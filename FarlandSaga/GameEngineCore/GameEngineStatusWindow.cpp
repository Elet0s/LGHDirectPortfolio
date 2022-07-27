#include "PreCompile.h"
#include "GameEngineStatusWindow.h"

GameEngineStatusWindow::GameEngineStatusWindow()
{
}

GameEngineStatusWindow::~GameEngineStatusWindow()
{
}


void GameEngineStatusWindow::Initialize(class GameEngineLevel* _Level)
{

}

void GameEngineStatusWindow::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
	int FPS = static_cast<int>(1.0f / _DeltaTime);
	// printf 형식인데 안씀.
	// LabelText는 보통 어떤 기능도 없는 글자표현기능
	std::string Name = "FPS : " + std::to_string(FPS);
	ImGui::Text(std::to_string(FPS).c_str());
}