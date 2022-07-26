#pragma once
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

class GameEngineCore;
class GameEngineGUI
{
	friend GameEngineCore;

public:	
	GameEngineGUI();
	~GameEngineGUI();

	GameEngineGUI(const GameEngineGUI& _Other) = delete;
	GameEngineGUI(GameEngineGUI&& _Other) noexcept = delete;
	GameEngineGUI& operator=(const GameEngineGUI& _Other) = delete;
	GameEngineGUI& operator=(GameEngineGUI&& _Other) noexcept = delete;

	static void Initialize();
	static void GUIRender();


protected:

private:
	static void GUIDestroy();

};

