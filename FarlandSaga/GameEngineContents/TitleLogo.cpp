#include "TitleLogo.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineRenderer.h>

TitleLogo::TitleLogo()
{
}

TitleLogo::~TitleLogo()
{
}

void TitleLogo::Start()
{
	GetTransform().SetScale({ 100, 100 });
	GetTransform().SetPosition({ 300, 300, 100 });
	{
		GameEngineRenderer* Renderer = CreateComponent<GameEngineRenderer>();
		// Renderer->ChangeOrder();
	}


	// 액터는 => 존재
	// 특화하지 않으면
	// 컴포넌트의 뜻 => 기능


}

void TitleLogo::Update(float _DeltaTime)
{
	//if (3.0f < GetAccTime())
	//{
	//	GEngine::ChangeLevel("Play");
	//	// GetLevel()->CreateActor();
	//}
}

void TitleLogo::End()
{
	int a = 0;
}