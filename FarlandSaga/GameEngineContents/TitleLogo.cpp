#include "PreCompile.h"
#include "TitleLogo.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

TitleLogo::TitleLogo()
	: TimeAngle(0.0f)
	, Renderer(nullptr)
{
}

TitleLogo::~TitleLogo()
{
}


void TitleLogo::Start()
{
	// 1280 720
	//1024¡¿768
	GetTransform().SetLocalPosition({ 0, 0, 1 });

	{
		//TimeAngle = 0.0f;
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 1024.0f, 768.0f , 0.0f });
		Renderer->SetTexture("title.bmp");
	}
}

void TitleLogo::Update(float _DeltaTime)
{
	//TimeAngle += _DeltaTime * 20.0f;

	//GetTransform().SetLocalRotation({ 0.0f , 0.0f, TimeAngle });
	//RendererTest->GetTransform().SetLocalRotation({ TimeAngle , TimeAngle, TimeAngle });
}

void TitleLogo::End()
{
}