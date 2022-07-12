#pragma once
#include "GameEngineShader.h"
#include "GameEngineRes.h"

class GameEnginePixelShader
	: public GameEngineShader
	, public GameEngineRes<GameEnginePixelShader>
{
	friend GameEngineShader;
	friend GameEngineRes<GameEnginePixelShader>;

public:
	static GameEnginePixelShader* Load(std::string _Path, std::string _EntryPoint, UINT _VersionHigh = 5, UINT _VersionLow = 0);

	static GameEnginePixelShader* Load(std::string _Path, std::string _Name, std::string _EntryPoint, UINT _VersionHigh, UINT _VersionLow);

private:
	GameEnginePixelShader();
	~GameEnginePixelShader();

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

