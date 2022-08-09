#include "PreCompile.h"
#include "TileMapActor.h"
#include "TileMapRenderer.h"

TileMapActor::TileMapActor()
{
}

TileMapActor::~TileMapActor()
{
}

void TileMapActor::Start()
{
	{
		TileMapRenderer* Renderer = CreateComponent<TileMapRenderer>();
	}

}
void TileMapActor::Update(float _DeltaTime)
{

}
void TileMapActor::End()
{

}