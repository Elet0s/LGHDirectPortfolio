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

	// ���� �� ������ �ִٸ� ���⼭ �ض�.
}

void GameEngineDefaultRenderer::Render(float _DeltaTime)
{
	// PipeLine->Draw();
}

