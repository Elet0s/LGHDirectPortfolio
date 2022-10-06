#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineTextureRenderer;
class TitleMainUi : public GameEngineActor
{
public:
	TitleMainUi();
	~TitleMainUi();

	TitleMainUi(const TitleMainUi& _Other) = delete;
	TitleMainUi(TitleMainUi&& _Other) noexcept = delete;
	TitleMainUi& operator=(const TitleMainUi& _Other) = delete;
	TitleMainUi& operator=(TitleMainUi&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	GameEngineTextureRenderer* Renderer;
	GameEngineTextureRenderer* StartButton;
	GameEngineTextureRenderer* EnterButton;
	GameEngineTextureRenderer* CacelButton;

	GameEngineCollision* StartCol;
	GameEngineCollision* EnterCol;
	GameEngineCollision* CacelCol;

private:
};