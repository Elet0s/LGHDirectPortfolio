#include "PreCompile.h"
#include "TitleLevel.h"
#include "TitleLogo.h"
#include "Enums.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}


void TitleLevel::Start()
{
	CreateActor<TitleLogo>(GameObjectGroup::UI);
}

void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
	{
		GEngine::ChangeLevel("Stage01");
	}

	// 레벨 바뀌어서 오면 초기화
	// GetAccTime();

}

void TitleLevel::End()
{
}