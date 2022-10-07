#include "PreCompile.h"
#include "TitleLevel.h"
#include "TitleLogo.h"
#include"TitleMainUi.h"
#include "SoundPlayer.h"
#include "Enums.h"
#include"UIMaster.h"
#include "MouseActor.h"
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
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("UI");
		Dir.Move("Title");
		std::vector<GameEngineFile> Shaders = Dir.GetAllFile();
		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineTexture::Load(Shaders[i].GetFullPath());
		}
	}
	CreateActor<TitleLogo>(GameObjectGroup::BG);
	CreateActor < TitleMainUi>(GameObjectGroup::UI); 
	TitleMouse= CreateActor<MouseActor>(GameObjectGroup::UI);
	TitleMouse->Level = this;
}

void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::GetInst()->IsDown("NextLevel"))
	{
		GEngine::ChangeLevel("Event01");
	}

	// 레벨 바뀌어서 오면 초기화
	// GetAccTime();

}

void TitleLevel::End()
{
}