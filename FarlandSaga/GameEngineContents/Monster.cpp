#include "PreCompile.h"
#include"Monster.h"
#include <GameEngineCore/GameEngineRenderer.h>

Monster::Monster()
{

}
Monster::~Monster()
{

}
void Monster::Start()
{
	{
		GameEngineRenderer* RendererTest = CreateComponent<GameEngineRenderer>();
	}
}