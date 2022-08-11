#include "PreCompile.h"
#include "MapEditorLevel.h"
#include "Enums.h"
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>
#include "TileMapActor.h"
#include "MapEditorWindow.h"

MapEditorLevel::MapEditorLevel()
{
}

MapEditorLevel::~MapEditorLevel()
{
}


void MapEditorLevel::Start()
{
	{
		TileMapActor* actor = CreateActor<TileMapActor>(OBJECTORDER::TileMap);
	}

}

void MapEditorLevel::OnEvent()
{
	// 2번 로딩 안되도록
	if (nullptr == GameEngineTexture::Find("PivotTile.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Map");

		std::vector<GameEngineFile> Ress = Dir.GetAllFile();

		for (size_t i = 0; i < Ress.size(); i++)
		{
			GameEngineTexture::Load(Ress[i].GetFullPath());
		}

		{
			GameEngineGUI::CreateGUIWindow<MapEditorWindow>("MapEditorGui", this);
		}
	}
}

void MapEditorLevel::Update(float _DeltaTime)
{
	// 그림하나 띄우려고 액터 하나 만드는 건 너무나도 귀찮은 일이기 때문에 만들어 봤습니다.
	GameEngineDebug::DrawTexture("PivotTile.png", { 0,0,0,1 }, { 0,0,0 });
}

void MapEditorLevel::End()
{
}