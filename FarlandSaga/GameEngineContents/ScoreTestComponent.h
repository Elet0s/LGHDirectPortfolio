#pragma once
#include <GameEngineCore/GameEngineComponent.h>

class ScoreTestComponent : public GameEngineComponent
{
public:
	ScoreTestComponent();
	~ScoreTestComponent();

	ScoreTestComponent(const ScoreTestComponent& _Other) = delete;
	ScoreTestComponent(ScoreTestComponent&& _Other) noexcept = delete;
	ScoreTestComponent& operator=(const ScoreTestComponent& _Other) = delete;
	ScoreTestComponent& operator=(ScoreTestComponent&& _Other) noexcept = delete;

protected:

private:

};

