#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class MapEditorLevel : public GameEngineLevel
{
public:
	MapEditorLevel();
	~MapEditorLevel();

	MapEditorLevel(const MapEditorLevel& _Other) = delete;
	MapEditorLevel(MapEditorLevel&& _Other) noexcept = delete;
	MapEditorLevel& operator=(const MapEditorLevel& _Other) = delete;
	MapEditorLevel& operator=(MapEditorLevel&& _Other) noexcept = delete;

	TileMapActor* TileMap;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	void OnEvent() override;

	POINT ptMouse1;
	POINT ptMouse2;
	POINT ptMouse3;

};

