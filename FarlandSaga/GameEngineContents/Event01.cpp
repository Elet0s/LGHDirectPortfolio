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
	{
		NewMyDialogBox = CreateActor<MyDialogBox>(GameObjectGroup::UI);
		NewMyDialogBox->SetDialogLevel(10);
	}
}
void Event01::Update(float _DeltaTime)
{
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