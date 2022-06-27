#pragma once
class GameEngineTransformComponent
{
public:
	GameEngineTransformComponent();
	~GameEngineTransformComponent();


	GameEngineTransformComponent(const GameEngineTransformComponent& _Other) = delete;
	GameEngineTransformComponent(GameEngineTransformComponent&& _Other) noexcept = delete;
	GameEngineTransformComponent& operator=(const GameEngineTransformComponent& _Other) = delete;
	GameEngineTransformComponent& operator=(GameEngineTransformComponent&& _Other) noexcept = delete;
protected:

private:

};