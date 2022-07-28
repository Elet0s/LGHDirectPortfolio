#pragma once
#include <GameEngineCore/GameEngineLevel.h>
class Event02 : public GameEngineLevel
{
public:
	Event02();
	~Event02();


	Event02(const Event02& _Other) = delete;
	Event02(Event02&& _Other) noexcept = delete;
	Event02& operator=(const Event02& _Other) = delete;
	Event02& operator=(Event02&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
};