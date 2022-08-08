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
	CreateActor<MyDialogBox>(GameObjectGroup::UI);
}
void Event01::Update(float _DeltaTime)
{

}
void Event01::End()
{

}