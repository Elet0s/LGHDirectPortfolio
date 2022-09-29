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

	AtlasDatainst.FrameData.PosX = 0.0f;
	AtlasDatainst.FrameData.PosY = 0.0f;
	AtlasDatainst.FrameData.SizeX = 1.0f;
	AtlasDatainst.FrameData.SizeY = 1.0f;
	AtlasDatainst.PivotPos = float4::ZERO;
	
	ShaderResources.SetConstantBufferLink("AtlasData", AtlasDatainst);
	ShaderResources.SetConstantBufferLink("PixelData", PixelData);

	PushRendererToMainCamera();
}

void TileMapRenderer::GetTileIndex(float4 _Pos, int& _X, int& _Y)
{
	float fX = (_Pos.x / TileScaleH.x + _Pos.y / -TileScaleH.y) / 2.0f;
	float fY = (_Pos.y / -TileScaleH.y - _Pos.x / TileScaleH.x) / 2.0f;


	_X = static_cast<int>(roundf(fX));
	_Y = static_cast<int>(roundf(fY));

}
void TileMapRenderer::LoadTileIndex(int _y, int _x, int _Index, int _Z, int _Zindex)
{
	if (0 > _Index)
	{
		return;
	}
	if (TileTextures->GetTextureCount() <= _Index)
	{
		return;
	}

	if (0 > _Zindex)
	{
		return;
	}
	if (TileTextures->GetTextureCount() <= _Zindex)
	{
		return;
	}
	if (0 > _Z)
	{
		return;
	}
	int X = _x;
	int Y = _y;
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
	Tiles[Y][X].Z = _Z;
	Tiles[Y][X].Zindex = _Zindex;
	if (_Zindex < 9)
	{
		Tiles[Y][X].Ztile = TileTextures->GetTexture(_Zindex);
		ShortIndex = _Zindex;
	}
	else if (_Zindex >= 9)
	{
		Tiles[Y][X].Ztile = TileTextures->GetTexture(_Zindex);
		LongIndex = _Zindex;
	}
	if (_Index >= 15)
	{
		Tiles[Y][X].TileImage = TileTextures->GetTexture(_Index);
	}
}

void TileMapRenderer::SetTileIndex(float4 _Pos, size_t _Index, int _Z, int _Zindex)//텍스처 선택해서 누를때
{
	if (0 > _Index)
	{
		return;
	}

	if (TileTextures->GetTextureCount() <= _Index)
	{
		return;
	}

	if (0 > _Zindex)
	{
		return;
	}
	if (TileTextures->GetTextureCount() <= _Zindex)
	{
		return;
	}

	if (0 > _Z)
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
	Tiles[Y][X].Z = _Z;
	Tiles[Y][X].Zindex = _Zindex;
	if (_Zindex < 9)
	{
		Tiles[Y][X].Ztile = TileTextures->GetTexture(_Zindex);
		ShortIndex = _Zindex;
	}
	else if (_Zindex >= 9)
	{
		Tiles[Y][X].Ztile = TileTextures->GetTexture(_Zindex);
		LongIndex = _Zindex;
	}
	if (_Index >= 15)
	{
		Tiles[Y][X].TileImage = TileTextures->GetTexture(_Index);
	}

}


