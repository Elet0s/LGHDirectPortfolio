#include "PreCompile.h"
#include"Flower.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

Flower::Flower()
{

}
Flower::~Flower()
{

}
void Flower::Start()
{
	GetTransform().SetLocalPosition({ 0, -214, 1 });

	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 1024, 340, 0 });
		Renderer->SetTexture("gameover.bmp");
	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("ConstantResources");
		Dir.Move("ConstantResources");
		Dir.Move("TestFolder");
		GameEngineFolderTexture::Load(Dir.GetFullPath());

		Renderer->CreateFrameAnimationFolder("Idle", FrameAnimation_DESC("TestFolder", 0.1f, true));
		Renderer->ChangeFrameAnimation("Idle");
	}

}
void Flower::Update(float _DeltaTime)
{

}
void Flower::End()
{

}