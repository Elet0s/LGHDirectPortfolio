#pragma once
#include <GameEngineCore/GameEngineDefaultRenderer.h>


class Tile
{
public:
	GameEngineTexture* TileImage;
};

// 타일의 정보

class TileMapRenderer : public GameEngineDefaultRenderer
{
public:
	TileMapRenderer();
	~TileMapRenderer();

	TileMapRenderer(const TileMapRenderer& _Other) = delete;
	TileMapRenderer(TileMapRenderer&& _Other) noexcept = delete;
	TileMapRenderer& operator=(const TileMapRenderer& _Other) = delete;
	TileMapRenderer& operator=(TileMapRenderer&& _Other) noexcept = delete;

	// CreateTileMap(Scale[0], Scale[1], SelectFolderTexture);
	void CreateIsometricTileMap(int _X, int _Y, float4 _TileScale, const std::string& _FolderTexture, int _DefualtIndex = 0);

protected:
	void Render(float _DeltaTime) override;

private:
	void Start() override;

	void Update(float _Delta) override;


	GameEngineFolderTexture* TileTextures;

	float4 TileScale;
	float4 TileScaleH;
	std::vector<std::vector<Tile>> Tiles;
	float4 FrameData;
	ColorData ColorData;
};

