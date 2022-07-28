#pragma once
#include "GameEngineTextureRenderer.h"

class GameEngineUIRenderer : public GameEngineTextureRenderer
{
public:
	GameEngineUIRenderer();
	~GameEngineUIRenderer();

	GameEngineUIRenderer(const GameEngineUIRenderer& _Other) = delete;
	GameEngineUIRenderer(GameEngineUIRenderer&& _Other) noexcept = delete;
	GameEngineUIRenderer& operator=(const GameEngineUIRenderer& _Other) = delete;
	GameEngineUIRenderer& operator=(GameEngineUIRenderer&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

