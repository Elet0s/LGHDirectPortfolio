#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineRes.h"
#include <vector>
#include <string>
#include <map>
#include <list>

// Ό³Έν :
class GameEngineVertexBuffer : public GameEngineRes<GameEngineVertexBuffer>
{
public:
	friend GameEngineRes<GameEngineVertexBuffer>;

private:
	static GameEngineVertexBuffer* CreateRes(const std::vector<float4>& _Vertex, const std::string& _Name = "");

public:
	static void Create(const std::string& _Name, const std::vector<float4>& _Vertex);
	static void Create(const std::vector<float4>& _Vertex);

private:
	// constrcuter destructer
	GameEngineVertexBuffer();
	~GameEngineVertexBuffer();

	// delete Function
	GameEngineVertexBuffer(const GameEngineVertexBuffer& _Other) = delete;
	GameEngineVertexBuffer(GameEngineVertexBuffer&& _Other) noexcept = delete;
	GameEngineVertexBuffer& operator=(const GameEngineVertexBuffer& _Other) = delete;
	GameEngineVertexBuffer& operator=(GameEngineVertexBuffer&& _Other) noexcept = delete;

protected:


private:

public:
	std::vector<float4> Vertexs;


};

