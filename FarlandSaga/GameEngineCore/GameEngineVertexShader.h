#pragma once
#include "GameEngineShader.h"

// Ό³Έν :
class GameEngineVertexShader
	: public GameEngineRes<GameEngineVertexShader>
	, public GameEngineShader

{
public:
	// constrcuter destructer
	GameEngineVertexShader();
	~GameEngineVertexShader();

	// delete Function
	GameEngineVertexShader(const GameEngineVertexShader& _Other) = delete;
	GameEngineVertexShader(GameEngineVertexShader&& _Other) noexcept = delete;
	GameEngineVertexShader& operator=(const GameEngineVertexShader& _Other) = delete;
	GameEngineVertexShader& operator=(GameEngineVertexShader&& _Other) noexcept = delete;

	static GameEngineVertexShader* Load(std::string _Path, std::string _EntryPoint, UINT _VersionHigh = 5, UINT _VersionLow = 0);

	static GameEngineVertexShader* Load(std::string _Path, std::string _Name, std::string _EntryPoint, UINT _VersionHigh, UINT _VersionLow);

protected:

private:

};

