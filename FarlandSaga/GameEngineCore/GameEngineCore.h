#pragma once
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <map>

// 설명 :
class GameEngineCore
{
public:
	template<typename CoreType>
	static void Start()
	{
		GameEngineDebug::LeakCheckOn();

		// 여기에서 만들어진 이 코어를 알아야 하는거지.
		CoreType Core;
		WindowCreate(Core.GetWindowTitle(), &Core);
	}



protected:
	virtual std::string GetWindowTitle() { return "MainWindow"; }

	// 너희들이 간섭할수 있는 내용.
	virtual void UserStart() = 0;
	// 엔진에서 제공하는 시간을 주고 너는 이걸 써라.
	virtual void UserUpdate(float _DeltaTime) = 0;
	virtual void UserEnd() = 0;

	GameEngineCore();
	~GameEngineCore();

	class GameEngineLevel* FindLevel(const std::string& _Name);

	template<typename LevelType>
	GameEngineLevel* CreateLevel(const std::string& _Name)
	{
		std::string UpperName = GameEngineString::ToUpperReturn(_Name);
		GameEngineLevel* NewLevel = new LevelType();
		InitializeLevel(NewLevel, UpperName);
		return NewLevel;
	}

	bool ChangeLevel(const std::string& _Name);

private:
	static std::map<std::string, class GameEngineLevel*> AllLevels;
	static GameEngineLevel* CurrentLevel;
	static GameEngineLevel* NextLevel;

	static void WindowCreate(const std::string& _Name, GameEngineCore* _UserCore);
	static void CoreStart(GameEngineCore* _UserCore); // 프로그램 시작
	static void CoreUpdate(GameEngineCore* _UserCore); // 프로그램 업데이트
	static void CoreEnd(GameEngineCore* _UserCore); // 프로그램 업데이트

	// 헤더 추가하기 싫어서 초기화를 CPP에서 하기 위한 함수.
	void InitializeLevel(GameEngineLevel* _Level, const std::string _Name);

	// delete Function
	GameEngineCore(const GameEngineCore& _Other) = delete;
	GameEngineCore(GameEngineCore&& _Other) noexcept = delete;
	GameEngineCore& operator=(const GameEngineCore& _Other) = delete;
	GameEngineCore& operator=(GameEngineCore&& _Other) noexcept = delete;


};

