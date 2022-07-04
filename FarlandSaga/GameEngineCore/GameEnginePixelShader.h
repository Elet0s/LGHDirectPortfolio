#pragma once
#include "GameEngineShader.h"
#include "GameEngineRes.h"

// ���� :
class GameEnginePixelShader
	: public GameEngineRes<GameEnginePixelShader>
	, public GameEngineShader
{
	friend GameEngineShader;
	friend GameEngineRes<GameEnginePixelShader>;

public:
	static GameEnginePixelShader* Load(std::string _Path, std::string _EntryPoint, UINT _VersionHigh = 5, UINT _VersionLow = 0);

	static GameEnginePixelShader* Load(std::string _Path, std::string _Name, std::string _EntryPoint, UINT _VersionHigh, UINT _VersionLow);

private:
	// constrcuter destructer
	GameEnginePixelShader();
	~GameEnginePixelShader();

	// delete Function
	GameEnginePixelShader(const GameEnginePixelShader& _Other) = delete;
	GameEnginePixelShader(GameEnginePixelShader&& _Other) noexcept = delete;
	GameEnginePixelShader& operator=(const GameEnginePixelShader& _Other) = delete;
	GameEnginePixelShader& operator=(GameEnginePixelShader&& _Other) noexcept = delete;

public:
	void Setting();

protected:
	void ShaderCompile(std::string _Path, std::string _EntryPoint, UINT _VersionHigh, UINT _VersionLow);

private:
	ID3D11PixelShader* ShaderPtr;
};

