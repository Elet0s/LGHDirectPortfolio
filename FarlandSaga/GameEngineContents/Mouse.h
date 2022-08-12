#pragma once
#include <GameEngineCore/GameEngineComponent.h>

class Mouse :public GameEngineComponent
{
public:
	Mouse();
	~Mouse();


	Mouse(const Mouse& _Other) = delete;
	Mouse(Mouse&& _Other) noexcept = delete;
	Mouse& operator=(const Mouse& _Other) = delete;
	Mouse& operator=(Mouse&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};