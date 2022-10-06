#include"PreCompile.h"
#include"TitleMainUi.h"
#include"GameEngineBase/GameEngineWindow.h"

TitleMainUi::TitleMainUi()
	:Renderer()
{

}
TitleMainUi::~TitleMainUi()
{

}

void TitleMainUi::Start()
{

	GetTransform().SetLocalPosition({ 0, 0, 1 });

	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 776.0f, 590.0f , -5.0f });
		Renderer->SetTexture("TitleUi01.png");
	}
	{
		StartButton = CreateComponent<GameEngineTextureRenderer>();
		StartButton->GetTransform().SetLocalScale({ 112.0f, 38.4f , -5.0f });
		StartButton->GetTransform().SetWorldPosition({ 321.0f,-265.0f ,6.0f });
		StartButton->SetTexture("TitleUi04.png");
		StartCol = CreateComponent<GameEngineCollision>();
		StartCol->GetTransform().SetLocalScale({ 112.0f, 38.4f , -5.0f });
		StartCol->GetTransform().SetWorldPosition({ 321.0f,-265.0f ,-6.0f });
		StartCol->ChangeOrder(OBJECTORDER::UI);

	}
	{
		EnterButton = CreateComponent<GameEngineTextureRenderer>();
		EnterButton->GetTransform().SetLocalScale({ 112.0f, 38.4f , -5.0f });
		EnterButton->GetTransform().SetWorldPosition({ 75.0f,-265.0f ,6.0f });
		EnterButton->SetTexture("TitleUi02.png");
		EnterCol = CreateComponent<GameEngineCollision>();
		EnterCol->GetTransform().SetLocalScale({ 112.0f, 38.4f , -5.0f });
		EnterCol->GetTransform().SetWorldPosition({ 75.0f,-265.0f , -6.0f });
		EnterCol->ChangeOrder(OBJECTORDER::UI);

	}
	{
		CacelButton = CreateComponent<GameEngineTextureRenderer>();
		CacelButton->GetTransform().SetLocalScale({ 112.0f, 38.4f , -5.0f });
		CacelButton->GetTransform().SetWorldPosition({ 198.0f,-265.0f ,6.0f });
		CacelButton->SetTexture("TitleUi03.png");
		CacelCol = CreateComponent<GameEngineCollision>();
		CacelCol->GetTransform().SetLocalScale({ 112.0f, 38.4f , -5.0f });
		CacelCol->GetTransform().SetWorldPosition({ 198.0f,-265.0f ,-6.0f });
		CacelCol->ChangeOrder(OBJECTORDER::UI);
	}

}
void TitleMainUi::Update(float _DeltaTime)
{
	if (StartCol->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Mouse, CollisionType::CT_OBB2D))
	{
		StartButton->GetTransform().SetWorldPosition({ 321.0f,-265.0f ,-6.0f });

		if (true == GameEngineInput::GetInst()->IsUp("MouseLeft"))
		{
			GEngine::ChangeLevel("Event01");
		}
	}
	else
	{
		StartButton->GetTransform().SetWorldPosition({ 321.0f,-265.0f ,6.0f });
	}
	if (EnterCol->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Mouse, CollisionType::CT_OBB2D))
	{
		EnterButton->GetTransform().SetWorldPosition({ 75.0f,-265.0f ,-6.0f });
	}
	else
	{
		EnterButton->GetTransform().SetWorldPosition({ 75.0f,-265.0f ,6.0f });
	}
	if (CacelCol->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Mouse, CollisionType::CT_OBB2D))
	{
		CacelButton->GetTransform().SetWorldPosition({ 198.0f,-265.0f ,-6.0f });

		 if (true == GameEngineInput::GetInst()->IsUp("MouseLeft"))
		{
			 GameEngineWindow::GetInst()->Off();
		}
	}
	else
	{
		CacelButton->GetTransform().SetWorldPosition({ 198.0f,-265.0f ,6.0f });
	}



}
void TitleMainUi::End()
{

}