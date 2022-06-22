#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Monster :public GameEngineActor
{
protected: 
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

	Monster();
	~Monster();

	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;
};