#include "PreCompile.h"
#include"EndingBG.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

EndingBG::EndingBG()
{

}
EndingBG::~EndingBG()
{

}
void EndingBG::Start()
{
	GetTransform().SetLocalPosition({ 0, 0, 1 });

	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 640.0f, 480.0f, 0.0f });
		Renderer->SetTexture("gameover.bmp");
	}
}
void EndingBG::Update(float _DeltaTime)
{

}
void EndingBG::End()
{

}