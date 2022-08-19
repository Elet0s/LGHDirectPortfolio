#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "TileMapRenderer.h"

class TileMapRenderer;
class TileMapActor : public GameEngineActor
{
public:
	TileMapActor();
	~TileMapActor();

	TileMapActor(const TileMapActor& _Other) = delete;
	TileMapActor(TileMapActor&& _Other) noexcept = delete;
	TileMapActor& operator=(const TileMapActor& _Other) = delete;
	TileMapActor& operator=(TileMapActor&& _Other) noexcept = delete;

	TileMapRenderer* TileRenderer;
	GameEngineCollision* TileCol;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End();

private:

};

