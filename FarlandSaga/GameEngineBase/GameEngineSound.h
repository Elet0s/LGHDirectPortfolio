#pragma once
#include "GameEngineNameObject.h"
#include "ThirdParty/inc/fmod.hpp"
#include "GameEngineFile.h"
#include <map>

class GameEngineSoundPlayer;

class GameEngineSound : public GameEngineNameObject
{
public:

	GameEngineSound();
	~GameEngineSound();

	GameEngineSound(const GameEngineSound& _Other) = delete;
	GameEngineSound(GameEngineSound&& _Other) noexcept = delete;
	GameEngineSound& operator=(const GameEngineSound& _Other) = delete;
	GameEngineSound& operator=(GameEngineSound&& _Other) noexcept = delete;

protected:
	bool Load(const std::string& _Path);


private:
	FMOD::Sound* Sound;

	///////////////////////////////////////// 매니지먼트 사운드 기능
public:
	// 그냥 사운드 재생1회 절대로 멈추거나 이런건 못합니다.
	static GameEngineSoundPlayer SoundPlayControl(const std::string& _Name, unsigned int LoopCount = 0);

	static void SoundPlayOneShot(const std::string& _Name, int LoopCount = 0);
	static void Update();

	/// <summary>
	/// ///////////////////////////////////// 리소스 매니지먼트
	/// </summary>
public:
	static GameEngineSound* FindRessource(const std::string& _Name);
	static GameEngineSound* LoadRessource(const GameEngineFile& _Path);
	static GameEngineSound* LoadRessource(const std::string& _Path);
	static GameEngineSound* LoadRessource(const std::string& _Path, const std::string& _Name);

	static void ResourcesDestroy();

private:
	static std::map<std::string, GameEngineSound*> AllRes;

};

// 사운드 재생을 제어할수 있는 기능들을 넣을겁니다.
class GameEngineSound;
class GameEngineSoundPlayer
{
	friend GameEngineSound;

public:
	void Stop();
	void PlaySpeed(float _Speed);
	void Volume(float _Value);

	GameEngineSoundPlayer(const GameEngineSoundPlayer& _Other);

private:
	GameEngineSound* Sound_;
	FMOD::Channel* ControlHandle_;


	GameEngineSoundPlayer(GameEngineSound* Sound, FMOD::Channel* ControlHandle);

public:
	GameEngineSoundPlayer();
	~GameEngineSoundPlayer();
};