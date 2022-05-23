#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineNameObject.h>
#include <vector>
#include <string>
#include <map>
#include <list>

// Ό³Έν :
class GameEngineMesh : public GameEngineNameObject
{
private:
	static std::map<std::string, GameEngineMesh*> NamedRes;
	static std::list<GameEngineMesh*> UnNamedRes;
	static GameEngineMesh* CreateRes(const std::vector<float4>& _Vertex, const std::string& _Name = "");

public:
	static void Create(const std::string& _Name, const std::vector<float4>& _Vertex);
	static void Create(const std::vector<float4>& _Vertex);



private:
	// constrcuter destructer
	GameEngineMesh();
	~GameEngineMesh();

	// delete Function
	GameEngineMesh(const GameEngineMesh& _Other) = delete;
	GameEngineMesh(GameEngineMesh&& _Other) noexcept = delete;
	GameEngineMesh& operator=(const GameEngineMesh& _Other) = delete;
	GameEngineMesh& operator=(GameEngineMesh&& _Other) noexcept = delete;

protected:


private:
	std::vector<float4> Vertex;

};

