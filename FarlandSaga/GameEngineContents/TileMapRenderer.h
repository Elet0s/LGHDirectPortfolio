#pragma once
#include <GameEngineCore/GameEngineDefaultRenderer.h>


class Tile
{
public:
	int TileIndex;
	int Z;
	int Front;
	GameEngineTexture* TileImage;
	GameEngineCollision* TileCol;
	GameEngineTexture* Ztile;
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
	void CreateIsometricTileMap(int _X, int _Y, int _Z, float4 _TileScale, const std::string& _FolderTexture, int _DefualtIndex = 0);
	void SetTileIndex(float4 _Pos, size_t _Index, int _ZChage);

	void GetTileIndex(float4 _Pos, int& _X, int& _Y);

	void SetZIndex(int& _X, int& _Y, int& _Z);

protected:
	void Render(float _DeltaTime) override;

private:
	void Start() override;
	void Update(float _Delta) override;


	int TileX;
	int TileY;
	int TileZ;

	GameEngineFolderTexture* TileTextures;

	float4 TileScale;
	float4 TileScaleH;
	std::vector<std::vector<Tile>> Tiles;
	float4 FrameData;
	ColorData ColorData;
};

