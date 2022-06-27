#pragma once
#include <GameEngineBase/GameEngineTransform.h>

class GameEngineCollision
{
public:
	// static bool SphereToSphere(const GameEngineTransform&);

	GameEngineCollision();
	~GameEngineCollision();

	GameEngineCollision(const GameEngineCollision& _Other) = delete;
	GameEngineCollision(GameEngineCollision&& _Other) noexcept = delete;
	GameEngineCollision& operator=(const GameEngineCollision& _Other) = delete;
	GameEngineCollision& operator=(GameEngineCollision&& _Other) noexcept = delete;
protected:

private:

};