#include "PreCompile.h"
#include "MapEditorLevel.h"
#include "Enums.h"
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>
#include "TileMapActor.h"


MapEditorLevel::MapEditorLevel()
	:TileMap()
	, ptMouse1()
	, ptMouse2()
	, ptMouse3()
{
}

MapEditorLevel::~MapEditorLevel()
{
}


void MapEditorLevel::Start()
{
	{
		TileMap = CreateActor<TileMapActor>(OBJECTORDER::TileMap);
	}
	if (false == GameEngineInput::GetInst()->IsKey("MouseRight"))
	{
		GameEngineInput::GetInst()->CreateKey("MouseRight", VK_RBUTTON);
	}
}
void MapEditorLevel::End()
{
}
void MapEditorLevel::LevelStartEvent()
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
			MapEditorWindow* TileMapEditorGUI = GameEngineGUI::CreateGUIWindow<MapEditorWindow>("MapEditorGui", this);
			TileMapEditorGUI->TileMap = TileMap;
		}
	}
}
void MapEditorLevel::LevelEndEvent()
{
}
void MapEditorLevel::Update(float _DeltaTime)
{
	// 그림하나 띄우려고 액터 하나 만드는 건 너무나도 귀찮은 일이기 때문에 만들어 봤습니다.
	//GameEngineDebug::DrawTexture("PivotTile.png", { 0,0-10,1 }, { 0,0,0 });

	//////// 마우스드래그 맵 이동하는 기능 ///////////
	{
		if (true == GameEngineInput::GetInst()->IsDown("MouseRight"))
		{
			GetCursorPos(&ptMouse1);
			ScreenToClient(GameEngineWindow::GetHWND(), &ptMouse1);
		}
		if (true == GameEngineInput::GetInst()->IsPress("MouseRight"))
		{
			GetCursorPos(&ptMouse2);
			ScreenToClient(GameEngineWindow::GetHWND(), &ptMouse2);
			//SetCursorPos(ptMouse1.x, ptMouse1.y);
		}
		ptMouse3.x = ptMouse2.x - ptMouse1.x;
		ptMouse3.y = ptMouse2.y - ptMouse1.y;

		if (ptMouse3.x > 0)
		{
			GetMainCameraActorTransform().SetLocalMove(-GetMainCameraActorTransform().GetRightVector() * static_cast<float>(ptMouse3.x));
			ptMouse3.x = 0;
			ptMouse1.x = ptMouse2.x;
		}
		else if (ptMouse3.x < 0)
		{
			GetMainCameraActorTransform().SetLocalMove(GetMainCameraActorTransform().GetRightVector() * static_cast<float>( - ptMouse3.x));
			ptMouse3.x = 0;
			ptMouse1.x = ptMouse2.x;

		}

		if (ptMouse3.y > 0)
		{
			GetMainCameraActorTransform().SetLocalMove(GetMainCameraActorTransform().GetUpVector() * static_cast<float>(ptMouse3.y));
			ptMouse3.y = 0;
			ptMouse1.y = ptMouse2.y;
		}
		else if (ptMouse3.y < 0)
		{
			GetMainCameraActorTransform().SetLocalMove(-GetMainCameraActorTransform().GetUpVector() * static_cast<float>( - ptMouse3.y));
			ptMouse3.y = 0;
			ptMouse1.y = ptMouse2.y;
		}
	}

}



