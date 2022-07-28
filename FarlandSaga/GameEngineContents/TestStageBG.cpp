#include "PreCompile.h"
#include"TestStageBG.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

TestStageBG::TestStageBG()
	: TimeAngle(0.0f)
{

}
TestStageBG::~TestStageBG()
{

}

void TestStageBG::Start()
{
	GetTransform().SetLocalPosition({ 1, -20, 1 });

	{
		//TimeAngle = 0.0f;
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 2048, 1536, 100 });
		Renderer->SetTexture("TestStage.png");
	}
}
void TestStageBG::Update(float _DeltaTime)
{

}
void TestStageBG::End()
{

}