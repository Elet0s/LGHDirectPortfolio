#pragma once
class GameEngineCameraActor
{
public:
	GameEngineCameraActor();
	~GameEngineCameraActor();


	GameEngineCameraActor(const GameEngineCameraActor& _Other) = delete;
	GameEngineCameraActor(GameEngineCameraActor&& _Other) noexcept = delete;
	GameEngineCameraActor& operator=(const GameEngineCameraActor& _Other) = delete;
	GameEngineCameraActor& operator=(GameEngineCameraActor&& _Other) noexcept = delete;
protected:

private:

};