#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineTextureRenderer;
class TestStageBG : public GameEngineActor
{
public:
	TestStageBG();
	~TestStageBG();

	TestStageBG(const TestStageBG& _Other) = delete;
	TestStageBG(TestStageBG&& _Other) noexcept = delete;
	TestStageBG& operator=(const TestStageBG& _Other) = delete;
	TestStageBG& operator=(TestStageBG&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	GameEngineTextureRenderer* Renderer;

private:

	float TimeAngle;
};