#pragma once
#include "GameEngineRenderTarget.h"

class GameEngineTexture;
class GameEngineDepthStencilTexture : public GameEngineRes<GameEngineDepthStencilTexture>
{
public:
	static GameEngineDepthStencilTexture* Create(const float4 _Scale);


public:
	GameEngineDepthStencilTexture();
	~GameEngineDepthStencilTexture();

	GameEngineDepthStencilTexture(const GameEngineDepthStencilTexture& _Other) = delete;
	GameEngineDepthStencilTexture(GameEngineDepthStencilTexture&& _Other) noexcept = delete;
	GameEngineDepthStencilTexture& operator=(const GameEngineDepthStencilTexture& _Other) = delete;
	GameEngineDepthStencilTexture& operator=(GameEngineDepthStencilTexture&& _Other) noexcept = delete;

	ID3D11DepthStencilView* CreateDepthStencilView();

protected:

private:
	GameEngineTexture* Buffer;

	void CreateDepthTexture(const float4 _Scale);

};

