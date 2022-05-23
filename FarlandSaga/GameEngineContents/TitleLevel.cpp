#include "TitleLevel.h"
#include "TitleLogo.h"
#include "Enums.h"

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}


void TitleLevel::UserStart()
{
	CreateActor<TitleLogo>(GameObjectGroup::UI);

	//GameEngineTime::GetInst()->SetTimeScale(GameObjectGroup::Monster, 0.5f);
}

void TitleLevel::UserUpdate(float _DeltaTime)
{
	// 레벨 바뀌어서 오면 초기화
	// GetAccTime();

}

void TitleLevel::UserEnd()
{
	int a = 0;
}