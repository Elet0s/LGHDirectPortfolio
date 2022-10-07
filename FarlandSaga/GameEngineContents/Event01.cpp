#include "PreCompile.h"
#include"Event01.h"
#include"MyDialogBox.h"

Event01::Event01()
{

}
Event01::~Event01()
{

}

void Event01::Start()
{
	/////////////////////////≈∏¿œ∏  ∑ŒµÂ///////////////////////////
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("Map");
		Dir.Move("Event01");

		std::string Path = Dir.GetFullPath();

		if (false == Path.empty())
		{
			StageName = GameEnginePath::GetFileName(Path);

			GameEngineFolderTexture::Load(Path.c_str());
		}
	}

	{
		E01TileMap = CreateActor<TileMapActor>(OBJECTORDER::TileMap);
		E01TileMap->TileRenderer->CreateIsometricTileMap(50, 50, 0, { 64, 32 }, StageName, 16);
		E01TileMap->TileRenderer->Load(StageName);

	}

	{
		NewMouseActor = CreateActor<MouseActor>(OBJECTORDER::UI);
		NewMouseActor->SetTileRenderer(E01TileMap->TileRenderer);
		NewMouseActor->Level = this;
	}
	{
		PlayUnit* UnitLEON = CreateActor<PlayUnit>(OBJECTORDER::Player);
		UnitLEON->SetTileRenderer(E01TileMap->TileRenderer);
		UnitLEON->SetUnit(23, 20, "LEON");
		UnitLEON->IdleDirection_ = IdleDirection::LeftDown;
		UnitLEON->SetUnitMouse(NewMouseActor);
	}
	{
		PlayUnit* UnitRALF = CreateActor<PlayUnit>(OBJECTORDER::Player);
		UnitRALF->SetTileRenderer(E01TileMap->TileRenderer);
		UnitRALF->SetUnit(26, 24, "RALF");
		UnitRALF->IdleDirection_ = IdleDirection::RigntUp;
		UnitRALF->SetUnitMouse(NewMouseActor);


	}
	{
		PlayUnit* UnitBRIAN = CreateActor<PlayUnit>(OBJECTORDER::Player);
		UnitBRIAN->SetTileRenderer(E01TileMap->TileRenderer);
		UnitBRIAN->SetUnit(26, 41, "BRIAN");
		UnitBRIAN->IdleDirection_ = IdleDirection::LeftDown;
		UnitBRIAN->SetUnitMouse(NewMouseActor);

	}
	{
		NewMyDialogBox = CreateActor<MyDialogBox>(OBJECTORDER::UI);
		NewMyDialogBox->SetDialogLevel(10);
	}
}
void Event01::Update(float _DeltaTime)
{
	if (MainCameraSet == false)
	{
		this->GetMainCameraActorTransform().SetWorldPosition(float4(-130, -770, -100, 1));
		MainCameraSet = true;
	}
	if (this->GetMainCameraActorTransform().GetWorldPosition().PosX > 280)
	{
		this->GetMainCameraActorTransform().SetWorldPosition({ 280 ,this->GetMainCameraActorTransform().GetWorldPosition().PosY,-100,1 });
	}
	if (this->GetMainCameraActorTransform().GetWorldPosition().PosX < -130)
	{
		this->GetMainCameraActorTransform().SetWorldPosition({ -130 ,this->GetMainCameraActorTransform().GetWorldPosition().PosY,-100,1 });
	}
	if (this->GetMainCameraActorTransform().GetWorldPosition().PosY > -760)
	{
		this->GetMainCameraActorTransform().SetWorldPosition({ this->GetMainCameraActorTransform().GetWorldPosition().PosX ,-760,-100,1 });
	}
	if (this->GetMainCameraActorTransform().GetWorldPosition().PosY < -780)
	{
		this->GetMainCameraActorTransform().SetWorldPosition({ this->GetMainCameraActorTransform().GetWorldPosition().PosX ,-780,-100,1 });
	}

	if (NewMyDialogBox->DialogEnd() == true)
	{
		if (NewMyDialogBox->DialogLevel_ == 10)
		{
			NewMyDialogBox->SetDialogLevel(11);
			NewMyDialogBox->DialogEnd_ = false;
		}
		else if (NewMyDialogBox->DialogLevel_ == 11)
		{
			NewMyDialogBox->SetDialogLevel(12);
			NewMyDialogBox->DialogEnd_ = false;
		}
		else if (NewMyDialogBox->DialogLevel_ == 12)
		{
			NewMyDialogBox->SetDialogLevel(13);
			NewMyDialogBox->DialogEnd_ = false;
		}
		else if (NewMyDialogBox->DialogLevel_ == 13)
		{
			NewMyDialogBox->SetDialogLevel(14);
			NewMyDialogBox->DialogEnd_ = false;
		}
	}	
	if (true == GameEngineInput::GetInst()->IsDown("NextLevel"))
	{
		GEngine::ChangeLevel("Stage01");
	}
}


void Event01::End()
{

}