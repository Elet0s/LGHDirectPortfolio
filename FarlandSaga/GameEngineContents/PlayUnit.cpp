#include "PreCompile.h"
#include"PlayUnit.h"
#include <iostream>
#include <GameEngineContents/GlobalContentsValue.h>

PlayUnit::PlayUnit()
	: UnitType(PlayUnitGroup::None)
	, Speed(50.0f)
	, UnitRenderer()
	,UnitX(0)
	, UnitY(0)
	, UnitZ(0)
	, TileMap()
	, Hp_(0)
	, Mp_(0)
	, Atk_(0)
	, Def_(0)
	, Matk_(0)
	, MDef_(0)
	, Dex_(0)
	, Exp_(0)
	, Level_(0)
	, Fire_(0)
	, Water_(0)
	, Earth_(0)
	, Wind_(0)
	, Dark_(0)
	, Light_(0)
	, Strength_(0)
	, Detect_(0)
	, Intelligence_(0)
	, Reflection_(0)
	, Heyste_(0)
{
}
PlayUnit::~PlayUnit()
{

}

void PlayUnit::Start()
{
}

void PlayUnit::Update(float _DeltaTime)
{
	if (true == GetLevel()->GetMainCameraActor()->IsFreeCameraMode())
	{
		return;
	}
//	StateManager1.Update(_DeltaTime);
}

void PlayUnit::End() 
{

}

void PlayUnit::IdleStart(const StateInfo& _Info)
{

}
void PlayUnit::IdleUpdate(float _DeltaTime, const StateInfo& _Info)
{
}

void PlayUnit::MoveUpdate(float _DeltaTime, const StateInfo& _Info)
{

	//if (true == GameEngineInput::GetInst()->IsPress("PlayerLeftUP"))
	//{
	//	GetTransform().SetWorldMove(GetTransform().GetLeftVector() * Speed * 2 * _DeltaTime);
	//	GetTransform().SetWorldMove(GetTransform().GetUpVector() * Speed * _DeltaTime);
	//	UnitRenderer->GetTransform().PixLocalPositiveX();
	//	//Renderer->GetColorData().MulColor.a -= _DeltaTime;
	//}
	//
	//else if (true == GameEngineInput::GetInst()->IsPress("PlayerLeftDown"))
	//{
	//	GetTransform().SetWorldMove(GetTransform().GetLeftVector() * Speed * 2 * _DeltaTime);
	//	GetTransform().SetWorldMove(GetTransform().GetDownVector() * Speed * _DeltaTime);
	//	UnitRenderer->GetTransform().PixLocalPositiveX();
	//}
	//
	//else if (true == GameEngineInput::GetInst()->IsPress("PlayerRightUP"))
	//{
	//	GetTransform().SetWorldMove(GetTransform().GetRightVector() * Speed * 2 * _DeltaTime);
	//	GetTransform().SetWorldMove(GetTransform().GetUpVector() * Speed * _DeltaTime);
	//	UnitRenderer->GetTransform().PixLocalNegativeX();
	//}
	//else if (true == GameEngineInput::GetInst()->IsPress("PlayerRightDown"))
	//{
	//	GetTransform().SetWorldMove(GetTransform().GetRightVector() * Speed * 2 * _DeltaTime);
	//	GetTransform().SetWorldMove(GetTransform().GetDownVector() * Speed * _DeltaTime);
	//	UnitRenderer->GetTransform().PixLocalNegativeX();
	//}

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
	if (TileMap->Tiles[_Y][_X].IsUnit == true)
	{
		MsgBoxAssert("설치하려는 자리에 이미 동료가 있습니다.");
		return;
	}
	if (TileMap->Tiles[_Y][_X].IsMapObject	== true)
	{
		MsgBoxAssert("설치하려는 자리에 이미 오브젝트가 있습니다.");
		return;
	}
	if (TileMap->Tiles[_Y][_X].IsMon == true)
	{
		MsgBoxAssert("설치하려는 자리에 이미 몬스터가 있습니다.");
		return;
	}
	

	float4 Pos;
	float4 Half = {32,16,0,0};

	Pos.x = (_X * Half.x) + (_Y * -Half.x);
	Pos.y = (_X * -Half.y) + (_Y * -Half.y) + (UnitZ * 16.0f) -16;
	UnitRenderer = CreateComponent<GameEngineTextureRenderer>();
	UnitRenderer->GetTransform().SetLocalScale({ 100,100, 1 });
	UnitRenderer->GetTransform().SetWorldPosition(float4(Pos.x, Pos.y+16.0f, -100));

	if (_UnitName == "LEON")
	{
		UnitRenderer->CreateFrameAnimationCutTexture("LeonWalkU", FrameAnimation_DESC("LeonWalkU.png", 0, 3, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("LeonWalkD", FrameAnimation_DESC("LeonWalkD.png", 0, 3, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("LeonIdle", FrameAnimation_DESC("LeonIdle.png", 0, 2, 0.2f));
		UnitRenderer->ChangeFrameAnimation("LeonIdle");
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