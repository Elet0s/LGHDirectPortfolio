#include "PreCompile.h"
#include "GameEngineDefaultRenderer.h"

GameEngineDefaultRenderer::GameEngineDefaultRenderer()
	:PipeLine(nullptr)
{
}

GameEngineDefaultRenderer::~GameEngineDefaultRenderer()
{
}

void GameEngineDefaultRenderer::Start()
{
	GameEngineRenderer::Start();

	// 뭔가 또 할일이 있다면 여기서 해라.
}

void GameEngineDefaultRenderer::Render(float _DeltaTime)
{
	// PipeLine->Draw();
}

