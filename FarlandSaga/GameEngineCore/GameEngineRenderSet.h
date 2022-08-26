#pragma once
#include "GameEngineRenderingPipeLine.h"
#include "GameEngineShaderResourcesHelper.h"

class GameEngineRenderSet
{
public:
	GameEngineRenderSet();
	~GameEngineRenderSet();

	GameEngineRenderSet(const GameEngineRenderSet& _Other) = delete;
	GameEngineRenderSet(GameEngineRenderSet&& _Other) noexcept = delete;
	GameEngineRenderSet& operator=(const GameEngineRenderSet& _Other) = delete;
	GameEngineRenderSet& operator=(GameEngineRenderSet&& _Other) noexcept = delete;


	void SetPipeLine(const std::string& _Name);

	void Render();

	GameEngineRenderingPipeLine* GetPipeLine();

	GameEngineRenderingPipeLine* PipeLine;
	GameEngineShaderResourcesHelper ShaderResources;

};

