#pragma once
#include <GameEngineCore/GameEngineLevel.h>
class Event01 : public GameEngineLevel
{
public:
	Event01();
	~Event01();

	Event01(const Event01& _Other) = delete;
	Event01(Event01&& _Other) noexcept = delete;
	Event01& operator=(const Event01& _Other) = delete;
	Event01& operator=(Event01&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
};