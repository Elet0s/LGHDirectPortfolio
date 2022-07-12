#pragma once
#include <GameEngineCore/CoreMinimal.h>

class GameEngineDefaultRenderer;
class Player : public GameEngineActor
{
public:
	Player();
	~Player();

	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineDefaultRenderer* Renderer;

	float4 Color;

private:
	float Speed;
};

