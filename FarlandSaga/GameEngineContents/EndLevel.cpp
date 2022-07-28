#include "PreCompile.h"
#include"EndLevel.h"
#include"Flower.h"
#include"EndingBG.h"

EndLevel::EndLevel()
{

}
EndLevel::~EndLevel()
{

}

void EndLevel::Start()
{
	CreateActor<EndingBG>(GameObjectGroup::BG);
	CreateActor<Flower>(GameObjectGroup::UI);
}
void EndLevel::Update(float _DeltaTime)
{

}
void EndLevel::End()
{

}