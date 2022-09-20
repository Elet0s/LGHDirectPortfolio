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
		Renderer->GetTransform().SetLocalScale({ 1024.0f, 768.0f , 0.0f });
		Renderer->SetTexture("gameover.bmp");
	}
}
void EndingBG::Update(float _DeltaTime)
{

}
void EndingBG::End()
{

}