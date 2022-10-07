#include "PreCompile.h"
#include "UIMaster.h"

UIMaster::UIMaster()
	:RClickRenderer()
{
}

UIMaster::~UIMaster()
{
}

void UIMaster::Start()
{

}

void UIMaster::Update(float _DeltaTime) 
{
	if (true == GameEngineInput::GetInst()->IsDown("MouseRight"))
	{
		RClickRenderer = CreateComponent<GameEngineUIRenderer>();
		RClickRenderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		RClickRenderer->GetTransform().SetLocalPosition({ 300, 300, -10 });
		RClickRenderer->SetTexture("RMClick01.png");
	}
}
void UIMaster::End()
{

}