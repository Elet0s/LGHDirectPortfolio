#pragma once
#include "Player.h"
#include "Monster.h"

enum class OBJECTORDER
{
	TileMap,
	Player,
	Monster,
	UI = 1000,
	BG
};

//enum class COLLISIONORDER
//{
//	Player,
//	Monster,
//	UI = 1000,
//};

class GlobalContentsValue
{
public:
	class Enums
	{
	};

	class Actors
	{
	public:
		static Monster* TestMonster;

	private:
		Actors() {		}
		~Actors() {		}
	};

private:
	GlobalContentsValue() {	}

	~GlobalContentsValue() {	}
};

