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

	GameEngineDebug::OutPutString("��ŸƮ\n");
	//Renderer->ChangeFrameAnimation("Test1");
}

void Player::Test1End(const FrameAnimation_DESC& _Info)
{

	GameEngineDebug::OutPutString("�ص�\n");
	//Renderer->ChangeFrameAnimation("Test2");

}

void Test2Frame(const FrameAnimation_DESC& _Info)
{
	// GameEngineDebug::OutPutString("������\n");
}

void Test2Time(const FrameAnimation_DESC& _Info, float _Time)
{
	// GameEngineDebug::OutPutString("Ÿ��\n");
}

void Player::MyFunction(const FrameAnimation_DESC& _Info)
{
	GameEngineDebug::OutPutString("�ߴ���\n");
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
		Renderer->GetTransform().SetLocalScale({ 250,250, 1 });
		Renderer->CreateFrameAnimationCutTexture("LeonWalkU", FrameAnimation_DESC("LeonWalkU.png", 0, 3, 0.2f));
		Renderer->CreateFrameAnimationCutTexture("LeonWalkD", FrameAnimation_DESC("LeonWalkD.png", 0, 3, 0.2f));
		Renderer->CreateFrameAnimationCutTexture("LeonIdle", FrameAnimation_DESC("LeonIdle.png", 0, 2, 0.2f));
		Renderer->ChangeFrameAnimation("LeonIdle");
		//Renderer->AnimationBindEnd("LeonWind", &Player::MyFunction, this);


		//Renderer->SetPivot(PIVOTMODE::BOT);
	}

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 100.0f, 100.0f, 100.0f });
		Collision->ChangeOrder(OBJECTORDER::Player);
	}

	// ����� �Լ��� ����� �ֽ��ϴ�.
	// �̸����� �ν��Ͻ� �Լ��� ������� �ֽ��ϴ�.
	// [](const StateInfo& _Info) 
	//{
	//} ���ٸ� ����ڴ� 

	StateManager.CreateStateMember("Idle"
		, std::bind(&Player::IdleUpdate, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Player::IdleStart, this, std::placeholders::_1)
	);

	int MyValue = 10;

	StateManager.CreateStateMember("Move"
		, std::bind(&Player::MoveUpdate, this, std::placeholders::_1, std::placeholders::_2)
		, [/*&*/=](const StateInfo& _Info)
		{
			// static const int MyValue = �ٱ� MyValue;

			int Test = MyValue;
			// = ���������� �����ִ�.
			// MyValue�� �ϳ��� ����� ������� �����Ϸ��� �ؼ��Ѵ�.
			// ????????
			// & �ܺ��� �ִ� ���� �������� �޾ƿ��� ���̱� ������
			// ���������� ���� ����� ����Ҽ��� ����.
			if (true == GameEngineInput::GetInst()->IsDown("PlayerLeftUP") ||
				true == GameEngineInput::GetInst()->IsDown("PlayerRightUp"))
			{
				Renderer->ChangeFrameAnimation("LeonWalkU");
			}
			else if (true == GameEngineInput::GetInst()->IsDown("PlayerLeftDown") ||
				true == GameEngineInput::GetInst()->IsDown("PlayerRightDown"))
			{
				Renderer->ChangeFrameAnimation("LeonWalkD");
			}

		});
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

void Player::MoveUpdate(float _DeltaTime, const StateInfo& _Info)
{

	//if (_Info.StateTime >= 2.0f)
	//{
	//	StateManager.ChangeState("Idle");
	//	return;
	//}
	//
	// GameEngineDebug::DebugSphereRender();
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
		GetTransform().SetWorldMove(GetTransform().GetLeftVector() * Speed * 2 * _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetUpVector() * Speed * _DeltaTime);
		Renderer->GetTransform().PixLocalPositiveX();
		//Renderer->GetColorData().MulColor.a -= _DeltaTime;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("PlayerLeftDown"))
	{
		GetTransform().SetWorldMove(GetTransform().GetLeftVector() * Speed * 2 * _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetDownVector() * Speed * _DeltaTime);
		Renderer->GetTransform().PixLocalPositiveX();
	}

	else if (true == GameEngineInput::GetInst()->IsPress("PlayerRightUP"))
	{
		GetTransform().SetWorldMove(GetTransform().GetRightVector() * Speed * 2 * _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetUpVector() * Speed * _DeltaTime);
		Renderer->GetTransform().PixLocalNegativeX();
	}
	else if (true == GameEngineInput::GetInst()->IsPress("PlayerRightDown"))
	{
		GetTransform().SetWorldMove(GetTransform().GetRightVector() * Speed * 2 * _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetDownVector() * Speed * _DeltaTime);
		Renderer->GetTransform().PixLocalNegativeX();
	}

	//GetLevel()->GetMainCameraActorTransform().SetLocalPosition(GetTransform().GetLocalPosition() + float4::BACK * 100.0f);
}

void Player::Update(float _DeltaTime)
{
	// GameEngineDebug::DrawBox(Collision->GetTransform(), { 1.0f, 0.0f,0.0f, 0.5f });
	// GameEngineDebug::DrawSphere(Collision->GetTransform(), {1.0f, 0.0f,0.0f, 0.5f});

	if (true == GetLevel()->GetMainCameraActor()->IsFreeCameraMode())
	{
		return;
	}

	StateManager.Update(_DeltaTime);

	//if (true == Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::UI, CollisionType::CT_OBB2D))
	//{
	//	int a = 0;
	//	// ��Ż�� ��Ҵٸ�
	//}

	//Renderer->AnimationBindEnd("Test2", std::bind(&Player::Test2End, this, std::placeholders::_1));
	//Renderer->AnimationBindEnd("Test1", std::bind(&Player::Test2End, this, std::placeholders::_1));
}