#include "PreCompile.h"
#include "TileMapRenderer.h"

TileMapRenderer::TileMapRenderer()
	:
	ShortIndex(0)
	, LongIndex(9)
	, TileX(0)
	, TileY(0)
	, TileZ(0)
	, RenderZ(0)
	, TileTextures(nullptr)
{
}

TileMapRenderer::~TileMapRenderer()
{
}

void TileMapRenderer::Start()
{
	SetPipeLine("TextureAtlas");

	FrameData.PosX = 0.0f;
	FrameData.PosY = 0.0f;
	FrameData.SizeX = 1.0f;
	FrameData.SizeY = 1.0f;

	ShaderResources.SetConstantBufferLink("AtlasData", FrameData);
	ShaderResources.SetConstantBufferLink("ColorData", ColorData);

	PushRendererToMainCamera();
}

void TileMapRenderer::GetTileIndex(float4 _Pos, int& _X, int& _Y)
{
	float fX = (_Pos.x / TileScaleH.x + _Pos.y / -TileScaleH.y) / 2.0f;
	float fY = (_Pos.y / -TileScaleH.y - _Pos.x / TileScaleH.x) / 2.0f;


	_X = static_cast<int>(roundf(fX));
	_Y = static_cast<int>(roundf(fY));

}

void TileMapRenderer::SetTileIndex(float4 _Pos, size_t _Index, int _ZChage)//텍스처 선택해서 누를때
{
	if (0 > _Index)
	{
		return;
	}

	if (TileTextures->GetTextureCount() <= _Index)
	{
		return;
	}
	if (0 > _ZChage)
	{
		return;
	}

	// _Pos
	int X = -1;
	int Y = -1;

	GetTileIndex(_Pos, X, Y);

	if (0 > X)
	{
		return;
	}

	if (TileX <= X)
	{
		return;
	}

	if (0 > Y)
	{
		return;
	}

	if (TileY <= Y)
	{
		return;
	}

	Tiles[Y][X].TileIndex = static_cast<int>(_Index);
	Tiles[Y][X].Z = _ZChage;
	if (_Index<9)
	{
		Tiles[Y][X].Ztile = TileTextures->GetTexture(_Index);
		ShortIndex = _Index;
	}
	else if (_Index < 15)
	{
		Tiles[Y][X].Ztile = TileTextures->GetTexture(_Index);
		LongIndex = _Index;
	}
	else
	{
		Tiles[Y][X].TileImage = TileTextures->GetTexture(_Index);
	}

}

void TileMapRenderer::CreateIsometricTileMap(int _X, int _Y, int _Z, float4 _TileScale, const std::string& _FolderTexture, int _DefualtIndex)
{
	TileTextures = GameEngineFolderTexture::Find(_FolderTexture);

	if (nullptr == TileTextures)
	{
		MsgBoxAssertString("존재하지 않는 폴더텍스처로 타일맵을 만들려고 했습니다" + _FolderTexture);
	}

	TileX = _X;
	TileY = _Y;
	TileZ = _Z;

	Tiles.resize(_Y);

	TileScale = _TileScale;
	TileScaleH = TileScale.Half();

	for (size_t y = 0; y < Tiles.size(); y++)
	{
		Tiles[y].resize(_X);

		for (size_t x = 0; x < Tiles[y].size(); x++)
		{
			Tiles[y][x].TileIndex = static_cast<int>(_DefualtIndex);
			Tiles[y][x].TileImage = TileTextures->GetTexture(_DefualtIndex);
			Tiles[y][x].TileDepth = (x + y)*2;
			if (_Z >5)
			{
				Tiles[y][x].Ztile = TileTextures->GetTexture(9);
			}
			else if (_Z >0)
			{
				Tiles[y][x].Ztile = TileTextures->GetTexture(0);
			}
			Tiles[y][x].Z = _Z;

		}
	}
}

