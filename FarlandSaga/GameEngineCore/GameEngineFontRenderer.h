#pragma once
#include "GameEngineFont.h"
#include "GameEngineDefaultRenderer.h"
#include "GameEngineRenderTarget.h"

class GameEngineDevice;
class GameEngineFontRenderer : public GameEngineDefaultRenderer
{
	friend GameEngineDevice;
	static GameEngineRenderTarget* FontTarget;

public:
	GameEngineFontRenderer();
	~GameEngineFontRenderer();

	GameEngineFontRenderer(const GameEngineFontRenderer& _Other) = delete;
	GameEngineFontRenderer(GameEngineFontRenderer&& _Other) noexcept = delete;
	GameEngineFontRenderer& operator=(const GameEngineFontRenderer& _Other) = delete;
	GameEngineFontRenderer& operator=(GameEngineFontRenderer&& _Other) noexcept = delete;

	void SetText(const std::string& _Text, const std::string& _Font = "µ¸¿ò");

	std::string GetText()
	{
		return Text;
	}

	void SetScreenPostion(float4 _ScreenPostion)
	{
		ScreenPostion = _ScreenPostion;
	}

	void SetColor(float4 _Color)
	{
		Color = _Color;
	}

	void SetSize(float _Size)
	{
		FontSize = _Size;
	}

protected:
	virtual void Start();

	virtual void Render(float _DeltaTime);

	std::string Text;
	GameEngineFont* Font;
	float FontSize;
	float4 Color;
	float4 ScreenPostion;
};

