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

	MouseActor* NewMouseActor;
	std::string StageName;

	bool MainCameraSet;
	size_t Turn;


	std::vector<PlayUnit*> PlayGroup;
	std::vector<MonUnit*> MonGroup;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
	void LevelStartEvent() override;
	void LevelEndEvent()	override;
private:
};

