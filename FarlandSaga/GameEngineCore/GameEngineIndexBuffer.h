#pragma once
#include "GameEngineRes.h"
#include <GameEngineBase/GameEngineMath.h>
#include <vector>
#include <string>
#include <map>
#include <list>

// Ό³Έν :
class GameEngineIndexBuffer : public GameEngineRes<GameEngineIndexBuffer>
{
	friend GameEngineRes<GameEngineIndexBuffer>;

private:
	static GameEngineIndexBuffer* CreateRes(const std::vector<int>& _Indexs, const std::string& _Name = "");

public:
	static void Create(const std::string& _Name, const std::vector<int>& _Indexs);
	static void Create(const std::vector<int>& _Indexs);

private:
	// constrcuter destructer
	GameEngineIndexBuffer();
	~GameEngineIndexBuffer();

	// delete Function
	GameEngineIndexBuffer(const GameEngineIndexBuffer& _Other) = delete;
	GameEngineIndexBuffer(GameEngineIndexBuffer&& _Other) noexcept = delete;
	GameEngineIndexBuffer& operator=(const GameEngineIndexBuffer& _Other) = delete;
	GameEngineIndexBuffer& operator=(GameEngineIndexBuffer&& _Other) noexcept = delete;

protected:


public:
	std::vector<int> Indexs;

};

