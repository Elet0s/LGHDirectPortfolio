#include "PreCompile.h"
#include"PlayUnit.h"
#include <iostream>
#include <GameEngineContents/GlobalContentsValue.h>


PlayUnit::PlayUnit()
	: UnitType(PlayUnitGroup::None)
	, Speed(50.0f)
	, UnitRenderer()
	, UnitX(0)
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
	, MaxHP_(10)
	, MaxMP_(10)
	, MaxExp_(0)
	, IdleDirection_(IdleDirection::LeftDown)
	, MoveCount_(0)
	, Turn_(0)
	, MaxCounter_(0)
	, MoveCheakerStart_(false)
	, AtkRange_(0)
{
}
PlayUnit::~PlayUnit()
{

}

void PlayUnit::Start()
{
}

void PlayUnit::MoveCheaker(MoveDirection _MoveDirection, float _X, float _Y,int _MoveCount)
{
	if (_MoveCount > 0)
	{
		if (TileMap->Tiles[_Y][_X].IsMapObject == false && TileMap->Tiles[_Y][_X].IsMon == MonUnitGroup::None && TileMap->Tiles[_Y][_X].IsUnit == PlayUnitGroup::None)//조사할 타일에 뭐 없다면
		{
			_MoveCount -= 1;
			TileMap->Tiles[_Y][_X].IsMoveOnTile = true; //이동가능
			if (_X > 0 && _Y > 0 && _X < TileMap->Tiles.size() && _Y < TileMap->Tiles.size()) //타일 범위 안에있을때
			{
				MoveCheaker(MoveDirection::RigntUp, _X, _Y - 1, _MoveCount);
				MoveCheaker(MoveDirection::LeftUp, _X - 1, _Y, _MoveCount);
				MoveCheaker(MoveDirection::RigntDown, _X + 1, _Y, _MoveCount);
				MoveCheaker(MoveDirection::LeftDown, _X, _Y + 1, _MoveCount);
			}
			else if (_X == 0)
			{
				MoveCheaker(MoveDirection::RigntDown, _X + 1, _Y, _MoveCount);

				if (_Y == 0)
				{
					MoveCheaker(MoveDirection::LeftDown, _X, _Y + 1, _MoveCount);
				}
				else
				{
					MoveCheaker(MoveDirection::RigntUp, _X, _Y - 1, _MoveCount);
				}
				if (_Y == TileMap->Tiles.size())
				{
					MoveCheaker(MoveDirection::RigntUp, _X, _Y - 1, _MoveCount);
				}
				else
				{
					MoveCheaker(MoveDirection::LeftDown, _X, _Y + 1, _MoveCount);
				}
			}
			else if (_Y == 0)
			{
				MoveCheaker(MoveDirection::LeftDown, _X, _Y + 1, _MoveCount);
				if (_X == 0)
				{
					MoveCheaker(MoveDirection::RigntDown, _X + 1, _Y, _MoveCount);
				}
				else
				{
					MoveCheaker(MoveDirection::LeftUp, _X - 1, _Y, _MoveCount);
				}
				if (_X == TileMap->Tiles.size())
				{
					MoveCheaker(MoveDirection::LeftUp, _X - 1, _Y, _MoveCount);
				}
				else
				{
					MoveCheaker(MoveDirection::RigntDown, _X + 1, _Y, _MoveCount);
				}
			}
			else if (_X == TileMap->Tiles.size())
			{
				MoveCheaker(MoveDirection::LeftUp, _X - 1, _Y, _MoveCount);
				if (_Y == 0)
				{
					MoveCheaker(MoveDirection::LeftDown, _X, _Y + 1, _MoveCount);
				}
				else
				{
					MoveCheaker(MoveDirection::RigntUp, _X, _Y - 1, _MoveCount);
				}
				if (_Y == TileMap->Tiles.size())
				{
					MoveCheaker(MoveDirection::RigntUp, _X, _Y - 1, _MoveCount);
				}
				else
				{
					MoveCheaker(MoveDirection::LeftDown, _X, _Y + 1, _MoveCount);
				}
			}
			else if (_Y == TileMap->Tiles.size())
			{
				MoveCheaker(MoveDirection::RigntUp, _X, _Y - 1, _MoveCount);
				if (_X == 0)
				{
					MoveCheaker(MoveDirection::RigntDown, _X + 1, _Y, _MoveCount);
				}
				else
				{
					MoveCheaker(MoveDirection::LeftUp, _X - 1, _Y, _MoveCount);
				}
				if (_X == TileMap->Tiles.size())
				{
					MoveCheaker(MoveDirection::LeftUp, _X - 1, _Y, _MoveCount);
				}
				else
				{
					MoveCheaker(MoveDirection::RigntDown, _X + 1, _Y, _MoveCount);
				}
			}
		}
	}
}
void PlayUnit::Update(float _DeltaTime)
{

	if (Turn_ % 2 == 1)//홀수턴일때
	{
		if (TileMap->Tiles[static_cast<size_t>(UnitY)][static_cast<size_t>(UnitX)].IsUnit != PlayUnitGroup::None)//플레이어 유닛이 맞는지 체크
		{
			if (TileMap->Tiles[static_cast<size_t>(UnitY)][static_cast<size_t>(UnitX)].ClickOnUint == true)//클릭했는지 체크
			{
				if (MoveCheakerStart_ == false)//캐릭터 눌렀을때 한번만 체크해줘야함
				{
					TileMap->Tiles[UnitY][UnitX].IsMoveOnTile = true;
					//MoveCount_ = MaxCounter_;
					MoveCheakerStart_ = true;
				}
				if (UnitX > 0 && UnitY > 0 && UnitX < TileMap->Tiles.size() && UnitY < TileMap->Tiles.size()) //타일 범위 안에있을때
				{
					MoveCheaker(MoveDirection::RigntUp, UnitX, UnitY - 1, MaxCounter_);
					MoveCheaker(MoveDirection::LeftUp, UnitX - 1, UnitY, MaxCounter_);
					MoveCheaker(MoveDirection::RigntDown, UnitX + 1, UnitY, MaxCounter_);
					MoveCheaker(MoveDirection::LeftDown, UnitX, UnitY +1, MaxCounter_);
				}
				else if (UnitX == 0)
				{
					MoveCheaker(MoveDirection::RigntDown, UnitX + 1, UnitY, MaxCounter_);

					if (UnitY == 0)
					{
						MoveCheaker(MoveDirection::LeftDown, UnitX, UnitY + 1, MaxCounter_);
					}
					else
					{
						MoveCheaker(MoveDirection::RigntUp, UnitX, UnitY - 1, MaxCounter_);
					}
					if (UnitY == TileMap->Tiles.size())
					{
						MoveCheaker(MoveDirection::RigntUp, UnitX, UnitY - 1, MaxCounter_);
					}
					else
					{
						MoveCheaker(MoveDirection::LeftDown, UnitX, UnitY + 1, MaxCounter_);
					}
				}
				else if(UnitY == 0)
				{
					MoveCheaker(MoveDirection::LeftDown, UnitX, UnitY + 1, MaxCounter_);
					if (UnitX == 0)
					{
						MoveCheaker(MoveDirection::RigntDown, UnitX + 1, UnitY, MaxCounter_);
					}
					else
					{
						MoveCheaker(MoveDirection::LeftUp, UnitX - 1, UnitY, MaxCounter_);
					}
					if (UnitX == TileMap->Tiles.size())
					{
						MoveCheaker(MoveDirection::LeftUp, UnitX - 1, UnitY, MaxCounter_);
					}
					else
					{
						MoveCheaker(MoveDirection::RigntDown, UnitX + 1, UnitY, MaxCounter_);
					}
				}
				else if (UnitX == TileMap->Tiles.size())
				{
					MoveCheaker(MoveDirection::LeftUp, UnitX - 1, UnitY, MaxCounter_);
					if (UnitY == 0)
					{
						MoveCheaker(MoveDirection::LeftDown, UnitX, UnitY + 1, MaxCounter_);
					}
					else
					{
						MoveCheaker(MoveDirection::RigntUp, UnitX, UnitY - 1, MaxCounter_);
					}
					if (UnitY == TileMap->Tiles.size())
					{
						MoveCheaker(MoveDirection::RigntUp, UnitX, UnitY - 1, MaxCounter_);
					}
					else
					{
						MoveCheaker(MoveDirection::LeftDown, UnitX, UnitY + 1, MaxCounter_);
					}
				}
				else if (UnitY == TileMap->Tiles.size())
				{
					MoveCheaker(MoveDirection::RigntUp, UnitX, UnitY - 1, MaxCounter_);
					if (UnitX == 0)
					{
						MoveCheaker(MoveDirection::RigntDown, UnitX + 1, UnitY, MaxCounter_);
					}
					else
					{
						MoveCheaker(MoveDirection::LeftUp, UnitX - 1, UnitY, MaxCounter_);
					}
					if (UnitX == TileMap->Tiles.size())
					{
						MoveCheaker(MoveDirection::LeftUp, UnitX - 1, UnitY, MaxCounter_);
					}
					else
					{
						MoveCheaker(MoveDirection::RigntDown, UnitX + 1, UnitY, MaxCounter_);
					}
				}
			}
		}
	}
}

