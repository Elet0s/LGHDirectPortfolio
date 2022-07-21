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
	Renderer->ChangeFrameAnimation("Test1");
}



void Player::Test1End(const FrameAnimation_DESC& _Info)
{

	GameEngineDebug::OutPutString("앤드\n");
	Renderer->ChangeFrameAnimation("Test2");

}

void Test2Frame(const FrameAnimation_DESC& _Info)
{
	// GameEngineDebug::OutPutString("프레임\n");
}

void Test2Time(const FrameAnimation_DESC& _Info, float _Time)
{
	// GameEngineDebug::OutPutString("타임\n");
}

void Player::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("PlayerLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("PlayerLeft", 'L');
		GameEngineInput::GetInst()->CreateKey("R", 'R');
	}



	GetTransform().SetLocalScale({ 1, 1, 1 });

	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 81, 81, 81 });
		Renderer->CreateFrameAnimationFolder("Test2", FrameAnimation_DESC("CUP", 0.1f));
		Renderer->CreateFrameAnimationFolder("Test1", FrameAnimation_DESC("AN", 0.1f));
		Renderer->CreateFrameAnimation("LeonIdle", FrameAnimation_DESC("LeonIdle.png",0,1,0.1f));

		Renderer->ChangeFrameAnimation("LeonIdle");
	}
}

void Player::Update(float _DeltaTime)
{
	Renderer->AnimationBindEnd("Test2", std::bind(&Player::Test2End, this, std::placeholders::_1));
	Renderer->AnimationBindEnd("Test1", std::bind(&Player::Test2End, this, std::placeholders::_1));

	if (true == GameEngineInput::GetInst()->IsPress("PlayerLeft"))
	{
		GetTransform().SetWorldMove(GetTransform().GetLeftVector() * Speed * _DeltaTime);
	}
}