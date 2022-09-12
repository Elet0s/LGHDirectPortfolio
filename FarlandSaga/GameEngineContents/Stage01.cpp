#include "PreCompile.h"
#include"Stage01.h"
#include "GlobalContentsValue.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>
#include "Monster.h"
#include "Player.h"
#include "UIMaster.h"
#include "TestStageBG.h"
#include <GameEngineCore/GEngine.h>
#include "GameEngineBase/GameEngineSound.h"
#include "SoundPlayer.h"
#include"MapEditorLevel.h"
#include"SelectTileUi.h"


Stage01::Stage01()
	:ptMouse1(),
	ptMouse2(),
	ptMouse3()
{
}

Stage01::~Stage01()
{
}

void Stage01::Start()
{
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Map");
		Dir.Move("Stage01");

		std::string Path = Dir.GetFullPath();

		if (false == Path.empty())
		{
			StageName = GameEnginePath::GetFileName(Path);
		
			GameEngineFolderTexture::Load(Path.c_str());
		}
	}

	S01TileMap = CreateActor<TileMapActor>(OBJECTORDER::TileMap);
	S01TileMap->TileRenderer->CreateIsometricTileMap(30,30,0,  { 64, 32 }, StageName, 16);
	S01TileMap->TileRenderer->Load(StageName);

	//CreateActor<TestStageBG>(OBJECTORDER::BG);//배경 이미지

	if (false == GameEngineInput::GetInst()->IsKey("MouseLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("MouseLeft", VK_LBUTTON);
	}

	{
		Player* NewPlayer = CreateActor<Player>(OBJECTORDER::Player);
	}
	{
		Monster* NewMonster = CreateActor<Monster>(OBJECTORDER::Monster);
	}
	{
		UIMaster* NewUI = CreateActor<UIMaster>(OBJECTORDER::UI);
	}
	{
		SelectTileUi* NewTileUi = CreateActor<SelectTileUi>(OBJECTORDER::UI);
	}
	{
		//Monster* actor = CreateActor<Monster>(OBJECTORDER::Monster);
		//actor->GetTransform().SetLocalPosition({ 300.0f, 0.0f, 0.0f });
		//actor->GetTransform().SetWorldScale(float4(1.0f, 1.0f, 1.0f));
	}

}

void Stage01::LevelStartEvent()
{
	SoundPlayer::BGMPlay_->ChangeBgm("BGM01.MID", 1);

}

void Stage01::LevelEndEvent()
{
	SoundPlayer::BGMPlay_->Stop();
}

void Stage01::Update(float _DeltaTime)
{
	GameEngineStatusWindow::AddDebugRenderTarget("BackBuffer", GameEngineDevice::GetBackBuffer());
	GameEngineStatusWindow::AddDebugRenderTarget("MainCamera", GetMainCamera()->GetCameraRenderTarget());
	GameEngineStatusWindow::AddDebugRenderTarget("UICamera", GetUICamera()->GetCameraRenderTarget());

	//////// 마우스드래그 맵 이동하는 기능 ///////////
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

	if (true == GameEngineInput::GetInst()->IsDown("NextLevel"))
	{
		GEngine::ChangeLevel("Event02");
	}

}
void Stage01::End() 
{
}
