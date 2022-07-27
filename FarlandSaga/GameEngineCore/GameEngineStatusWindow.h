#pragma once
#include "GameEngineGUI.h"

class GameEngineStatusWindow : public GameEngineGUIWindow
{
public:
	GameEngineStatusWindow();
	~GameEngineStatusWindow();

	GameEngineStatusWindow(const GameEngineStatusWindow& _Other) = delete;
	GameEngineStatusWindow(GameEngineStatusWindow&& _Other) noexcept = delete;
	GameEngineStatusWindow& operator=(const GameEngineStatusWindow& _Other) = delete;
	GameEngineStatusWindow& operator=(GameEngineStatusWindow&& _Other) noexcept = delete;

protected:

private:
	void Initialize(class GameEngineLevel* _Level) override; //���������Լ� �� �ִ� Ŭ����->�߻�Ŭ����
	void OnGUI(GameEngineLevel* _Level, float _DeltaTime) override;
};