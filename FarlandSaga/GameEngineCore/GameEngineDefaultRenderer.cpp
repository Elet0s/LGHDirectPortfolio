#include "PreCompile.h"
#include "GameEngineDefaultRenderer.h"
#include "GameEngineRenderingPipeLine.h"

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

void GameEngineDefaultRenderer::SetPipeLine(const std::string& _Name)
{
	PipeLine = GameEngineRenderingPipeLine::Find(_Name);

	if (nullptr == PipeLine)
	{
		MsgBoxAssert("�������� �ʴ� ������������ �����Ϸ��� �߽��ϴ�.");
		return;
	}

}

void GameEngineDefaultRenderer::Render(float _DeltaTime)
{
	if (nullptr == PipeLine)
	{
		MsgBoxAssert("������ ������������ ���õ��� ������ �������� �Ҽ� �����ϴ�.");
	}

	PipeLine->Rendering();
}

