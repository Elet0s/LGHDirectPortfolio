#include "PreCompile.h"
#include "TileMapRenderer.h"

TileMapRenderer::TileMapRenderer()
	:
	ShortIndex(0)
	, LongIndex(9)
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

void TileMapRenderer::SetTileIndex(float4 _Pos, size_t _Index, int _ZChage)//�ؽ�ó �����ؼ� ������
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
		MsgBoxAssertString("�������� �ʴ� �����ؽ�ó�� Ÿ�ϸ��� ������� �߽��ϴ�" + _FolderTexture);
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
			Tiles[y][x].Front = (x + y)*2;
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
	// DebugTrans.CalculateWorldViewProjection();

	for (size_t y = 0; y < Tiles.size(); y++)
	{
		for (size_t x = 0; x < Tiles[y].size(); x++)
		{
			float4 Pos = GetTransform().GetWorldPosition();
			// Pos.x += TileScale.x * x;
			// Pos.y += -TileScale.y * y;

			Pos.x = (x * TileScaleH.x) + (y * -TileScaleH.x);
			Pos.y = (x * -TileScaleH.y) + (y * -TileScaleH.y) + (Tiles[y][x].Z * 16);
			Pos.z = -Tiles[y][x].Front;
			// Z���� order������ ���� ���ϰ� ����ϱ� ���ؼ� ������ �ٲ㼭 �־���
			TileTrans.SetLocalScale(float4(64, 32));
			TileTrans.SetLocalPosition(Pos);
			TileTrans.CalculateWorldViewProjection();
			ShaderResources.SetConstantBufferLink("TransformData", TileTrans.GetTransformData());
			ShaderResources.SetTexture("Tex", Tiles[y][x].TileImage);
			GameEngineDefaultRenderer::Render(_DeltaTime);
			if (x+1 < TileX && y + 1 < TileY) // ���� Ÿ���� ����
			{
				if (Tiles[y][x].Z > Tiles[y + 1][x + 1].Z) //���� Ÿ���� �� ũ��
				{
					RenderZ = Tiles[y][x].Z - Tiles[y + 1][x + 1].Z +2;
				}
				else if (Tiles[y][x].Z <= Tiles[y + 1][x + 1].Z) // ���� Ÿ���� �� ũ�ų� ������
				{
					RenderZ = 2;
				}
			}
			else if (x+1 == TileX || y+1 == TileY) // ���� Ÿ���� ����
			{
				RenderZ = Tiles[y][x].Z;
			}

			if (RenderZ > 5) //�׷����� Ÿ���� 5���̻��̸�
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

			else if (RenderZ > 0)// �׷����� Ÿ���� 5�����ϸ�
			{
				for (size_t z = 1; z <= RenderZ; z++)
				{
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