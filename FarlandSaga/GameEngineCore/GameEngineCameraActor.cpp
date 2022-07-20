#include "PreCompile.h"
#include "GameEngineCameraActor.h"
#include <GameEngineBase/GameEngineInput.h>

GameEngineCameraActor::GameEngineCameraActor()
	: CameraComponent(nullptr)
{
}

GameEngineCameraActor::~GameEngineCameraActor()
{
}

void GameEngineCameraActor::Start()
{
	CameraComponent = CreateComponent<GameEngineCamera>();

	if (false == GameEngineInput::GetInst()->IsKey("CamMoveForward"))
	{
		GameEngineInput::GetInst()->CreateKey("CamMoveForward", 'W');
		GameEngineInput::GetInst()->CreateKey("CamMoveBack", 'S');
		GameEngineInput::GetInst()->CreateKey("CamMoveUp", 'Q');
		GameEngineInput::GetInst()->CreateKey("CamMoveDown", 'E');
		GameEngineInput::GetInst()->CreateKey("CamMoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("CamMoveRight", 'D');

		GameEngineInput::GetInst()->CreateKey("CamMoveBoost", VK_LSHIFT);
		GameEngineInput::GetInst()->CreateKey("CamRot", VK_RBUTTON);
	}

}

void GameEngineCameraActor::Update(float _DeltaTime)
{
	if (false == FreeCameraMode)
	{
		return;
	}

	float MoveSpeed = Speed;

	if (GameEngineInput::GetInst()->IsPress("CamMoveBoost"))
	{
		MoveSpeed *= 3.0f;
	}
}

void GameEngineCameraActor::End()
{

}


void GameEngineCameraActor::FreeCameraModeOnOff()
{
	FreeCameraMode = !FreeCameraMode;
}