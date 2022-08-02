#include "PreCompile.h"
#include "GameEngineCollision.h"

bool (*GameEngineCollision::CollisionFunction[static_cast<int>(CollisionType::CT_MAX)][static_cast<int>(CollisionType::CT_MAX)])(const GameEngineTransform& _Left, const GameEngineTransform& _Right);

class GameEngineCollisionFunctionInit
{


public:
	GameEngineCollisionFunctionInit()
	{
		memset(GameEngineCollision::CollisionFunction, 0, sizeof(GameEngineCollision::CollisionFunction));

		GameEngineCollision::CollisionFunction[static_cast<int>(CollisionType::CT_SPHERE)][static_cast<int>(CollisionType::CT_SPHERE)] = &GameEngineTransform::SphereToSphere;
		GameEngineCollision::CollisionFunction[static_cast<int>(CollisionType::CT_AABB)][static_cast<int>(CollisionType::CT_AABB)] = &GameEngineTransform::AABBToAABB;
		GameEngineCollision::CollisionFunction[static_cast<int>(CollisionType::CT_OBB)][static_cast<int>(CollisionType::CT_OBB)] = &GameEngineTransform::OBBToOBB;
	}

	~GameEngineCollisionFunctionInit()
	{

	}
};

GameEngineCollisionFunctionInit Inst;

GameEngineCollision::GameEngineCollision()
{
}

GameEngineCollision::~GameEngineCollision()
{
}


void GameEngineCollision::Start()
{
	GetActor()->GetLevel()->PushCollision(this, GetOrder());
}

void GameEngineCollision::ChangeOrder(int _Order)
{
	GetActor()->GetLevel()->PushCollision(this, _Order);
}

bool GameEngineCollision::IsCollision(CollisionType _ThisType, int _GroupOrder
	, CollisionType _OtherType
	, std::function<bool(GameEngineCollision* _This, GameEngineCollision* _Other)> _Function /*= nullptr*/)
{
	int ThisType = static_cast<int>(_ThisType);
	int OtherType = static_cast<int>(_OtherType);

	if (nullptr == GameEngineCollision::CollisionFunction[ThisType][OtherType])
	{
		MsgBoxAssert("아직 만들어지지 않은 콜리전 처리입니다");
	}

	std::map<int, std::list<GameEngineCollision*>>& AllCollisions = GetActor()->GetLevel()->AllCollisions;

	std::list<GameEngineCollision*>& Collisions = AllCollisions[_GroupOrder];

	for (GameEngineCollision* Collision : Collisions)
	{
		if (false == Collision->IsUpdate())
		{
			continue;
		}

		if (true == GameEngineCollision::CollisionFunction[ThisType][OtherType](GetTransform(), Collision->GetTransform()))
		{
			if (nullptr != _Function)
			{
				if (true == _Function(this, Collision))
				{
					return true;
				}
			}

			return true;
		}
	}

	return false;
}