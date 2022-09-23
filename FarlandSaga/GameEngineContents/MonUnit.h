#pragma once
#include <GameEngineCore/GameEngineActor.h>
class MonUnit :public GameEngineActor
{
public:
	MonUnit();
	~MonUnit();

	MonUnit(const MonUnit& _Other) = delete;
	MonUnit(MonUnit&& _Other) noexcept = delete;
	MonUnit& operator=(const MonUnit& _Other) = delete;
	MonUnit& operator=(MonUnit&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End();

private:
};