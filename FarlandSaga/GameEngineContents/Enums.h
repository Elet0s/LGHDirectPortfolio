#pragma once

enum class GameObjectGroup
{
	BG,
	Player,
	Monster,
	UI,
};

enum class TileObject
{
	None,
	Block,
	AniBLock,
	PlayUnit,
	MonUnit,
	Item
};

enum class PlayUnitGroup
{
	None,
	Leon,
	Ralf,
	Brian,
	TT,
	Mascia,
	farm,
	Karin,
	Rian,
	Ophelia
};

enum class MonUnitGroup
{
	None,
	Goblin,
	Wolf,
};

enum class MoveDirection
{
	RigntUp,
	LeftUp,
	RigntDown,
	LeftDown
};

enum class IdleDirection
{
	RigntUp,
	LeftUp,
	RigntDown,
	LeftDown
};

enum class Conditions
{
	None,
	Faint,
	Sleep,
	Silence,
	Poison,
	Freezing,
	Paralysis,
	Fascination,
	petrification,
	Restraint
};