void PlayUnit::End() 
{

}

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

void PlayUnit::SetTileRenderer(TileMapRenderer* _TileMapRenderer)
{
	TileMap = _TileMapRenderer;
}

void PlayUnit::SetUnit(int _X, int _Y, std::string _UnitName)
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
	if (_UnitName == "LEON")
	{
		UnitRenderer->CreateFrameAnimationCutTexture("LeonWalkU", FrameAnimation_DESC("LeonWalkU.png", 0, 3, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("LeonWalkD", FrameAnimation_DESC("LeonWalkD.png", 0, 3, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("LeonIdle", FrameAnimation_DESC("LeonIdle.png", 0, 2, 0.2f));
		UnitRenderer->ChangeFrameAnimation("LeonIdle");
		TileMap->Tiles[static_cast<size_t>(UnitY)][static_cast<size_t>(UnitX)].IsUnit = PlayUnitGroup::Leon;

		MaxHP_ = 34;
		Hp_ = 34;

		MaxMP_ = 10;
		Mp_ = 5;

		Atk_ = 33;
		Def_ = 19;
		Matk_ = 10;
		MDef_ = 14;
		Dex_ = 23;
		AtkRange_ = 1;
		MaxCounter_ = 6;

		Level_ = 1;
		MaxExp_ = 100;
		Exp_ = 0;
	}
	else if (_UnitName == "RALF")
	{

	}
	else if (_UnitName == "BRIAN")
	{

	}
}

void PlayUnit::UnitMove(size_t _MoveConter, MoveDirection _MoveDirection)
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
void PlayUnit::SetTurn(size_t _Turn)
{
	Turn_ = _Turn;
}