#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "Enums.h"

class GameEngineTextureRenderer;
class PlayUnit : public GameEngineActor
{
public:
	PlayUnit();
	~PlayUnit();

	PlayUnit(const PlayUnit& _Other) = delete;
	PlayUnit(PlayUnit&& _Other) noexcept = delete;
	PlayUnit& operator=(const PlayUnit& _Other) = delete;
	PlayUnit& operator=(PlayUnit&& _Other) noexcept = delete;

	void SetUnit(int _X, int _Y, std::string _UnitName);
	void UnitMove(size_t _MoveConter, std::string _Direction);
	PlayUnitGroup UnitType;
	GameEngineTextureRenderer* UnitRenderer;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End();

	void IdleStart(const StateInfo& _Info);
	void IdleUpdate(float _DeltaTime, const StateInfo& _Info);
	void MoveUpdate(float _DeltaTime, const StateInfo& _Info);

private:
	GameEngineStateManager StateManager1;
	float Speed;
};