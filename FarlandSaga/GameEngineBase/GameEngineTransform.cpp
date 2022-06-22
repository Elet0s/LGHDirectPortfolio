#include "PreCompile.h"
#include "GameEngineTransform.h"

GameEngineTransform::GameEngineTransform()
	: LocalScale(float4::ONE)
	, LocalPosition(float4::ZERO)
	, LocalRotation(float4::ZERO)
	, WorldScale(float4::ONE)
	, WorldPosition(float4::ZERO)
	, WorldRotation(float4::ZERO)
	, Parent(nullptr)
	, CollisionDataObject()
{
	CollisionDataSetting();
}

GameEngineTransform::~GameEngineTransform()
{
}


void GameEngineTransform::CalculateWorld()
{

	LocalWorldMat = LocalScaleMat * LocalRotateMat * LocalPositionMat;

	if (nullptr != Parent)
	{
		// Parent 컴포넌트일 경우에는 액터의 트랜스폼을 부모로 가지게 된다. 
		// 엑터 트랜스폼 - 부모 컴포넌트 - 자식 컴포넌트
		WorldWorldMat = LocalWorldMat * Parent->GetWorldWorld();
	}
	else
	{
		WorldWorldMat = LocalWorldMat;
	}

	for (GameEngineTransform* Child : Childs)
	{
		Child->CalculateWorld();
	}
}

void GameEngineTransform::CalculateWorldViewProjection()
{
	WorldViewMat = WorldWorldMat * View;
	WorldViewProjectMat = WorldViewMat * Projection;
}

void GameEngineTransform::DetachTransform()
{
	if (nullptr == Parent)
	{
		return;
	}

	Parent->Childs.remove(this);
	Parent = nullptr;

}

void GameEngineTransform::SetParentTransform(GameEngineTransform& _Parent)
{
	if (nullptr != Parent)
	{
		// 나는 삭제되고
		Parent->Childs.remove(this);
		Parent = nullptr;
	}

	Parent = &_Parent;
	_Parent.Childs.push_back(this);

	SetLocalScale(LocalScale);
	SetLocalRotation(LocalRotation);
	SetLocalPosition(LocalPosition);
}
