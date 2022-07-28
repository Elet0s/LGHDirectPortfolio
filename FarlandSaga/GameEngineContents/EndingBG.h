#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineTextureRenderer;
class EndingBG : public GameEngineActor
{
public:
	EndingBG();
	~EndingBG();


	EndingBG(const EndingBG& _Other) = delete;
	EndingBG(EndingBG&& _Other) noexcept = delete;
	EndingBG& operator=(const EndingBG& _Other) = delete;
	EndingBG& operator=(EndingBG&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	GameEngineTextureRenderer* Renderer;

private:

};