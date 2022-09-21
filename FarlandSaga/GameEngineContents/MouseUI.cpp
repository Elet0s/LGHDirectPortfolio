
#include "PreCompile.h"
#include"MouseUI.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

MouseUI::MouseUI()
	:Renderer(nullptr),
	 ptMouse1(),
	ptMouse2(),
	ptMouse3(),
	Level(),
	MousePosition()
{

}
MouseUI::~MouseUI()
{

}

void MouseUI::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("MouseLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("MouseLeft", VK_LBUTTON);
	}
	if (false == GameEngineInput::GetInst()->IsKey("MouseLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("MouseRight", VK_RBUTTON);
	}

	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->GetTransform().SetLocalScale({ 64.0f, 32.0f, 0.0f });
	Renderer->SetTexture("ST01.png");
}
void MouseUI::Update(float _DeltaTime)
{

	{
		float4 MousePos = Level->GetMainCamera()->GetMouseWorldPositionToActor();

		MX = roundf((MousePos.x / 32.0f + MousePos.y / -16.0f) / 2.0f);
		MY = roundf((MousePos.y / -16.0f - MousePos.x / 32.0f) / 2.0f);

		float XX = (MX * 32) + (MY * -32);
		float YY = (MX * -16) + (MY * -16);
		Renderer->GetTransform().SetWorldPosition({ XX, YY,-99.0f,0.0f });
		//int a = 0;
	}


	//////// 마우스드래그 이동하는 기능 ///////////
	{
		if (true == GameEngineInput::GetInst()->IsDown("MouseLeft"))
		{
			GetCursorPos(&ptMouse1);
			ScreenToClient(GameEngineWindow::GetHWND(), &ptMouse1);
		}
		if (true == GameEngineInput::GetInst()->IsPress("MouseLeft"))
		{
			GetCursorPos(&ptMouse2);
			ScreenToClient(GameEngineWindow::GetHWND(), &ptMouse2);
			//SetCursorPos(ptMouse1.x, ptMouse1.y);
		}
		ptMouse3.x = ptMouse2.x - ptMouse1.x;
		ptMouse3.y = ptMouse2.y - ptMouse1.y;

		if (ptMouse3.x > 0)
		{
			Level->GetMainCameraActorTransform().SetLocalMove(-Level->GetMainCameraActorTransform().GetRightVector() * static_cast<float>(ptMouse3.x));
			ptMouse3.x = 0;
			ptMouse1.x = ptMouse2.x;
		}
		else if (ptMouse3.x < 0)
		{
			Level->GetMainCameraActorTransform().SetLocalMove(Level->GetMainCameraActorTransform().GetRightVector() * static_cast<float>(-ptMouse3.x));
			ptMouse3.x = 0;
			ptMouse1.x = ptMouse2.x;
		}

		if (ptMouse3.y > 0)
		{
			Level->GetMainCameraActorTransform().SetLocalMove(Level->GetMainCameraActorTransform().GetUpVector() * static_cast<float>(ptMouse3.y));
			ptMouse3.y = 0;
			ptMouse1.y = ptMouse2.y;
		}
		else if (ptMouse3.y < 0)
		{
			Level->GetMainCameraActorTransform().SetLocalMove(-Level->GetMainCameraActorTransform().GetUpVector() * static_cast<float>(-ptMouse3.y));
			ptMouse3.y = 0;
			ptMouse1.y = ptMouse2.y;
		}
	}
}
void MouseUI::End()
{

}