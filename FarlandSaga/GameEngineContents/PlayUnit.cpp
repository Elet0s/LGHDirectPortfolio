#include "PreCompile.h"
#include"PlayUnit.h"

PlayUnit::PlayUnit()
	: UnitType(PlayUnitGroup::None)
{

}
PlayUnit::~PlayUnit()
{

}

void PlayUnit::Start()
{

}

void PlayUnit::Update(float _DeltaTime)
{

}
void PlayUnit::End() 
{

}

void PlayUnit::SetUnit(int _X, int _Y, std::string _UnitName)
{
	GameEngineString::ToUpper(_UnitName);// 대문자로변환해서 조건문 으로 체크 한뒤 유닛 정보를 세팅
	if (_UnitName == "LEON")
	{
		UnitRenderer = CreateComponent<GameEngineTextureRenderer>();
		UnitRenderer->GetTransform().SetLocalScale({ 100,100, 1 });
		UnitRenderer->CreateFrameAnimationCutTexture("LeonWalkU", FrameAnimation_DESC("LeonWalkU.png", 0, 3, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("LeonWalkD", FrameAnimation_DESC("LeonWalkD.png", 0, 3, 0.2f));
		UnitRenderer->CreateFrameAnimationCutTexture("LeonIdle", FrameAnimation_DESC("LeonIdle.png", 0, 2, 0.2f));
		UnitRenderer->ChangeFrameAnimation("LeonIdle");
		UnitRenderer->GetTransform().SetWorldPosition(float4(0, 0, -100));

	}
	else if(_UnitName == "RALF")
	{

	}
}

void UnitMove(size_t _MoveConter, std::string _Direction)
{
	GameEngineString::ToUpper(_Direction);
	if (_Direction == "UP")
	{
		for (size_t i = 0; i < _MoveConter; i++)
		{

		}
	}
	else if (_Direction == "DOWN")
	{
		for (size_t i = 0; i < _MoveConter; i++)
		{

		}
	}
	else if (_Direction == "RIGNT")
	{
		for (size_t i = 0; i < _MoveConter; i++)
		{

		}
	}
	else if (_Direction == "LEFT")
	{
		for (size_t i = 0; i < _MoveConter; i++)
		{

		}
	}
}