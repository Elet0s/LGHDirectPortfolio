#include "TitleLevel.h"
#include "TitleLogo.h"
#include "Enums.h"
#include "GameEngineCore/GEngine.h"

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}


void TitleLevel::Start()
{
	// GEngine::createActor
	CreateActor<TitleLogo>(GameObjectGroup::UI);
}

void TitleLevel::Update(float _DeltaTime)
{
	// 레벨 바뀌어서 오면 초기화
	// GetAccTime();

}

void TitleLevel::End()
{
	int a = 0;
}