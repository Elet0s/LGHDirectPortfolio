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
	, IdleDirection_(IdleDirection::LeftUp)
	, MoveCount_(0)
	, Turn_(0)
	, MaxCounter_(0)
	, MoveCheakerStart_(false)
	, AtkRange_(0)
	, RangeCheakerStart_(false)
	, EnterMon_(false)
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
		if (TileMap->Tiles[_Y][_X].IsMapObject == false && TileMap->Tiles[_Y][_X].IsMon == MonUnitGroup::None && TileMap->Tiles[_Y][_X].IsUnit == PlayUnitGroup::None)//������ Ÿ�Ͽ� �� ���ٸ�
		{
			_MoveCount -= 1;
			TileMap->Tiles[_Y][_X].IsMoveOnTile = true; //�̵�����
			if (_X > 0 && _Y > 0 && _X < TileMap->Tiles.size() && _Y < TileMap->Tiles.size()) //Ÿ�� ���� �ȿ�������
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
void PlayUnit::MonCheaker(MoveDirection _CheakDirection, float _X, float _Y, int _AtkRange)
{
	if (_AtkRange > 0)
	{
		if (TileMap->Tiles[_Y][_X].IsMon != MonUnitGroup::None)//���� Ÿ�Ͽ� �� �ִٸ�
		{
			EnterMon_ = true;//���� �߰�
			TileMap->Tiles[_Y][_X].IsAtkOnTile = true; //���ݰ���
		}
		_AtkRange -= 1;
		if (_X > 0 && _Y > 0 && _X < TileMap->Tiles.size() && _Y < TileMap->Tiles.size()) //Ÿ�� ���� �ȿ�������
		{
			MonCheaker(MoveDirection::RigntUp, _X, _Y - 1, _AtkRange);
			MonCheaker(MoveDirection::LeftUp, _X - 1, _Y, _AtkRange);
			MonCheaker(MoveDirection::RigntDown, _X + 1, _Y, _AtkRange);
			MonCheaker(MoveDirection::LeftDown, _X, _Y + 1, _AtkRange);
		}
		else if (_X == 0)
		{
			MonCheaker(MoveDirection::RigntDown, _X + 1, _Y, _AtkRange);

			if (_Y == 0)
			{
				MonCheaker(MoveDirection::LeftDown, _X, _Y + 1, _AtkRange);
			}
			else
			{
				MonCheaker(MoveDirection::RigntUp, _X, _Y - 1, _AtkRange);
			}
			if (_Y == TileMap->Tiles.size())
			{
				MonCheaker(MoveDirection::RigntUp, _X, _Y - 1, _AtkRange);
			}
			else
			{
				MonCheaker(MoveDirection::LeftDown, _X, _Y + 1, _AtkRange);
			}
		}
		else if (_Y == 0)
		{
			MonCheaker(MoveDirection::LeftDown, _X, _Y + 1, _AtkRange);
			if (_X == 0)
			{
				MonCheaker(MoveDirection::RigntDown, _X + 1, _Y, _AtkRange);
			}
			else
			{
				MonCheaker(MoveDirection::LeftUp, _X - 1, _Y, _AtkRange);
			}
			if (_X == TileMap->Tiles.size())
			{
				MonCheaker(MoveDirection::LeftUp, _X - 1, _Y, _AtkRange);
			}
			else
			{
				MonCheaker(MoveDirection::RigntDown, _X + 1, _Y, _AtkRange);
			}
		}
		else if (_X == TileMap->Tiles.size())
		{
			MonCheaker(MoveDirection::LeftUp, _X - 1, _Y, _AtkRange);
			if (_Y == 0)
			{
				MonCheaker(MoveDirection::LeftDown, _X, _Y + 1, _AtkRange);
			}
			else
			{
				MonCheaker(MoveDirection::RigntUp, _X, _Y - 1, _AtkRange);
			}
			if (_Y == TileMap->Tiles.size())
			{
				MonCheaker(MoveDirection::RigntUp, _X, _Y - 1, _AtkRange);
			}
			else
			{
				MonCheaker(MoveDirection::LeftDown, _X, _Y + 1, _AtkRange);
			}
		}
		else if (_Y == TileMap->Tiles.size())
		{
			MonCheaker(MoveDirection::RigntUp, _X, _Y - 1, _AtkRange);
			if (_X == 0)
			{
				MonCheaker(MoveDirection::RigntDown, _X + 1, _Y, _AtkRange);
			}
			else
			{
				MonCheaker(MoveDirection::LeftUp, _X - 1, _Y, _AtkRange);
			}
			if (_X == TileMap->Tiles.size())
			{
				MonCheaker(MoveDirection::LeftUp, _X - 1, _Y, _AtkRange);
			}
			else
			{
				MonCheaker(MoveDirection::RigntDown, _X + 1, _Y, _AtkRange);
			}
		}
	}
}
void PlayUnit::Update(float _DeltaTime)
{

	if (TileMap->Tiles[static_cast<size_t>(UnitY)][static_cast<size_t>(UnitX)].IsUnit == PlayUnitGroup::Leon)
	{
		if (IdleDirection_ == IdleDirection::RigntUp)
		{
			UnitRenderer->ChangeFrameAnimation("LeonIdleRU");
		}
		if (IdleDirection_ == IdleDirection::LeftUp)
		{
			UnitRenderer->ChangeFrameAnimation("LeonIdleRU");
			UnitRenderer->GetTransform().PixLocalNegativeX();
		}
		if (IdleDirection_ == IdleDirection::RigntDown)
		{
			UnitRenderer->ChangeFrameAnimation("LeonIdleLD");
			UnitRenderer->GetTransform().PixLocalNegativeX();
		}
		if (IdleDirection_ == IdleDirection::LeftDown)
		{
			UnitRenderer->ChangeFrameAnimation("LeonIdleLD");
		}
	}	
	else if (TileMap->Tiles[static_cast<size_t>(UnitY)][static_cast<size_t>(UnitX)].IsUnit == PlayUnitGroup::Ralf)
	{
		if (IdleDirection_ == IdleDirection::RigntUp)
		{
			UnitRenderer->ChangeFrameAnimation("RalfIdleRU");
		}
		if (IdleDirection_ == IdleDirection::LeftUp)
		{
			UnitRenderer->ChangeFrameAnimation("RalfIdleRU");
			UnitRenderer->GetTransform().PixLocalNegativeX();
		}
		if (IdleDirection_ == IdleDirection::RigntDown)
		{
			UnitRenderer->ChangeFrameAnimation("RalfIdleLD");
			UnitRenderer->GetTransform().PixLocalNegativeX();
		}
		if (IdleDirection_ == IdleDirection::LeftDown)
		{
			UnitRenderer->ChangeFrameAnimation("RalfIdleLD");
		}
	}
	else if (TileMap->Tiles[static_cast<size_t>(UnitY)][static_cast<size_t>(UnitX)].IsUnit == PlayUnitGroup::Brian)
	{
		if (IdleDirection_ == IdleDirection::RigntUp)
		{
			UnitRenderer->ChangeFrameAnimation("BrianIdleRU");
		}
		if (IdleDirection_ == IdleDirection::LeftUp)
		{
			UnitRenderer->ChangeFrameAnimation("BrianIdleRU");
			UnitRenderer->GetTransform().PixLocalNegativeX();
		}
		if (IdleDirection_ == IdleDirection::RigntDown)
		{
			UnitRenderer->ChangeFrameAnimation("BrianIdleLD");
			UnitRenderer->GetTransform().PixLocalNegativeX();
		}
		if (IdleDirection_ == IdleDirection::LeftDown)
		{
			UnitRenderer->ChangeFrameAnimation("BrianIdleLD");
		}
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

	if (Turn_ % 2 == 1)//Ȧ�����϶�
	{
		if (TileMap->Tiles[static_cast<size_t>(UnitY)][static_cast<size_t>(UnitX)].IsUnit != PlayUnitGroup::None)//�÷��̾� ������ �´��� üũ
		{
			if (TileMap->Tiles[static_cast<size_t>(UnitY)][static_cast<size_t>(UnitX)].ClickOnUint == true)//Ŭ���ߴ��� üũ
			{
				if (MoveCheakerStart_ == false)//ĳ���� �������� �ѹ��� üũ�������
				{
					TileMap->Tiles[UnitY][UnitX].IsMoveOnTile = true;
					MoveCheakerStart_ = true;
				}
				if (RangeCheakerStart_ == false)
				{
					if (UnitX > 0 && UnitY > 0 && UnitX < TileMap->Tiles.size() && UnitY < TileMap->Tiles.size()) //Ÿ�� ���� �ȿ�������
					{
						MoveCheaker(MoveDirection::RigntUp, UnitX, UnitY - 1, MaxCounter_);
						MoveCheaker(MoveDirection::LeftUp, UnitX - 1, UnitY, MaxCounter_);
						MoveCheaker(MoveDirection::RigntDown, UnitX + 1, UnitY, MaxCounter_);
						MoveCheaker(MoveDirection::LeftDown, UnitX, UnitY + 1, MaxCounter_);
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
					else if (UnitY == 0)
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

			if (true == GameEngineInput::GetInst()->IsDown("MouseLeft"))
			{
				if (UnitMouse->MouseOnX >= 0 && UnitMouse->MouseOnY >= 0 && UnitMouse->MouseOnX < TileMap->Tiles.size() && UnitMouse->MouseOnY < TileMap->Tiles.size())
				{
					if (TileMap->Tiles[UnitMouse->MouseOnY][UnitMouse->MouseOnX].IsMoveOnTile == true)//���콺 Ŭ�������� ���콺�� �ִ� Ÿ�� 
					{
						int X = UnitMouse->MouseOnX;
						int Y = UnitMouse->MouseOnY;
						if (X > 0 && Y > 0 && X < TileMap->Tiles.size() && Y < TileMap->Tiles.size()) //Ÿ�� ���� �ȿ�������
						{
							MonCheaker(MoveDirection::RigntUp, X, Y - 1, AtkRange_);
							MonCheaker(MoveDirection::LeftUp, X - 1, Y, AtkRange_);
							MonCheaker(MoveDirection::RigntDown, X + 1, Y, AtkRange_);
							MonCheaker(MoveDirection::LeftDown, X, Y + 1, AtkRange_);
						}
						else if (X == 0)
						{
							MonCheaker(MoveDirection::RigntDown, X + 1, Y, AtkRange_);

							if (Y == 0)
							{
								MonCheaker(MoveDirection::LeftDown, X, Y + 1, AtkRange_);
							}
							else
							{
								MonCheaker(MoveDirection::RigntUp, X, Y - 1, AtkRange_);
							}
							if (Y == TileMap->Tiles.size())
							{
								MonCheaker(MoveDirection::RigntUp, X, Y - 1, AtkRange_);
							}
							else
							{
								MonCheaker(MoveDirection::LeftDown, X, Y + 1, AtkRange_);
							}
						}
						else if (Y == 0)
						{
							MonCheaker(MoveDirection::LeftDown, X, Y + 1, AtkRange_);
							if (X == 0)
							{
								MonCheaker(MoveDirection::RigntDown, X + 1, Y, AtkRange_);
							}
							else
							{
								MonCheaker(MoveDirection::LeftUp, X - 1, Y, AtkRange_);
							}
							if (X == TileMap->Tiles.size())
							{
								MonCheaker(MoveDirection::LeftUp, X - 1, Y, AtkRange_);
							}
							else
							{
								MonCheaker(MoveDirection::RigntDown, X + 1, Y, AtkRange_);
							}
						}
						else if (X == TileMap->Tiles.size())
						{
							MonCheaker(MoveDirection::LeftUp, X - 1, Y, AtkRange_);
							if (Y == 0)
							{
								MonCheaker(MoveDirection::LeftDown, X, Y + 1, AtkRange_);
							}
							else
							{
								MonCheaker(MoveDirection::RigntUp, X, Y - 1, AtkRange_);
							}
							if (Y == TileMap->Tiles.size())
							{
								MonCheaker(MoveDirection::RigntUp, X, Y - 1, AtkRange_);
							}
							else
							{
								MonCheaker(MoveDirection::LeftDown, X, Y + 1, AtkRange_);
							}
						}
						else if (Y == TileMap->Tiles.size())
						{
							MonCheaker(MoveDirection::RigntUp, X, Y - 1, AtkRange_);
							if (X == 0)
							{
								MonCheaker(MoveDirection::RigntDown, X + 1, Y, AtkRange_);
							}
							else
							{
								MonCheaker(MoveDirection::LeftUp, X - 1, Y, AtkRange_);
							}
							if (X == TileMap->Tiles.size())
							{
								MonCheaker(MoveDirection::LeftUp, X - 1, Y, AtkRange_);
							}
							else
							{
								MonCheaker(MoveDirection::RigntDown, X + 1, Y, AtkRange_);
							}
						}

						for (size_t y = 0; y < TileMap->Tiles.size(); y++)
						{
							for (size_t x = 0; x < TileMap->Tiles[y].size(); x++)
							{
								if (TileMap->Tiles[y][x].IsMoveOnTile == true)
								{
									TileMap->Tiles[y][x].IsMoveOnTile = false;
								}
							}
						}
						//Ŭ���� ������ ĳ���� �ű��
						float4 Pos;
						float4 Half = { 32,16,0,0 };
						Pos.x = (X * Half.x) + (Y * -Half.x);
						Pos.y = (X * -Half.y) + (Y * -Half.y) + (TileMap->Tiles[Y][X].Z * 16.0f) - 16;

						if (this->MoveCheakerStart_ == true)
						{
							UnitRenderer->GetTransform().SetWorldPosition(float4(Pos.x, Pos.y + 16.0f, -(TileMap->Tiles[Y][X].TileDepth + 1)));
						}
							

						if (EnterMon_ == true)	////////////////////////////���ݹ������� ���� ����
						{
							TileMap->Tiles[Y][X].IsMoveOnTile = true;
							//����Ŭ��
							//���� �ѹ��� Ŭ���ϸ� �̵��� ����
							//ĳ���� �ѹ� �� Ŭ���ϸ� �ؿ� �������ϱ�
							RangeCheakerStart_ = true;
						}
						else//////////////////////////////////������� ui�� ����� ���� �����ֱ�
						{
							// ���� ���ϱ�
							RangeCheakerStart_ = true;

						}
					}
				}
			}

			if (true == GameEngineInput::GetInst()->IsDown("MouseRight"))
			{
				if (RangeCheakerStart_ == true)
				{
					RangeCheakerStart_ = false;
					float4 Pos;
					float4 Half = { 32,16,0,0 };
					Pos.x = (UnitX * Half.x) + (UnitY * -Half.x);
					Pos.y = (UnitX * -Half.y) + (UnitY * -Half.y) + (UnitZ * 16.0f) - 16;
					UnitRenderer->GetTransform().SetWorldPosition(float4(Pos.x, Pos.y + 16.0f, -(TileMap->Tiles[UnitY][UnitX].TileDepth + 1)));
					TileMap->Tiles[UnitY][UnitX].IsMoveOnTile = true;
					for (size_t y = 0; y < TileMap->Tiles.size(); y++)
					{
						for (size_t x = 0; x < TileMap->Tiles[y].size(); x++)
						{
							if (TileMap->Tiles[y][x].IsAtkOnTile == true)
							{
								TileMap->Tiles[y][x].IsAtkOnTile = false;
							}
						}
					}
				}
				else
				{
					TileMap->Tiles[static_cast<size_t>(UnitY)][static_cast<size_t>(UnitX)].ClickOnUint = false;
					for (size_t y = 0; y < TileMap->Tiles.size(); y++)
					{
						for (size_t x = 0; x < TileMap->Tiles[y].size(); x++)
						{
							if (TileMap->Tiles[y][x].IsMoveOnTile == true)
							{
								TileMap->Tiles[y][x].IsMoveOnTile = false;
								MoveCheakerStart_ = false;
							}
						}
					}
				}
			}
		}
	}
}

	

void PlayUnit::End() 
{

}



void PlayUnit::SetTileRenderer(TileMapRenderer* _TileMapRenderer)
{
	TileMap = _TileMapRenderer;
}

void PlayUnit::SetUnit(int _X, int _Y, std::string _UnitName)
{
	GameEngineString::ToUpper(_UnitName);// �빮�ڷκ�ȯ�ؼ� ���ǹ� ���� üũ �ѵ� ���� ������ ����

	UnitX = static_cast<float>(_X);
	UnitY = static_cast<float>(_Y);
	UnitZ = static_cast<float>(TileMap->Tiles[_Y][_X].Z);
	if (TileMap->Tiles[_Y][_X].IsUnit != PlayUnitGroup::None)
	{
		MsgBoxAssert("��ġ�Ϸ��� �ڸ��� �̹� ���ᰡ �ֽ��ϴ�.");
		return;
	}
	if (TileMap->Tiles[_Y][_X].IsMapObject == true)
	{
		MsgBoxAssert("��ġ�Ϸ��� �ڸ��� �̹� ������Ʈ�� �ֽ��ϴ�.");
		return;
	}
	if (TileMap->Tiles[_Y][_X].IsMon != MonUnitGroup::None)
	{
		MsgBoxAssert("��ġ�Ϸ��� �ڸ��� �̹� ���Ͱ� �ֽ��ϴ�.");
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
		UnitRenderer->CreateFrameAnimationCutTexture("LeonIdleLD", FrameAnimation_DESC("LeonIdle.png", 0, 2, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("LeonIdleRU", FrameAnimation_DESC("LeonIdle.png", 3, 5, 0.2f));
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
		UnitRenderer->CreateFrameAnimationCutTexture("RalfIdleLD", FrameAnimation_DESC("RalfIdle.png", 0, 2, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("RalfIdleRU", FrameAnimation_DESC("RalfIdle.png", 3, 5, 0.2f));
		TileMap->Tiles[static_cast<size_t>(UnitY)][static_cast<size_t>(UnitX)].IsUnit = PlayUnitGroup::Ralf;
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
	else if (_UnitName == "BRIAN")
	{
		UnitRenderer->CreateFrameAnimationCutTexture("BrianIdleLD", FrameAnimation_DESC("BrianIdle.png", 0, 2, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("BrianIdleRU", FrameAnimation_DESC("BrianIdle.png", 3, 5, 0.2f));
		TileMap->Tiles[static_cast<size_t>(UnitY)][static_cast<size_t>(UnitX)].IsUnit = PlayUnitGroup::Brian;
		MaxHP_ = 34;
		Hp_ = 34;

		MaxMP_ = 10;
		Mp_ = 5;

		Atk_ = 33;
		Def_ = 19;
		Matk_ = 10;
		MDef_ = 14;
		Dex_ = 23;
		AtkRange_ = 2;
		MaxCounter_ = 6;

		Level_ = 1;
		MaxExp_ = 100;
		Exp_ = 0;
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

void PlayUnit::SetUnitMouse(MouseActor* _UnitMouse)
{
	UnitMouse = _UnitMouse;
}