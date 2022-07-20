#pragma once
#include "GameEngineActor.h"
#include "GameEngineCamera.h"

class GameEngineLevel;
class GameEngineCameraActor : public GameEngineActor
{

public:
	GameEngineCameraActor();
	~GameEngineCameraActor();

	GameEngineCameraActor(const GameEngineCameraActor& _Other) = delete;
	GameEngineCameraActor(GameEngineCameraActor&& _Other) noexcept = delete;
	GameEngineCameraActor& operator=(const GameEngineCameraActor& _Other) = delete;
	GameEngineCameraActor& operator=(GameEngineCameraActor&& _Other) noexcept = delete;

	GameEngineCamera* GetCameraComponent()
	{
		return CameraComponent;
	}

	void FreeCameraModeOnOff();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	bool FreeCameraMode;
	float Speed;

	GameEngineCamera* CameraComponent;

};

