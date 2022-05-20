#include "GameEngineCore.h"
#include <GameEngineBase/GameEngineWindow.h>

#pragma comment(lib, "GameEngineBase.lib")

GameEngineCore::GameEngineCore()
{
}

GameEngineCore::~GameEngineCore()
{
}

void GameEngineCore::CoreStart(GameEngineCore* _UserCore)
{
	_UserCore->UserGameStart();
}

void GameEngineCore::CoreUpdate(GameEngineCore* _UserCore)
{
	_UserCore->UserGameUpdate();
}

void GameEngineCore::CoreEnd(GameEngineCore* _UserCore)
{
	_UserCore->UserGameEnd();
}


void GameEngineCore::WindowCreate(const std::string& _Name, GameEngineCore* _UserCore)
{
	GameEngineWindow::GetInst().CreateGameWindow(nullptr, _Name.c_str());
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0,0 }, { 1280, 720 });
	GameEngineWindow::GetInst().ShowGameWindow();
	GameEngineWindow::GetInst().MessageLoop(
		std::bind(&GameEngineCore::CoreStart, _UserCore),
		std::bind(&GameEngineCore::CoreUpdate, _UserCore),
		std::bind(&GameEngineCore::CoreEnd, _UserCore)
	);
}