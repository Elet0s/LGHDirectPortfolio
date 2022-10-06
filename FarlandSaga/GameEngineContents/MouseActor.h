#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineBase/GameEngineWindow.h>

class GameEngineTextureRenderer;
class TileMapRenderer;
class MouseActor : public GameEngineActor
{
public:

	MouseActor();
	~MouseActor();


	MouseActor(const MouseActor& _Other) = delete;
	MouseActor(MouseActor&& _Other) noexcept = delete;
	MouseActor& operator=(const MouseActor& _Other) = delete;
	MouseActor& operator=(MouseActor&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Renderer;
	GameEngineLevel* Level;
	float MX;
	float MY;
	int MZ;
	bool OnUnit;
	bool OnMon;
	TileMapRenderer* TileMap;
	GameEngineCollision* MouseCol_;
	int MouseOnX;
	int MouseOnY;
	void SetTileRenderer(TileMapRenderer* _TileMapRenderer);

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