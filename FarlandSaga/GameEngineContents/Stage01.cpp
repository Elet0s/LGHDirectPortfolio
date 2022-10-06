#include "PreCompile.h"
#include"Stage01.h"
#include "GlobalContentsValue.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>
#include "UIMaster.h"
#include "TestStageBG.h"
#include <GameEngineCore/GEngine.h>
#include "GameEngineBase/GameEngineSound.h"
#include "SoundPlayer.h"
#include"MapEditorLevel.h"

Stage01::Stage01()
	:S01TileMap()
	, StageName()
	,NewMouseActor()
	, MainCameraSet(false)
	,Turn(1)
{
}

Stage01::~Stage01()
{
}

void Stage01::Start()
{
	/////////////////////////타일맵 로드///////////////////////////
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
	{
		S01TileMap = CreateActor<TileMapActor>(OBJECTORDER::TileMap);
		S01TileMap->TileRenderer->CreateIsometricTileMap(30, 30, 0, { 64, 32 }, StageName, 16);
		S01TileMap->TileRenderer->Load(StageName);
		GetMainCameraActorTransform().SetWorldPosition({ 0.0f,-0.0f,0.0f,0.0f });
		//CreateActor<TestStageBG>(OBJECTORDER::BG);//배경 이미지
	}

	/////////////////////////플레이어 유닛 로드///////////////////////////
	{
		PlayUnit* UnitLEON = CreateActor<PlayUnit>(OBJECTORDER::Player);
		UnitLEON->SetTileRenderer(S01TileMap->TileRenderer);
		UnitLEON->SetTurn(Turn);
		UnitLEON->SetUnit(1, 0, "LEON");
		PlayGroup.push_back(UnitLEON);
	}
	/////////////////////////몬스터 유닛 로드///////////////////////////
	{
		MonUnit* Goblin1 = CreateActor<MonUnit>(OBJECTORDER::Monster);
		Goblin1->SetTileRenderer(S01TileMap->TileRenderer);
		Goblin1->SetTurn(Turn);
		Goblin1->SetUnit(2, 0, "GOBLIN");
		MonGroup.push_back(Goblin1);
	}

	/////////////////////////마우스 로드///////////////////////////
	{
		NewMouseActor = CreateActor<MouseActor>(OBJECTORDER::UI);
		NewMouseActor->SetTileRenderer(S01TileMap->TileRenderer);
		NewMouseActor->Level = this;
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
	if (MainCameraSet==false)
	{
		this->GetMainCameraActorTransform().SetWorldPosition(float4(0, 0, -100, 1));
		MainCameraSet = true;
	}

	GameEngineStatusWindow::AddDebugRenderTarget("BackBuffer", GameEngineDevice::GetBackBuffer());
	GameEngineStatusWindow::AddDebugRenderTarget("MainCamera", GetMainCamera()->GetCameraRenderTarget());
	GameEngineStatusWindow::AddDebugRenderTarget("UICamera", GetUICamera()->GetCameraRenderTarget());

	if (true == GameEngineInput::GetInst()->IsDown("NextLevel"))
	{
		GEngine::ChangeLevel("Event02");
	}

}
void Stage01::End() 
{
}
