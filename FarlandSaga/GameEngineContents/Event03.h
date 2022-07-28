#pragma once
#include <GameEngineCore/GameEngineLevel.h>
class Event03 : public GameEngineLevel
{
public:
	Event03();
	~Event03();


	Event03(const Event03& _Other) = delete;
	Event03(Event03&& _Other) noexcept = delete;
	Event03& operator=(const Event03& _Other) = delete;
	Event03& operator=(Event03&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
};