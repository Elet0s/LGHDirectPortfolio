#include "PreCompile.h"
#include"MyDialogBox.h"

MyDialogBox::MyDialogBox()
{

}
MyDialogBox::~MyDialogBox()
{

}
void MyDialogBox::Start()
{

	GetTransform().SetLocalPosition({ 0, 240, 1 });

	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 921, 210, 0 });
		Renderer->SetTexture("DialogBox.png");
	}

	{
		GameEngineFontRenderer* Font = CreateComponent<GameEngineFontRenderer>();
		Font->SetText("·¹¿Â", "±Ã¼­");
		Font->SetColor({ 1.0f, 1.0f, 0.0f });
		Font->SetScreenPostion({ 400.0f, 70.0f });
	}
	{
		GameEngineFontRenderer* Font = CreateComponent<GameEngineFontRenderer>();
		Font->SetText("[¸¹ÀÌ ±â´Ù·ÈÁö!]", "±Ã¼­");
		Font->SetColor({ 1.0f, 1.0f, 1.0f });
		Font->SetScreenPostion({ 400.0f, 100.0f });
	}
}