#include "PreCompile.h"
#include "Player.h"
#include <iostream>
#include <GameEngineContents/GlobalContentsValue.h>

Player* Player::MainPlayer = nullptr;
Player::Player()
	: Speed(50.0f)
{
	MainPlayer = this;
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
	if (false == GameEngineInput::GetInst()->IsKey("PlayerLeftUP"))
	{
		GameEngineInput::GetInst()->CreateKey("PlayerLeftUP", 'W');
		GameEngineInput::GetInst()->CreateKey("PlayerLeftDown", 'A');
		GameEngineInput::GetInst()->CreateKey("PlayerRightUP", 'D');
		GameEngineInput::GetInst()->CreateKey("PlayerRightDown", 'S');
	}


	GetTransform().SetLocalScale({ 1, 1, 1 });

	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 384, 384, 1 });
		Renderer->CreateFrameAnimation("LeonWalkU", FrameAnimation_DESC("LeonWalkU.png", 0, 3, 0.1f));
		Renderer->CreateFrameAnimation("LeonWalkD", FrameAnimation_DESC("LeonWalkD.png", 0, 3, 0.1f));
		Renderer->CreateFrameAnimation("LeonIdle", FrameAnimation_DESC("LeonIdle.png", 0, 2, 0.1f));
		Renderer->ChangeFrameAnimation("LeonIdle");
		//Renderer->AnimationBindEnd("LeonWind", &Player::MyFunction, this);


		Renderer->SetPivot(PIVOTMODE::BOT);
	}

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 100.0f, 100.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Player);
	}

	{
	GameEngineFontRenderer* Font = CreateComponent<GameEngineFontRenderer>();
	Font->SetText("안녕하세요", "궁서");
	Font->SetColor({ 1.0f, 0.0f, 0.0f });
	Font->SetScreenPostion({ 100.0f, 100.0f });
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
	Renderer->ChangeFrameAnimation("LeonIdle");
}

void Player::IdleUpdate(float _DeltaTime, const StateInfo& _Info)
{
	if (true == GameEngineInput::GetInst()->IsPress("PlayerLeftUP") ||
		true == GameEngineInput::GetInst()->IsPress("PlayerLeftDown") ||
		true == GameEngineInput::GetInst()->IsPress("PlayerRightUP") ||
		true == GameEngineInput::GetInst()->IsPress("PlayerRightDown"))
	{
		StateManager.ChangeState("Move");
	}
}

void Player::MoveStart(const StateInfo& _Info)
{
	if (true == GameEngineInput::GetInst()->IsPress("PlayerLeftUP") ||
		true == GameEngineInput::GetInst()->IsPress("PlayerRightUp"))
	{
		Renderer->ChangeFrameAnimation("LeonWalkU");


		
	}
	else if (true == GameEngineInput::GetInst()->IsPress("PlayerLeftDown") ||
		true == GameEngineInput::GetInst()->IsPress("PlayerRightDown"))
	{
		Renderer->ChangeFrameAnimation("LeonWalkD");
	}
}

void Player::MoveUpdate(float _DeltaTime, const StateInfo& _Info)
{

	//if (_Info.StateTime >= 2.0f)
	//{
	//	StateManager.ChangeState("Idle");
	//	return;
	//}
	//

	if (false == GameEngineInput::GetInst()->IsPress("PlayerLeftUP") &&
		false == GameEngineInput::GetInst()->IsPress("PlayerLeftDown") &&
		false == GameEngineInput::GetInst()->IsPress("PlayerRightUP") &&
		false == GameEngineInput::GetInst()->IsPress("PlayerRightDown"))
	{
		StateManager.ChangeState("Idle");
		return;
	}

	if (true == GameEngineInput::GetInst()->IsPress("PlayerLeftUP"))
	{
		GetTransform().SetWorldMove(GetTransform().GetLeftVector() * Speed *2* _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetUpVector() * Speed * _DeltaTime);
		Renderer->GetTransform().PixLocalPositiveX();
		Renderer->GetColorData().MulColor.a -= _DeltaTime;
	}

	if (true == GameEngineInput::GetInst()->IsPress("PlayerLeftDown"))
	{
		GetTransform().SetWorldMove(GetTransform().GetLeftVector() * Speed * 2 * _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetDownVector() * Speed * _DeltaTime);
		Renderer->GetTransform().PixLocalPositiveX();
	}

	if (true == GameEngineInput::GetInst()->IsPress("PlayerRightUP"))
	{
		GetTransform().SetWorldMove(GetTransform().GetRightVector() * Speed * 2 * _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetUpVector() * Speed * _DeltaTime);
		Renderer->GetTransform().PixLocalNegativeX();
	}

	if (true == GameEngineInput::GetInst()->IsPress("PlayerRightDown"))
	{
		GetTransform().SetWorldMove(GetTransform().GetRightVector() * Speed * 2 * _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetDownVector() * Speed * _DeltaTime);
		Renderer->GetTransform().PixLocalNegativeX();
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