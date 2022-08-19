#include "PreCompile.h"
#include "TileMapActor.h"

TileMapActor::TileMapActor()
{
}

TileMapActor::~TileMapActor()
{
}

void TileMapActor::Start()
{
	{
		TileRenderer = CreateComponent<TileMapRenderer>();
	}
	{
		TileCol = CreateComponent<GameEngineCollision>();
		TileCol->GetTransform().SetLocalScale({ 100.0f, 100.0f, 100.0f });
		TileCol->ChangeOrder(OBJECTORDER::Player);
	}
}

void TileMapActor::Update(float _DeltaTime)
{

}
void TileMapActor::End()
{

}