#pragma once
#include <GameEngineCore/GameEngineDefaultRenderer.h>

struct Atlas2Data
{
public:
	float4 FrameData;
	float4 PivotPos;
};

class Tile
{
public:
	int TileIndex; //�� Ÿ���� �ε�����ȣ
	int Zindex;
	int Z;//�̸�Ʈ���� ���� z��(����)
	int TileDepth; //ī�޶���� z��(����)


	GameEngineTexture* TileImage;
	GameEngineTexture* Ztile;
	GameEngineTexture* MapObject;


};

// Ÿ���� ����

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

	void SetZIndex(int& _X, int& _Y, int& _Z, int& _Index);
	void LoadTileIndex(int _x, int _y, int _Index, int _Z);

		std::vector<std::vector<Tile>> Tiles;
		void Load(std::string _Stage);


protected:
	void Render(float _DeltaTime) override;

private:
	void Start() override;
	void Update(float _Delta) override;


	int TileX;
	int TileY;
	int TileZ;
	int RenderZ;
	size_t ShortIndex;
	size_t LongIndex;

	GameEngineFolderTexture* TileTextures;

	float4 TileScale;
	float4 TileScaleH;

	Atlas2Data AtlasDatainst;
	PixelData PixelData;
};

