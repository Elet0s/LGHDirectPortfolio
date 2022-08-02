#pragma once
#include <GameEngineCore/CoreMinimal.h>

class GameEngineTextureRenderer;
class Player : public GameEngineActor
{
private:
	static Player* MainPlayer;

public:
	static Player* GetMainPlayer()
	{
		return MainPlayer;
	}
public:
	Player();
	~Player();

	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void Test2End(const FrameAnimation_DESC& _Info);
	void Test1End(const FrameAnimation_DESC& _Info);
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}



	GameEngineTextureRenderer* Renderer;
	GameEngineCollision* Collision;

	float4 Color;

	void MyFunction(const FrameAnimation_DESC& _Info);


	void IdleStart(const StateInfo& _Info);
	void IdleUpdate(float _DeltaTime, const StateInfo& _Info);

	void MoveStart(const StateInfo& _Info);
	void MoveUpdate(float _DeltaTime, const StateInfo& _Info);

private:

	float Speed;

	GameEngineStateManager StateManager;
};

