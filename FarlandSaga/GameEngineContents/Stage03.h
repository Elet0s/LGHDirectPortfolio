#pragma once
#include <GameEngineCore/GameEngineLevel.h>
class Stage03 : public GameEngineLevel
{
public:
	Stage03();
	~Stage03();


	Stage03(const Stage03& _Other) = delete;
	Stage03(Stage03&& _Other) noexcept = delete;
	Stage03& operator=(const Stage03& _Other) = delete;
	Stage03& operator=(Stage03&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:


};