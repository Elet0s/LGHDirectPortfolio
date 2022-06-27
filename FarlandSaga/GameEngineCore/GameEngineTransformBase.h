#pragma once
class GameEngineTransformBase
{
public:
	GameEngineTransformBase();
	~GameEngineTransformBase();


	GameEngineTransformBase(const GameEngineTransformBase& _Other) = delete;
	GameEngineTransformBase(GameEngineTransformBase&& _Other) noexcept = delete;
	GameEngineTransformBase& operator=(const GameEngineTransformBase& _Other) = delete;
	GameEngineTransformBase& operator=(GameEngineTransformBase&& _Other) noexcept = delete;
protected:

private:

};