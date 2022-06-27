#pragma once
#include <GameEngineCore/GameEngineActor.h>

class TitleLogo : public GameEngineActor
{
public:
	TitleLogo();
	~TitleLogo();

	TitleLogo(const TitleLogo& _Other) = delete;
	TitleLogo(TitleLogo&& _Other) noexcept = delete;
	TitleLogo& operator=(const TitleLogo& _Other) = delete;
	TitleLogo& operator=(TitleLogo&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:

	float TimeAngle;
};

