#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class Stage01 : public GameEngineLevel
{
public:
	Stage01();
	~Stage01();

	Stage01(const Stage01& _Other) = delete;
	Stage01(Stage01&& _Other) noexcept = delete;
	Stage01& operator=(const Stage01& _Other) = delete;
	Stage01& operator=(Stage01&& _Other) noexcept = delete;

	TileMapActor* S01TileMap;

	std::string StageName;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
	void LevelStartEvent() override;
	void LevelEndEvent()	override;
private:
	POINT ptMouse1;
	POINT ptMouse2;
	POINT ptMouse3;
};

