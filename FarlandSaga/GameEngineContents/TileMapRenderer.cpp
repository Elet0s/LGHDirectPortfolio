#include "PreCompile.h"
#include "TileMapRenderer.h"

TileMapRenderer::TileMapRenderer()
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

void TileMapRenderer::CreateIsometricTileMap(int _X, int _Y, float4 _TileScale, const std::string& _FolderTexture, int _DefualtIndex)
{
	TileTextures = GameEngineFolderTexture::Find(_FolderTexture);

	if (nullptr == TileTextures)
	{
		MsgBoxAssertString("존재하지 않는 폴더텍스처로 타일맵을 만들려고 했습니다" + _FolderTexture);
	}

	Tiles.resize(_Y);

	TileScale = _TileScale;
	TileScaleH = TileScale.Half();

	for (size_t y = 0; y < Tiles.size(); y++)
	{
		Tiles[y].resize(_X);

		for (size_t x = 0; x < Tiles[y].size(); x++)
		{
			Tiles[y][x].TileImage = TileTextures->GetTexture(_DefualtIndex);
		}
	}
}

void TileMapRenderer::Update(float _Delta)
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
			Pos.y = (x * -TileScaleH.y) + (y * -TileScaleH.y);
			Pos.z = Pos.y;

			TileTrans.SetLocalPosition(Pos);
			TileTrans.CalculateWorldViewProjection();
			ShaderResources.SetConstantBufferLink("TransformData", TileTrans.GetTransformData());
			ShaderResources.SetTexture("Tex", Tiles[y][x].TileImage);
			GameEngineDefaultRenderer::Render(_DeltaTime);
		}
	}
}