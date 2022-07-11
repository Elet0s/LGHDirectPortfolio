#pragma once
#include "GameEngineRenderingPipeLine.h"
#include "GameEngineShader.h"

class GameEngineShaderResourcesHelper
{
	friend GameEngineShader;

public:
	GameEngineShaderResourcesHelper();
	~GameEngineShaderResourcesHelper();

	GameEngineShaderResourcesHelper(const GameEngineShaderResourcesHelper& _Other) = delete;
	GameEngineShaderResourcesHelper(GameEngineShaderResourcesHelper&& _Other) noexcept = delete;
	GameEngineShaderResourcesHelper& operator=(const GameEngineShaderResourcesHelper& _Other) = delete;
	GameEngineShaderResourcesHelper& operator=(GameEngineShaderResourcesHelper&& _Other) noexcept = delete;

protected:
	void ResourcesCheck(GameEngineShader* _Shader);

private:
	std::map<std::string, GameEngineConstantBufferSetter> ConstantBufferMap;
	std::map<std::string, GameEngineTextureSetter> TextureSetterMap;
};

