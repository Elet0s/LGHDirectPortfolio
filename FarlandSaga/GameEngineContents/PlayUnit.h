#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "Enums.h"

class MouseActor;
class GameEngineTextureRenderer;
class TileMapRenderer;
class PlayUnit : public GameEngineActor
{
public:
	PlayUnit();
	~PlayUnit();

	PlayUnit(const PlayUnit& _Other) = delete;
	PlayUnit(PlayUnit&& _Other) noexcept = delete;
	PlayUnit& operator=(const PlayUnit& _Other) = delete;
	PlayUnit& operator=(PlayUnit&& _Other) noexcept = delete;

	void SetTileRenderer(TileMapRenderer* _TileMapRenderer);
	void SetUnit(int _X, int _Y, std::string _UnitName);
	void UnitMove(size_t _MoveConter, MoveDirection _MoveDirection);
	void SetTurn(size_t _Turn);
	void SetUnitMouse(MouseActor* _UnitMouse);

	void MoveCheaker(MoveDirection _MoveDirection, float _X, float _Y, int _MoveCount);
	void MonCheaker(MoveDirection _CheakDirection, float _X, float _Y, int _AtkRange);

	PlayUnitGroup UnitType;
	GameEngineTextureRenderer* UnitRenderer;
	TileMapRenderer* TileMap;
	MouseActor* UnitMouse;

	float UnitX;
	float UnitY;
	float UnitZ;

	IdleDirection IdleDirection_;
	size_t Turn_;
	bool MoveCheakerStart_;
	bool RangeCheakerStart_;
	bool EnterMon_;
	///  ����

	size_t MaxHP_;
	size_t Hp_;

	size_t MaxMP_;
	size_t Mp_;

	size_t Atk_;
	size_t Def_;
	size_t Matk_;
	size_t MDef_;
	size_t Dex_;

	size_t AtkRange_;
	int MoveCount_;
	int MaxCounter_;

	size_t Level_;
	size_t MaxExp_;
	size_t Exp_;

	/// �Ӽ�
	size_t Fire_;
	size_t Water_;
	size_t Earth_;
	size_t Wind_;
	size_t Dark_;
	size_t Light_;

	///  ����
	size_t Strength_;
	size_t Detect_;
	size_t Intelligence_;
	size_t Reflection_;
	size_t Heyste_;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End();

private:

	GameEngineStateManager StateManager1;
	float Speed;

};