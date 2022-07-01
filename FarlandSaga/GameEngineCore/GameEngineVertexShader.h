#pragma once
#include "GameEngineShader.h"

class GameEngineVertexShader
	: public GameEngineRes<GameEngineVertexShader>
	, public GameEngineShader

{
public:
	GameEngineVertexShader();
	~GameEngineVertexShader();

	GameEngineVertexShader(const GameEngineVertexShader& _Other) = delete;
	GameEngineVertexShader(GameEngineVertexShader&& _Other) noexcept = delete;
	GameEngineVertexShader& operator=(const GameEngineVertexShader& _Other) = delete;
	GameEngineVertexShader& operator=(GameEngineVertexShader&& _Other) noexcept = delete;

	static GameEngineVertexShader* Load(std::string _Path);

};