void TileMapRenderer::Update(float _Delta)
{
	//if (true == Tiles[TileY][TileX].TileCol->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::TileMap, CollisionType::CT_OBB2D))
	//{
	//	Tiles[TileY][TileX].TileRender->SetTexture("TestStage.png");
	//}
}
void ZChange(int Scale)
{

}
void TileMapRenderer::Render(float _DeltaTime)
{
	static GameEngineTransform TileTrans;

	TileTrans.SetLocalScale(TileScale);
	TileTrans.SetView(GetTransform().GetTransformData().ViewMatrix);
	TileTrans.SetProjection(GetTransform().GetTransformData().ProjectionMatrix);

	for (size_t y = 0; y < Tiles.size(); y++)
	{
		for (size_t x = 0; x < Tiles[y].size(); x++)
		{
			float4 Pos = GetTransform().GetWorldPosition();

			Pos.x = (x * TileScaleH.x) + (y * -TileScaleH.x);
			Pos.y = (x * -TileScaleH.y) + (y * -TileScaleH.y) + (Tiles[y][x].Z * 16);
			// Z값과 order순서를 내가 편하게 사용하기 위해서 음수로 바꿔서 넣어줌
			Pos.z = -Tiles[y][x].TileDepth;

			if (Tiles[y][x].TileIndex > 60) //특수 타일
			{
				switch (Tiles[y][x].TileIndex)
				{
				case 61:
					Pos.y += 6;
					TileTrans.SetWorldScale(float4(64, 48));
					break;
				case 64:
					Pos.y += 11;
					TileTrans.SetWorldScale(float4(64, 55));
					break;
				default:
					Pos.y += 8;
					TileTrans.SetWorldScale(float4(64, 48));
					break;
				}
			}
			else
			{
				TileTrans.SetLocalScale(float4(64, 32));
			}
			TileTrans.SetLocalPosition(Pos);
			TileTrans.CalculateWorldViewProjection();
			ShaderResources.SetConstantBufferLink("TransformData", TileTrans.GetTransformData());
			ShaderResources.SetTexture("Tex", Tiles[y][x].TileImage);
			GameEngineDefaultRenderer::Render(_DeltaTime);

			///////////////////////////////////////////////////////////////////////////////////////

			if (x + 1 < TileX && y + 1 < TileY) // 가장자리 안쪽
			{
				if (Tiles[y][x].Z > Tiles[y + 1][x+1].Z) //내가 높다면
				{
					RenderZ = Tiles[y][x].Z - Tiles[y + 1][x + 1].Z+2; //차이만큼 그려라
				}
				else if (Tiles[y][x].Z < Tiles[y + 1][x + 1].Z)//앞 타일이 크면
				{
					RenderZ = 1;
				}
				else if (Tiles[y][x].Z = Tiles[y + 1][x + 1].Z) // 앞쪽 타일이같으면
				{
					if (Tiles[y][x].Z == 0) //바닥일경우
					{
						RenderZ = 0;
					}
					else
					{
						RenderZ = 2;
					}
				}

			}
			else if (x + 1 == TileX || y + 1 == TileY) // 타일 가장자리
			{
				RenderZ = Tiles[y][x].Z;
			}

			if (RenderZ > 5) //그려야할 타일이 5개이상이면
			{
				Pos.y -= 56;
				TileTrans.SetLocalScale(float4(64, 112));
				TileTrans.SetLocalPosition(Pos);
				TileTrans.CalculateWorldViewProjection();
				ShaderResources.SetConstantBufferLink("TransformData", TileTrans.GetTransformData());
				if (Tiles[y][x].Ztile == nullptr)
				{
					Tiles[y][x].Ztile = TileTextures->GetTexture(9);
				}
				ShaderResources.SetTexture("Tex", Tiles[y][x].Ztile);
				GameEngineDefaultRenderer::Render(_DeltaTime);

			}

			else if (RenderZ > 0)// 그려야할 타일이 5개이하면
			{
				for (size_t z = 1; z <= RenderZ; z++)
				{
					TileTrans.SetLocalScale(float4(64, 32));
					Pos.y -= 16;
					TileTrans.SetLocalPosition(Pos);
					TileTrans.CalculateWorldViewProjection();
					ShaderResources.SetConstantBufferLink("TransformData", TileTrans.GetTransformData());
					if (Tiles[y][x].Ztile == nullptr)
					{
						Tiles[y][x].Ztile = TileTextures->GetTexture(0);
					}
					ShaderResources.SetTexture("Tex", Tiles[y][x].Ztile);
					GameEngineDefaultRenderer::Render(_DeltaTime);
				}
			}
		}
	}
}

void TileMapRenderer::SetZIndex(int& _X, int& _Y, int& _Z)
{
	if (_X>=0&& TileX>_X)
	{
		if (_Y>=0&&TileY > _Y)
		{
			float fZ = Tiles[_Y][_X].Z;
			_Z = static_cast<int>(roundf(fZ));
		}
	}
}