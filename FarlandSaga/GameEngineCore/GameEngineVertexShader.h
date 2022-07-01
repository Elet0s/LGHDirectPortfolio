#pragma once
#include "GameEngineShader.h"
#include "GameEngineRes.h"

// Ό³Έν :
class GameEngineInputLayOut;
class GameEngineVertexShader
	: public GameEngineRes<GameEngineVertexShader>
	, public GameEngineShader

{
	friend GameEngineInputLayOut;
	friend GameEngineShader;
	friend GameEngineRes<GameEngineVertexShader>;

private:
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

	void ShaderCompile(std::string _Path, std::string _EntryPoint, UINT _VersionHigh, UINT _VersionLow);

private:
	ID3D11VertexShader* ShaderPtr;

};

