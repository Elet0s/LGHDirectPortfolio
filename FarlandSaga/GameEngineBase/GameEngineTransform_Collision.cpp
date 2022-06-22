#include "PreCompile.h"
#include "GameEngineTransform.h"
// #include <DirectXCollision.inl>


void GameEngineTransform::CollisionScaleSetting() {
	CollisionDataObject.OBB.Extents = WorldScale * 0.5f;
}
void GameEngineTransform::CollisionRotationSetting() {
	CollisionDataObject.OBB.Orientation = WorldRotation.DegreeRotationToQuaternionReturn();
}
void GameEngineTransform::CollisionPositionSetting() {
	CollisionDataObject.OBB.Center = WorldPosition;
}

void GameEngineTransform::CollisionDataSetting()
{
	CollisionScaleSetting();
	CollisionRotationSetting();
	CollisionPositionSetting();
}


bool GameEngineTransform::SphereToSphere(const GameEngineTransform& _Left, const GameEngineTransform& _Right)
{
	return _Left.CollisionDataObject.SPHERE.Intersects(_Right.CollisionDataObject.SPHERE);
}

bool GameEngineTransform::AABBToAABB(const GameEngineTransform& _Left, const GameEngineTransform& _Right)
{
	return _Left.CollisionDataObject.AABB.Intersects(_Right.CollisionDataObject.AABB);
}

bool GameEngineTransform::OBBToOBB(const GameEngineTransform& _Left, const GameEngineTransform& _Right)
{
	return _Left.CollisionDataObject.OBB.Intersects(_Right.CollisionDataObject.OBB);
}