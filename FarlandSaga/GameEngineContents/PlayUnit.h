#pragma once
#include"GameEngineCore/GameEngineActor.h"

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
private:

};