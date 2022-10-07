#include "PreCompile.h"
#include"MonUnit.h"

MonUnit::MonUnit()
	: MonType(MonUnitGroup::None),
	UnitRenderer(),
	TileMap(),
	UnitX(0),
	UnitY(0),
	UnitZ(0),
	MaxHP_(0),
	Hp_(0),
	MaxMP_(0),
	Mp_(0),
	Atk_(0),
	Def_(0),
	Matk_(0),
	MDef_(0),
	Dex_(0),
	Level_(0),
	MaxExp_(0),
	Exp_(0),
	Fire_(0),
	Water_(0),
	Earth_(0),
	Wind_(0),
	Dark_(0),
	Light_(0),
	Strength_(0),
	Detect_(0),
	Intelligence_(0),
	Reflection_(0),
	Heyste_(0),
	IdleDirection_(IdleDirection::RigntDown),
	MoveCount_(0),
	Turn_(0)
{

}
MonUnit::~MonUnit()
{

}
void MonUnit::Start()
{
}
void MonUnit::Update(float _DeltaTime)
{
	if (IdleDirection_ == IdleDirection::RigntUp)
	{
		UnitRenderer->ChangeFrameAnimation("GoblinIdleRU");
	}
	if (IdleDirection_ == IdleDirection::LeftUp)
	{
		UnitRenderer->ChangeFrameAnimation("GoblinIdleRU");
		UnitRenderer->GetTransform().PixLocalNegativeX();
	}
	if (IdleDirection_ == IdleDirection::RigntDown)
	{
		UnitRenderer->ChangeFrameAnimation("GoblinIdleLD");
		UnitRenderer->GetTransform().PixLocalNegativeX();
	}
	if (IdleDirection_ == IdleDirection::LeftDown)
	{
		UnitRenderer->ChangeFrameAnimation("GoblinIdleLD");
	}
}
void MonUnit::End() 
{

}

void MonUnit::SetTileRenderer(TileMapRenderer* _TileMapRenderer)
{
	TileMap = _TileMapRenderer;
}

void MonUnit::SetUnit(int _X, int _Y, std::string _UnitName)
{
	GameEngineString::ToUpper(_UnitName);// 대문자로변환해서 조건문 으로 체크 한뒤 유닛 정보를 세팅

	UnitX = static_cast<float>(_X);
	UnitY = static_cast<float>(_Y);
	UnitZ = static_cast<float>(TileMap->Tiles[_Y][_X].Z);
	if (TileMap->Tiles[_Y][_X].IsUnit != PlayUnitGroup::None)
	{
		MsgBoxAssert("설치하려는 자리에 이미 동료가 있습니다.");
		return;
	}
	if (TileMap->Tiles[_Y][_X].IsMapObject == true)
	{
		MsgBoxAssert("설치하려는 자리에 이미 오브젝트가 있습니다.");
		return;
	}
	if (TileMap->Tiles[_Y][_X].IsMon != MonUnitGroup::None)
	{
		MsgBoxAssert("설치하려는 자리에 이미 몬스터가 있습니다.");
		return;
	}


	float4 Pos;
	float4 Half = { 32,16,0,0 };

	Pos.x = (_X * Half.x) + (_Y * -Half.x);
	Pos.y = (_X * -Half.y) + (_Y * -Half.y) + (UnitZ * 16.0f) - 16;
	UnitRenderer = CreateComponent<GameEngineTextureRenderer>();
	UnitRenderer->GetTransform().SetLocalScale({ 100,100, 1 });
	UnitRenderer->GetTransform().SetWorldPosition(float4(Pos.x, Pos.y + 16.0f, -(TileMap->Tiles[UnitY][UnitX].TileDepth + 1)));

	if (_UnitName == "GOBLIN")
	{
		UnitRenderer->CreateFrameAnimationCutTexture("GoblinIdleLD", FrameAnimation_DESC("GoblinIdle.png", 0, 2, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("GoblinIdleRU", FrameAnimation_DESC("GoblinIdle.png", 3, 5, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("GoblinWalkU", FrameAnimation_DESC("LeonWalkU.png", 0, 3, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("GoblinWalkD", FrameAnimation_DESC("LeonWalkD.png", 0, 3, 0.2f));

		TileMap->Tiles[static_cast<float>(UnitY)][static_cast<float>(UnitX)].IsMon = MonUnitGroup::Goblin;
	}
	else if (_UnitName == "WOLF")
	{

	}
}
void MonUnit::UnitMove(size_t _MoveConter, MoveDirection _MoveDirection)
{

		if (_MoveDirection == MoveDirection::RigntUp)
		{
			for (size_t i = 0; i < _MoveConter; i++)
			{

			}
		}
		else if (_MoveDirection == MoveDirection::LeftDown)
		{
			for (size_t i = 0; i < _MoveConter; i++)
			{

			}
		}
		else if (_MoveDirection == MoveDirection::LeftUp)
		{
			for (size_t i = 0; i < _MoveConter; i++)
			{

			}
		}
		else if (_MoveDirection == MoveDirection::RigntDown)
		{
			for (size_t i = 0; i < _MoveConter; i++)
			{

			}
		}
	
}
void MonUnit::SetTurn(size_t _Turn)
{
	Turn_ = _Turn;
}