#include "PreCompile.h"
#include"Stage01.h"
#include "GlobalContentsValue.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>
#include "Monster.h"
#include "Player.h"
#include "UIMaster.h"
#include "TestStageBG.h"


Stage01::Stage01()
	:ptMouse1(),
	ptMouse2(),
	ptMouse3()
{
}

Stage01::~Stage01()
{
}

void Stage01::Start()
{

	CreateActor<TestStageBG>(OBJECTORDER::BG);

	if (false == GameEngineInput::GetInst()->IsKey("FreeCameaOnOff"))
	{
		GameEngineInput::GetInst()->CreateKey("FreeCameaOnOff", 'O');
	}



	{
		Player* NewPlayer = CreateActor<Player>(OBJECTORDER::Player);
	}

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
		Player* NewPlayer = CreateActor<Player>(OBJECTORDER::Player);
	}

	{
		UIMaster* NewPlayer = CreateActor<UIMaster>(OBJECTORDER::UI);
	}

	{
		Monster* actor = CreateActor<Monster>(OBJECTORDER::Monster);
		actor->GetTransform().SetLocalPosition({ 300.0f, 0.0f, 0.0f });
		actor->GetTransform().SetWorldScale(float4(1.0f, 1.0f, 1.0f));
	}


}
void Stage01::Update(float _DeltaTime)
{
	if (GameEngineInput::GetInst()->IsDown("FreeCameaOnOff"))
	{
		GetMainCameraActor()->FreeCameraModeOnOff();
	}

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
void Stage01::End() {}
