#pragma once
#include <GameEngineCore/GameEngineGUI.h>

class TileMapActor;
class MapEditorWindow : public GameEngineGUIWindow
{
public:
	MapEditorWindow();
	~MapEditorWindow();

	MapEditorWindow(const MapEditorWindow& _Other) = delete;
	MapEditorWindow(MapEditorWindow&& _Other) noexcept = delete;
	MapEditorWindow& operator=(const MapEditorWindow& _Other) = delete;
	MapEditorWindow& operator=(MapEditorWindow&& _Other) noexcept = delete;

	TileMapActor* TileMap;
	std::string SelectFolderTexture;

	int Scale[3];
	int ZScale[1];
	size_t SelectTile;
	size_t SelectZTile;
	size_t SelectOTile;
	bool LoadCheaker;
	bool MapObjectSet;

	GameEngineTextureRenderer* Renderer;

protected:

private:
	bool ButtonCheaker;

	void Initialize(class GameEngineLevel* _Level) override;
	void OnGUI(GameEngineLevel* _Level, float _DeltaTime) override;
};