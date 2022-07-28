#pragma once
#include <GameEngineCore/GameEngineActor.h>

class UIMaster : public GameEngineActor
{
public:
	UIMaster();
	~UIMaster();

	UIMaster(const UIMaster& _Other) = delete;
	UIMaster(UIMaster&& _Other) noexcept = delete;
	UIMaster& operator=(const UIMaster& _Other) = delete;
	UIMaster& operator=(UIMaster&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

