#pragma once
#include "GameEngineComponent.h"
#include <GameEngineBase/GameEngineTransform.h>
#include <GameEngineCore/GameEngineActor.h>
#include "GameEngineTransformBase.h"

// ���� : ����ε� ������������ �������ϴ� ������Ʈ���� �̰� ��� �޴´�.
class GameEngineTransformComponent
	: public GameEngineComponent
	, public GameEngineTransformBase
{
public:
	GameEngineTransformComponent();
	~GameEngineTransformComponent();

	GameEngineTransformComponent(const GameEngineTransformComponent& _Other) = delete;
	GameEngineTransformComponent(GameEngineTransformComponent&& _Other) noexcept = delete;
	GameEngineTransformComponent& operator=(const GameEngineTransformComponent& _Other) = delete;
	GameEngineTransformComponent& operator=(GameEngineTransformComponent&& _Other) noexcept = delete;

	GameEngineActor* GetActor()
	{
		return GetParent<GameEngineActor>();
	}

	void DetachObject() override;

	void SetParent(GameEngineUpdateObject*) override;

protected:


private:
};
