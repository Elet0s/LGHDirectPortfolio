#pragma once
#include <GameEngineCore/GameEngineLevel.h>
class Stage02 : public GameEngineLevel
{
public:
	Stage02();
	~Stage02();


	Stage02(const Stage02& _Other) = delete;
	Stage02(Stage02&& _Other) noexcept = delete;
	Stage02& operator=(const Stage02& _Other) = delete;
	Stage02& operator=(Stage02&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
};