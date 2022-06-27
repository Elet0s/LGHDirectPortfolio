#pragma once
class GameEngineDevice
{
public:
	GameEngineDevice();
	~GameEngineDevice();


	GameEngineDevice(const GameEngineDevice& _Other) = delete;
	GameEngineDevice(GameEngineDevice&& _Other) noexcept = delete;
	GameEngineDevice& operator=(const GameEngineDevice& _Other) = delete;
	GameEngineDevice& operator=(GameEngineDevice&& _Other) noexcept = delete;
protected:

private:

};