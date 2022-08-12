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
		TileMap = CreateActor<TileMapActor>(OBJECTORDER::TileMap);
	}
	if (false == GameEngineInput::GetInst()->IsKey("MouseLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("MouseLeft", VK_LBUTTON);
	}
}

void MapEditorLevel::OnEvent()
{
	// 2�� �ε� �ȵǵ���
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

void MapEditorLevel::Update(float _DeltaTime)
{
	// �׸��ϳ� ������ ���� �ϳ� ����� �� �ʹ����� ������ ���̱� ������ ����� �ý��ϴ�.
	GameEngineDebug::DrawTexture("PivotTile.png", { 0,0,0,1 }, { 0,0,0 });

	//////// ���콺�巡�� �� �̵��ϴ� ��� ///////////
	{
		if (true == GameEngineInput::GetInst()->IsDown("MouseLeft"))
		{
			GetCursorPos(&ptMouse1);
			ScreenToClient(GameEngineWindow::GetHWND(), &ptMouse1);
		}
		if (true == GameEngineInput::GetInst()->IsPress("MouseLeft"))
		{
			GetCursorPos(&ptMouse2);
			ScreenToClient(GameEngineWindow::GetHWND(), &ptMouse2);
			//SetCursorPos(ptMouse1.x, ptMouse1.y);
		}
		ptMouse3.x = ptMouse2.x - ptMouse1.x;
		ptMouse3.y = ptMouse2.y - ptMouse1.y;

		if (ptMouse3.x > 0)
		{
			GetMainCameraActorTransform().SetLocalMove(-GetMainCameraActorTransform().GetRightVector() * ptMouse3.x);
			ptMouse3.x = 0;
			ptMouse1.x = ptMouse2.x;
		}
		else if (ptMouse3.x < 0)
		{
			GetMainCameraActorTransform().SetLocalMove(GetMainCameraActorTransform().GetRightVector() * -ptMouse3.x);
			ptMouse3.x = 0;
			ptMouse1.x = ptMouse2.x;

		}

		if (ptMouse3.y > 0)
		{
			GetMainCameraActorTransform().SetLocalMove(GetMainCameraActorTransform().GetUpVector() * ptMouse3.y);
			ptMouse3.y = 0;
			ptMouse1.y = ptMouse2.y;
		}
		else if (ptMouse3.y < 0)
		{
			GetMainCameraActorTransform().SetLocalMove(-GetMainCameraActorTransform().GetUpVector() * -ptMouse3.y);
			ptMouse3.y = 0;
			ptMouse1.y = ptMouse2.y;
		}
	}

}

void MapEditorLevel::End()
{
}