#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "TileMapRenderer.h"

class TileMapRenderer;
class ObjectActor : public GameEngineActor
{
public:
	ObjectActor();
	~ObjectActor();

	ObjectActor(const ObjectActor& _Other) = delete;
	ObjectActor(ObjectActor&& _Other) noexcept = delete;
	ObjectActor& operator=(const ObjectActor& _Other) = delete;
	ObjectActor& operator=(ObjectActor&& _Other) noexcept = delete;

	TileMapRenderer* TileRenderer;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End();

private:
};