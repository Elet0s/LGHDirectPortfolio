#include "PreCompile.h"
#include"PlayUnit.h"
#include <iostream>
#include <GameEngineContents/GlobalContentsValue.h>

PlayUnit::PlayUnit()
	: UnitType(PlayUnitGroup::None)
	, Speed(50.0f)
	, UnitRenderer()
	, _Hp()
	, _Mp()
	, _Atk()
	, _Def()
	, _Move()
{

}
PlayUnit::~PlayUnit()
{

}

void PlayUnit::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("PlayerLeftUP"))
	{
		GameEngineInput::GetInst()->CreateKey("PlayerLeftUP", 'W');
		GameEngineInput::GetInst()->CreateKey("PlayerLeftDown", 'A');
		GameEngineInput::GetInst()->CreateKey("PlayerRightUP", 'D');
		GameEngineInput::GetInst()->CreateKey("PlayerRightDown", 'S');
	}
	{
		UnitRenderer = CreateComponent<GameEngineTextureRenderer>();
		UnitRenderer->GetTransform().SetLocalScale({ 100,100, 1 });
		UnitRenderer->CreateFrameAnimationCutTexture("LeonWalkU", FrameAnimation_DESC("LeonWalkU.png", 0, 3, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("LeonWalkD", FrameAnimation_DESC("LeonWalkD.png", 0, 3, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("LeonIdle", FrameAnimation_DESC("LeonIdle.png", 0, 2, 0.2f));
		UnitRenderer->ChangeFrameAnimation("LeonIdle");
		UnitRenderer->GetTransform().SetWorldPosition(float4(0, 0, -100));
	}
	StateManager1.CreateStateMember("Idle", std::bind(&PlayUnit::IdleUpdate, this, std::placeholders::_1, std::placeholders::_2), std::bind(&PlayUnit::IdleStart, this, std::placeholders::_1));
	StateManager1.CreateStateMember("Move", std::bind(&PlayUnit::MoveUpdate, this, std::placeholders::_1, std::placeholders::_2), [/*&*/=](const StateInfo& _Info)
		{
			if (true == GameEngineInput::GetInst()->IsDown("PlayerLeftUP") || true == GameEngineInput::GetInst()->IsDown("PlayerRightUp"))
			{
				UnitRenderer->ChangeFrameAnimation("LeonWalkU");
			}
			else if (true == GameEngineInput::GetInst()->IsDown("PlayerLeftDown") || true == GameEngineInput::GetInst()->IsDown("PlayerRightDown"))
			{
				UnitRenderer->ChangeFrameAnimation("LeonWalkD");
			}
		});
	StateManager1.ChangeState("Idle");
}

void PlayUnit::Update(float _DeltaTime)
{
	if (true == GetLevel()->GetMainCameraActor()->IsFreeCameraMode())
	{
		return;
	}
	StateManager1.Update(_DeltaTime);
}

void PlayUnit::End() 
{

}

void PlayUnit::IdleStart(const StateInfo& _Info)
{
	UnitRenderer->ChangeFrameAnimation("LeonIdle");
}
void PlayUnit::IdleUpdate(float _DeltaTime, const StateInfo& _Info)
{
	if (true == GameEngineInput::GetInst()->IsPress("PlayerLeftUP") ||
		true == GameEngineInput::GetInst()->IsPress("PlayerLeftDown") ||
		true == GameEngineInput::GetInst()->IsPress("PlayerRightUP") ||
		true == GameEngineInput::GetInst()->IsPress("PlayerRightDown"))
	{
		StateManager1.ChangeState("Move");
	}
}

void PlayUnit::MoveUpdate(float _DeltaTime, const StateInfo& _Info)
{

	if (false == GameEngineInput::GetInst()->IsPress("PlayerLeftUP") && false == GameEngineInput::GetInst()->IsPress("PlayerLeftDown") && false == GameEngineInput::GetInst()->IsPress("PlayerRightUP") && false == GameEngineInput::GetInst()->IsPress("PlayerRightDown"))
	{
		StateManager1.ChangeState("Idle");
		return;
	}

	if (true == GameEngineInput::GetInst()->IsPress("PlayerLeftUP"))
	{
		GetTransform().SetWorldMove(GetTransform().GetLeftVector() * Speed * 2 * _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetUpVector() * Speed * _DeltaTime);
		UnitRenderer->GetTransform().PixLocalPositiveX();
		//Renderer->GetColorData().MulColor.a -= _DeltaTime;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("PlayerLeftDown"))
	{
		GetTransform().SetWorldMove(GetTransform().GetLeftVector() * Speed * 2 * _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetDownVector() * Speed * _DeltaTime);
		UnitRenderer->GetTransform().PixLocalPositiveX();
	}

	else if (true == GameEngineInput::GetInst()->IsPress("PlayerRightUP"))
	{
		GetTransform().SetWorldMove(GetTransform().GetRightVector() * Speed * 2 * _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetUpVector() * Speed * _DeltaTime);
		UnitRenderer->GetTransform().PixLocalNegativeX();
	}
	else if (true == GameEngineInput::GetInst()->IsPress("PlayerRightDown"))
	{
		GetTransform().SetWorldMove(GetTransform().GetRightVector() * Speed * 2 * _DeltaTime);
		GetTransform().SetWorldMove(GetTransform().GetDownVector() * Speed * _DeltaTime);
		UnitRenderer->GetTransform().PixLocalNegativeX();
	}

}

void PlayUnit::SetTileRenderer(TileMapRenderer* _TileMapRenderer)
{
	TileMap = _TileMapRenderer;
}

void PlayUnit::SetUnit(int _X, int _Y, std::string _UnitName)
{
	GameEngineString::ToUpper(_UnitName);// 대문자로변환해서 조건문 으로 체크 한뒤 유닛 정보를 세팅

	UnitX = _X;
	UnitY = _Y;
	UnitZ = TileMap->Tiles[_Y][_X].Z;

	float4 Pos;
	float4 Half = {32,16,0,0};

	Pos.x = (_X * Half.x) + (_Y * -Half.x);
	Pos.y = (_X * -Half.y) + (_Y * -Half.y) + (UnitZ * 16.0f);
	UnitRenderer->GetTransform().SetWorldPosition(float4(Pos.x, Pos.y+16.0f, -100));

	if (_UnitName == "LEON")
	{

	}
	else if(_UnitName == "RALF")
	{

	}
	else if (_UnitName == "BRIAN")
	{

	}
	else if (_UnitName == "TT")
	{

	}
	else if (_UnitName ==  "Mascia")
	{

	}
	else if (_UnitName == "farm")
	{

	}
	else if (_UnitName == "Karin")
	{

	}
	else if (_UnitName == " Rian")
	{

	}
	else if (_UnitName ==  "Ophelia")
	{

	}
}

void PlayUnit::UnitMove(size_t _MoveConter, MoveDirection _MoveDirection)
{
	if (_MoveDirection == MoveDirection::Up)
	{
		for (size_t i = 0; i < _MoveConter; i++)
		{

		}
	}
	else if (_MoveDirection == MoveDirection::Down)
	{
		for (size_t i = 0; i < _MoveConter; i++)
		{

		}
	}
	else if (_MoveDirection == MoveDirection::Left)
	{
		for (size_t i = 0; i < _MoveConter; i++)
		{

		}
	}
	else if (_MoveDirection == MoveDirection::Right)
	{
		for (size_t i = 0; i < _MoveConter; i++)
		{

		}
	}
}