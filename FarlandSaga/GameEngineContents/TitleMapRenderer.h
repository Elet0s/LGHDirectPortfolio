#pragma once
#include <GameEngineCore/GameEngineDefaultRenderer.h>

class Tile
{

};

class TitleMapRenderer : public GameEngineDefaultRenderer
{
public:
	TitleMapRenderer();
	~TitleMapRenderer();


	TitleMapRenderer(const TitleMapRenderer& _Other) = delete;
	TitleMapRenderer(TitleMapRenderer&& _Other) noexcept = delete;
	TitleMapRenderer& operator=(const TitleMapRenderer& _Other) = delete;
	TitleMapRenderer& operator=(TitleMapRenderer&& _Other) noexcept = delete;
protected:
	std::vector<std::vector<Tile>> Tiles;
private:

};