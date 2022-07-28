#include "PreCompile.h"
#include "Player.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineContents/GlobalContentsValue.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineRenderingPipeLine.h>
#include <GameEngineCore/GameEngineVertexShader.h>
#include <GameEngineCore/GameEngineConstantBuffer.h>
#include <GameEngineCore/GameEngineDevice.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>


Player::Player()
	: Speed(50.0f)
{
	

}

Player::~Player()
{
}

void Player::Test2End(const FrameAnimation_DESC& _Info)
{

	GameEngineDebug::OutPutString("스타트\n");
	//Renderer->ChangeFrameAnimation("Test1");
}

void Player::Test1End(const FrameAnimation_DESC& _Info)
{

	GameEngineDebug::OutPutString("앤드\n");
	//Renderer->ChangeFrameAnimation("Test2");

}

void Test2Frame(const FrameAnimation_DESC& _Info)
{
	// GameEngineDebug::OutPutString("프레임\n");
}

void Test2Time(const FrameAnimation_DESC& _Info, float _Time)
{
	// GameEngineDebug::OutPutString("타임\n");
}

void Player::MyFunction(const FrameAnimation_DESC& _Info)
{
	GameEngineDebug::OutPutString("중단점\n");
}

void Player::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("PlayerLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("PlayerLeft", 'L');
		GameEngineInput::GetInst()->CreateKey("PlayerRight", 'K');
		GameEngineInput::GetInst()->CreateKey("PlayerUp", VK_NUMPAD9);
		GameEngineInput::GetInst()->CreateKey("PlayerDown", VK_NUMPAD7);
	}


	GetTransform().SetLocalScale({ 1, 1, 1 });

	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 81, 81, 81 });
		Renderer->CreateFrameAnimation("LeonWind2", FrameAnimation_DESC("LeonWind.png", 0, 2, 0.1f));
		Renderer->CreateFrameAnimation("LeonWind", FrameAnimation_DESC("LeonWind.png", 0, 2, 0.1f));
		Renderer->ChangeFrameAnimation("LeonWind2");
		//Renderer->AnimationBindEnd("LeonWind", &Player::MyFunction, this);

		//Renderer->ScaleToTexture();
		Renderer->SetPivot(PIVOTMODE::BOT);
	}

	// 무기명 함수를 만들수 있습니다.
	// 이름없는 인스턴스 함수를 만들수가 있습니다.
	// [](const StateInfo& _Info) 
	//{
	//} 람다를 만들겠다 

	StateManager.CreateStateMember("Idle", this, &Player::IdleUpdate, &Player::IdleStart);
	StateManager.CreateStateMember("Move", this, &Player::MoveUpdate, &Player::MoveStart);
	StateManager.ChangeState("Idle");
}

void Player::IdleStart(const StateInfo& _Info)
{
	Renderer->ChangeFrameAnimation("LeonWind");
}

void Player::IdleUpdate(float _DeltaTime, const StateInfo& _Info)
{
	if (true == GameEngineInput::GetInst()->IsPress("PlayerLeft") ||
		true == GameEngineInput::GetInst()->IsPress("PlayerRight") ||
		true == GameEngineInput::GetInst()->IsPress("PlayerUp") ||
		true == GameEngineInput::GetInst()->IsPress("PlayerDown"))
	{
		StateManager.ChangeState("Move");
	}
}

void Player::MoveStart(const StateInfo& _Info)
{
	Renderer->ChangeFrameAnimation("LeonWind2");
}

void Player::MoveUpdate(float _DeltaTime, const StateInfo& _Info)
{

	//if (_Info.StateTime >= 2.0f)
	//{
	//	StateManager.ChangeState("Idle");
	//	return;
	//}
	//

	if (false == GameEngineInput::GetInst()->IsPress("PlayerLeft") &&
		false == GameEngineInput::GetInst()->IsPress("PlayerRight") &&
		false == GameEngineInput::GetInst()->IsPress("PlayerUp") &&
		false == GameEngineInput::GetInst()->IsPress("PlayerDown"))
	{
		StateManager.ChangeState("Idle");
		return;
	}

	if (true == GameEngineInput::GetInst()->IsPress("PlayerLeft"))
	{
		GetTransform().SetWorldMove(GetTransform().GetLeftVector() * Speed * _DeltaTime);
		Renderer->GetTransform().PixLocalNegativeX();
	}

	if (true == GameEngineInput::GetInst()->IsPress("PlayerRight"))
	{
		GetTransform().SetWorldMove(GetTransform().GetRightVector() * Speed * _DeltaTime);
		Renderer->GetTransform().PixLocalPositiveX();
	}

	if (true == GameEngineInput::GetInst()->IsPress("PlayerUp"))
	{
		GetTransform().SetWorldMove(GetTransform().GetUpVector() * Speed * _DeltaTime);
	}

	if (true == GameEngineInput::GetInst()->IsPress("PlayerDown"))
	{
		GetTransform().SetWorldMove(GetTransform().GetDownVector() * Speed * _DeltaTime);
	}

	//GetLevel()->GetMainCameraActorTransform().SetLocalPosition(GetTransform().GetLocalPosition() + float4::BACK * 100.0f);
}

void Player::Update(float _DeltaTime)
{
	if (true == GetLevel()->GetMainCameraActor()->IsFreeCameraMode())
	{
		return;
	}

	StateManager.Update(_DeltaTime);

	//Renderer->AnimationBindEnd("Test2", std::bind(&Player::Test2End, this, std::placeholders::_1));
	//Renderer->AnimationBindEnd("Test1", std::bind(&Player::Test2End, this, std::placeholders::_1));
}