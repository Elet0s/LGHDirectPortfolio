#include "PreCompile.h"
#include "TitleLevel.h"
#include "TitleLogo.h"
#include "SoundPlayer.h"
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
	if (true == GameEngineInput::GetInst()->IsDown("NextLevel"))
	{
		GEngine::ChangeLevel("Event01");
	}

	// ���� �ٲ� ���� �ʱ�ȭ
	// GetAccTime();

}

void TitleLevel::End()
{
}