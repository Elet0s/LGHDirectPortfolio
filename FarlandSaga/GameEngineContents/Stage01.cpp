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
		S01TileMap->TileRenderer->CreateIsometricTileMap(50, 50, 0, { 64, 32 }, StageName, 16);
		S01TileMap->TileRenderer->Load(StageName);


	}
	/////////////////////////마우스 로드///////////////////////////
	{
		NewMouseActor = CreateActor<MouseActor>(OBJECTORDER::UI);
		NewMouseActor->SetTileRenderer(S01TileMap->TileRenderer);
		NewMouseActor->Level = this;
	}

	/////////////////////////플레이어 유닛 로드///////////////////////////
	{
		PlayUnit* UnitLEON = CreateActor<PlayUnit>(OBJECTORDER::Player);
		UnitLEON->SetTileRenderer(S01TileMap->TileRenderer);
		UnitLEON->SetTurn(Turn);
		UnitLEON->SetUnit(41, 24, "LEON");
		UnitLEON->SetUnitMouse(NewMouseActor);
		PlayGroup.push_back(UnitLEON);
	}
	{
		PlayUnit* UnitRALF = CreateActor<PlayUnit>(OBJECTORDER::Player);
		UnitRALF->SetTileRenderer(S01TileMap->TileRenderer);
		UnitRALF->SetTurn(Turn);
		UnitRALF->SetUnit(41, 23, "RALF");
		UnitRALF->SetUnitMouse(NewMouseActor);
		PlayGroup.push_back(UnitRALF);
	}
	{
		PlayUnit* UnitBRIAN = CreateActor<PlayUnit>(OBJECTORDER::Player);
		UnitBRIAN->SetTileRenderer(S01TileMap->TileRenderer);
		UnitBRIAN->SetTurn(Turn);
		UnitBRIAN->SetUnit(41, 22, "BRIAN");
		UnitBRIAN->SetUnitMouse(NewMouseActor);
		PlayGroup.push_back(UnitBRIAN);
	}
	/////////////////////////몬스터 유닛 로드///////////////////////////
	{
		MonUnit* Goblin1 = CreateActor<MonUnit>(OBJECTORDER::Monster);
		Goblin1->SetTileRenderer(S01TileMap->TileRenderer);
		Goblin1->SetTurn(Turn);
		Goblin1->SetUnit(35, 24, "GOBLIN");
		MonGroup.push_back(Goblin1);
	}
	{
		MonUnit* Goblin2 = CreateActor<MonUnit>(OBJECTORDER::Monster);
		Goblin2->SetTileRenderer(S01TileMap->TileRenderer);
		Goblin2->SetTurn(Turn);
		Goblin2->SetUnit(25, 20, "GOBLIN");
		MonGroup.push_back(Goblin2);
	}
	{
		MonUnit* Goblin3 = CreateActor<MonUnit>(OBJECTORDER::Monster);
		Goblin3->SetTileRenderer(S01TileMap->TileRenderer);
		Goblin3->SetTurn(Turn);
		Goblin3->SetUnit(22, 30, "GOBLIN");
		MonGroup.push_back(Goblin3);
	}
	{
		MonUnit* Goblin4 = CreateActor<MonUnit>(OBJECTORDER::Monster);
		Goblin4->SetTileRenderer(S01TileMap->TileRenderer);
		Goblin4->SetTurn(Turn);
		Goblin4->SetUnit(30, 25, "GOBLIN");
		MonGroup.push_back(Goblin4);
	}
	{
		MonUnit* Goblin5 = CreateActor<MonUnit>(OBJECTORDER::Monster);
		Goblin5->SetTileRenderer(S01TileMap->TileRenderer);
		Goblin5->SetTurn(Turn);
		Goblin5->SetUnit(15, 15, "GOBLIN");
		MonGroup.push_back(Goblin5);
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
		this->GetMainCameraActorTransform().SetWorldPosition(float4(280, -770, -100, 1));
		MainCameraSet = true;
	}
	if (this->GetMainCameraActorTransform().GetWorldPosition().PosX >280)
	{
		this->GetMainCameraActorTransform().SetWorldPosition({ 280 ,this->GetMainCameraActorTransform().GetWorldPosition().PosY,-100,1});
	}
	if (this->GetMainCameraActorTransform().GetWorldPosition().PosX < 70)
	{
		this->GetMainCameraActorTransform().SetWorldPosition({ 70 ,this->GetMainCameraActorTransform().GetWorldPosition().PosY,-100,1 });
	}
	if (this->GetMainCameraActorTransform().GetWorldPosition().PosY > -760)
	{
		this->GetMainCameraActorTransform().SetWorldPosition({ this->GetMainCameraActorTransform().GetWorldPosition().PosX ,-760,-100,1 });
	}
	if (this->GetMainCameraActorTransform().GetWorldPosition().PosY < -770)
	{
		this->GetMainCameraActorTransform().SetWorldPosition({ this->GetMainCameraActorTransform().GetWorldPosition().PosX ,-770,-100,1 });
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
