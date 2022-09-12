
#include "PreCompile.h"
#include"SelectTileUi.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

SelectTileUi::SelectTileUi()
	:Renderer(nullptr)
{

}
SelectTileUi::~SelectTileUi()
{

}

void SelectTileUi::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->GetTransform().SetLocalScale({ 64.0f, 32.0f, 0.0f });
	Renderer->SetTexture("ST01.png");
}
void SelectTileUi::Update(float _DeltaTime)
{

}
void SelectTileUi::End()
{

}