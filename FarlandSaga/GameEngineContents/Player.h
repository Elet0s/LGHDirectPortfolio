#pragma once
#include <GameEngineCore/CoreMinimal.h>

// ���� :
class GameEngineTextureRenderer;
class Player : public GameEngineActor
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void Test2Start(const FrameAnimation_DESC& _Info);

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}



	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:

	float Speed;
};

