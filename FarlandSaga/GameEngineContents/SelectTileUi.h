#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineTextureRenderer;
class SelectTileUi : public GameEngineActor
{
public:

	SelectTileUi();
	~SelectTileUi();


	SelectTileUi(const SelectTileUi& _Other) = delete;
	SelectTileUi(SelectTileUi&& _Other) noexcept = delete;
	SelectTileUi& operator=(const SelectTileUi& _Other) = delete;
	SelectTileUi& operator=(SelectTileUi&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	GameEngineTextureRenderer* Renderer;
private:
};