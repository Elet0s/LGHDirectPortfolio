
#include "PreCompile.h"
#include "PlayLevel.h"
#include "GlobalContentsValue.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>
#include "Player.h"
#include "Monster.h"
#include <Windows.h>

PlayLevel::PlayLevel()
	:ptMouse1(),
	ptMouse2(),
	ptMouse3()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("CamLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("CamLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("CamRight", 'D');
		GameEngineInput::GetInst()->CreateKey("CamUp", 'Q');
		GameEngineInput::GetInst()->CreateKey("CamDown", 'E');
		GameEngineInput::GetInst()->CreateKey("CamForward", 'W');
		GameEngineInput::GetInst()->CreateKey("CamBack", 'S');

		GameEngineInput::GetInst()->CreateKey("MouseLeft", VK_LBUTTON);

	}



	{
		GameEngineCameraActor* actor = CreateActor<GameEngineCameraActor>();
		actor->GetCameraComponent()->SetProjectionMode(CAMERAPROJECTIONMODE::Orthographic);
		actor->GetTransform().SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	}


	Player* NewPlayer;

	{
		NewPlayer = CreateActor<Player>(OBJECTORDER::Player);
	}

	{
		Monster* actor = CreateActor<Monster>(OBJECTORDER::Monster);
		actor->GetTransform().SetLocalPosition({ 300.0f, 0.0f, 0.0f });
		actor->GetTransform().SetWorldScale(float4(50.0f, 50.f, 50.0f));
		actor->SetParent(NewPlayer);
	}


}
void PlayLevel::Update(float _DeltaTime)
{


	if (true == GameEngineInput::GetInst()->IsPress("CamLeft"))
	{
		GetMainCameraActorTransform().SetLocalMove(-GetMainCameraActorTransform().GetRightVector() * 100 * _DeltaTime);
	}

	if (true == GameEngineInput::GetInst()->IsPress("CamRight"))
	{
		GetMainCameraActorTransform().SetLocalMove(GetMainCameraActorTransform().GetRightVector() * 100 * _DeltaTime);
	}
	if (true == GameEngineInput::GetInst()->IsPress("CamUp"))
	{
		GetMainCameraActorTransform().SetLocalMove(GetMainCameraActorTransform().GetUpVector() * 100 * _DeltaTime);
	}
	if (true == GameEngineInput::GetInst()->IsPress("CamDown"))
	{
		GetMainCameraActorTransform().SetLocalMove(-GetMainCameraActorTransform().GetUpVector() * 100 * _DeltaTime);
	}

	if (true == GameEngineInput::GetInst()->IsPress("CamForward"))
	{
		GetMainCameraActorTransform().SetLocalMove(GetMainCameraActorTransform().GetForwardVector() * 100 * _DeltaTime);
	}
	if (true == GameEngineInput::GetInst()->IsPress("CamBack"))
	{
		GetMainCameraActorTransform().SetLocalMove(-GetMainCameraActorTransform().GetForwardVector() * 100 * _DeltaTime);
	}

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
		GetMainCameraActorTransform().SetLocalMove(-GetMainCameraActorTransform().GetRightVector() * ptMouse3.x);
		ptMouse3.x = 0;
		ptMouse1.x = ptMouse2.x;
	}
	else if (ptMouse3.x < 0)
	{
		GetMainCameraActorTransform().SetLocalMove(GetMainCameraActorTransform().GetRightVector() * -ptMouse3.x);
		ptMouse3.x = 0;
		ptMouse1.x = ptMouse2.x;

	}

	if (ptMouse3.y > 0)
	{
		GetMainCameraActorTransform().SetLocalMove(GetMainCameraActorTransform().GetUpVector() * ptMouse3.y);
		ptMouse3.y = 0;
		ptMouse1.y = ptMouse2.y;
	}
	else if (ptMouse3.y < 0)
	{
		GetMainCameraActorTransform().SetLocalMove(-GetMainCameraActorTransform().GetUpVector() * -ptMouse3.y);
		ptMouse3.y = 0;
		ptMouse1.y = ptMouse2.y;
	}


}
void PlayLevel::End() {}