void TileMapRenderer::Load(std::string _Stage) //이미 만들어진 타일맵Data불러오기
{

	GameEngineDirectory Dir;
	Dir.MoveParentToExitsChildDirectory("ConstantResources");
	Dir.Move("ConstantResources");
	Dir.Move("Data");

	GameEngineFile LoadFile = (Dir.GetFullPath() + "\\" + _Stage + ".MapData").c_str();
	LoadFile.Open(OpenMode::Read, FileMode::Binary);

	int Size = 0;
	LoadFile.Read(&Size, sizeof(int), sizeof(int));

	for (size_t y = 0; y < Size; y++)
	{
		int XSize = 0;
		LoadFile.Read(&XSize, sizeof(int), sizeof(int));

		for (size_t x = 0; x < XSize; x++)
		{
			int Tileindex =0;
			LoadFile.Read(&Tileindex, sizeof(int), sizeof(int));
			Tiles[y][x].TileIndex = Tileindex;

			int TileZ = 0;
			LoadFile.Read(&TileZ, sizeof(int), sizeof(int));
			Tiles[y][x].Z = TileZ;

			int TileZindex = 0;
			LoadFile.Read(&TileZindex, sizeof(int), sizeof(int));
			Tiles[y][x].Zindex = TileZindex;

			LoadTileIndex(static_cast<int>(y), static_cast<int>(x), Tileindex, TileZ, TileZindex);

			//     int TileDepth = TileMap->TileRenderer->Tiles[y][x].TileDepth;
			//     LoadFile.Read(&Tileindex, sizeof(int), sizeof(int));
			//     TileMap->TileRenderer->Tiles[y][x].TileDepth = TileDepth;

		}

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
			Tiles[y][x].TileDepth = static_cast<int>((x + y)*2);
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
			float4 Pos;// = GetTransform().GetWorldPosition();
			if (Tiles[y][x].Z != 0)
			{
				Pos.x = (x * TileScaleH.x) + (y * -TileScaleH.x);
				Pos.y = (x * -TileScaleH.y) + (y * -TileScaleH.y) + (Tiles[y][x].Z * 16);
				// Z값과 order순서를 내가 편하게 사용하기 위해서 음수로 바꿔서 넣어줌
				Pos.z = static_cast<float>(-Tiles[y][x].TileDepth);

				if (Tiles[y][x].TileIndex > 60) //특수 타일
				{
					switch (Tiles[y][x].TileIndex)
					{
					case 61:
						Pos.y += 6;
						Pos.y -= 16;
						TileTrans.SetWorldScale(float4(64, 48));
						break;
					case 64:
						Pos.y += 11;
						Pos.y -= 1616;
						TileTrans.SetWorldScale(float4(64, 55));
						break;
					default:
						Pos.y += 8;
						Pos.y -= 16;
						TileTrans.SetWorldScale(float4(64, 48));
						break;
					}
				}
				else
				{
					TileTrans.SetLocalScale(float4(64, 32));
					Pos.y -= 16;
				}
				TileTrans.SetLocalPosition(Pos);
				TileTrans.CalculateWorldViewProjection();
				ShaderResources.SetConstantBufferLink("TransformData", TileTrans.GetTransformData());
				ShaderResources.SetTexture("Tex", Tiles[y][x].TileImage);
				GameEngineDefaultRenderer::Render(_DeltaTime);

				///////////////////////////////////////////////////////////////////////////////////////

				if (x + 1 < TileX && y + 1 < TileY) //내가 고른타일이 만들어진 타일 범위 안에 있다면
				{
					if (Tiles[y][x].Z > Tiles[y + 1][x + 1].Z) //앞 타일이 낮음
					{
						RenderZ = Tiles[y][x].Z - Tiles[y + 1][x + 1].Z + 2;
					}
					else if (Tiles[y][x].Z < Tiles[y + 1][x + 1].Z)//앞 타일이 높음
					{
						RenderZ = 0;
					}
					else if (Tiles[y][x].Z == Tiles[y + 1][x + 1].Z) //같을때
					{
						if (Tiles[y][x].Z > Tiles[y + 1][x].Z || Tiles[y][x].Z > Tiles[y][x + 1].Z)
						{
							RenderZ = 2;
						}
						else
						{
							RenderZ = 0;
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
						if (Tiles[y][x].TileIndex > 60) //특수 타일
						{
							switch (Tiles[y][x].TileIndex)
							{
							case 61:
								Pos.y -= 6;

								break;
							case 64:
								Pos.y -= 11;

								break;
							default:
								Pos.y -= 8;
								break;
							}
						}
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
}

void TileMapRenderer::SetZIndex(int& _X, int& _Y, int& _Z,int& _Index)
{
	if (_X>=0&& TileX>_X)
	{
		if (_Y>=0&&TileY > _Y)
		{
			float fZ = static_cast<float>(Tiles[_Y][_X].Z);
			float fTileIndex = static_cast<float>(Tiles[_Y][_X].TileIndex);
			_Z = static_cast<int>(roundf(fZ));
			_Index = static_cast<int>(fTileIndex);
		}
	}
}