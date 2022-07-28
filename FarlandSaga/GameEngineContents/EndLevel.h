#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class EndLevel : public GameEngineLevel
{
public:
	EndLevel();
	~EndLevel();

	EndLevel(const EndLevel& _Other) = delete;
	EndLevel(EndLevel&& _Other) noexcept = delete;
	EndLevel& operator=(const EndLevel& _Other) = delete;
	EndLevel& operator=(EndLevel&& _Other) noexcept = delete;
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:

};