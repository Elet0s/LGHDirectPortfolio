#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineBase/GameEngineWindow.h>

class GameEngineTextureRenderer;
class MouseUI : public GameEngineActor
{
public:

	MouseUI();
	~MouseUI();


	MouseUI(const MouseUI& _Other) = delete;
	MouseUI(MouseUI&& _Other) noexcept = delete;
	MouseUI& operator=(const MouseUI& _Other) = delete;
	MouseUI& operator=(MouseUI&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Renderer;
	GameEngineLevel* Level;
	float MX;
	float MY;

	inline void GetCurPos()
	{
		POINT Pos_;
		GetCursorPos(&Pos_);
		ScreenToClient(GameEngineWindow::GethWnd(), &Pos_);
		MousePosition.x = static_cast<float>(Pos_.x);
		MousePosition.y = static_cast<float>(Pos_.y);
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:



	float4 MousePosition;
	POINT ptMouse1;
	POINT ptMouse2;
	POINT ptMouse3;
};