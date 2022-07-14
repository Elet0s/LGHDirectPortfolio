#pragma once
#include "GameEngineDefaultRenderer.h"

// Ό³Έν :
class GameEngineTextureRenderer : public GameEngineDefaultRenderer
{
public:
	// constrcuter destructer
	GameEngineTextureRenderer();
	~GameEngineTextureRenderer();

	// delete Function
	GameEngineTextureRenderer(const GameEngineTextureRenderer& _Other) = delete;
	GameEngineTextureRenderer(GameEngineTextureRenderer&& _Other) noexcept = delete;
	GameEngineTextureRenderer& operator=(const GameEngineTextureRenderer& _Other) = delete;
	GameEngineTextureRenderer& operator=(GameEngineTextureRenderer&& _Other) noexcept = delete;

	void SetTexture(const std::string& _Name);

	void SetFrame(UINT _Index);

	void SetTexture(const std::string& _Name, UINT _Index);

protected:
	void Start() override;

private:
	GameEngineTexture* CurTex;
	float4 FrameData;
};

