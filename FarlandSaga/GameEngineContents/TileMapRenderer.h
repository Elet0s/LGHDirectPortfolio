#pragma once
#include <GameEngineCore/GameEngineDefaultRenderer.h>


class Tile
{

};

// 타일의 정보

// 설명 :
class TileMapRenderer : public GameEngineDefaultRenderer
{
public:
	// constrcuter destructer
	TileMapRenderer();
	~TileMapRenderer();

	// delete Function
	TileMapRenderer(const TileMapRenderer& _Other) = delete;
	TileMapRenderer(TileMapRenderer&& _Other) noexcept = delete;
	TileMapRenderer& operator=(const TileMapRenderer& _Other) = delete;
	TileMapRenderer& operator=(TileMapRenderer&& _Other) noexcept = delete;

	void CreateIsometricTileMap(int _X, int _Y, const std::string& _FolderTexture);

protected:

private:
	void Start() override;

	void Update(float _Delta) override;

	std::vector<std::vector<Tile>> Tiles;
	float4 FrameData;
	ColorData ColorData;
};

