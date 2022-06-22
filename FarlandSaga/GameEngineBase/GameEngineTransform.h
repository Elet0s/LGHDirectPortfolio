#pragma once
#include "GameEngineMath.h"
#include <DirectXCollision.h>
#include <GameEngineBase/GameEngineDebugObject.h>
#include <GameEngineBase/GameEngineUpdateObject.h>
#include <list>

enum CollisionType
{
	CT_POINT,
	CT_SPHERE, // 정방원
	CT_AABB, // 회전하지 않은 박스
	CT_OBB, // 회전한 박스
};

class CollisionData
{
	friend class GameEngineTransform;

	union
	{
		DirectX::BoundingSphere SPHERE;
		DirectX::BoundingBox AABB;
		DirectX::BoundingOrientedBox OBB;
	};

	CollisionData()
		: OBB()
	{

	}
};

// 설명 :
class GameEngineTransform : public GameEngineDebugObject
{
public:
	// constrcuter destructer
	GameEngineTransform();
	~GameEngineTransform();

	// delete Function
	GameEngineTransform(const GameEngineTransform& _Other) = delete;
	GameEngineTransform(GameEngineTransform&& _Other) noexcept = delete;
	GameEngineTransform& operator=(const GameEngineTransform& _Other) = delete;
	GameEngineTransform& operator=(GameEngineTransform&& _Other) noexcept = delete;


public:
	inline void SetLocalScale(const float4& _Value)
	{
		CalculateWorldScale(_Value);
		CalculateWorld();
	}

	inline void SetLocalRotation(const float4& _Value)
	{
		CalculateWorldRotation(_Value);
		CalculateWorld();
	}

	inline void SetLocalPosition(const float4& _Value)
	{
		CalculateWorldPosition(_Value);
		CalculateWorld();
	}

	inline void SetWorldScale(const float4& _World)
	{
		float4 Local = _World;
		if (nullptr != Parent)
		{
			Local = _World / Parent->WorldScale;
		}

		CalculateWorldScale(Local);
		CalculateWorld();
	}

	inline void SetWorldRotation(const float4& _World)
	{
		float4 Local = _World;
		if (nullptr != Parent)
		{
			Local = _World - Parent->WorldRotation;
		}

		CalculateWorldRotation(Local);
		CalculateWorld();
	}

	inline void SetWorldPosition(const float4& _World)
	{
		float4 Local = _World;
		if (nullptr != Parent)
		{
			// 부모의 역행렬을 곱해서 
			Local = _World * Parent->WorldWorldMat.InverseReturn();
		}


		CalculateWorldPosition(Local);
		CalculateWorld();
	}

	inline void SetLocalRotate(const float4& _Value)
	{
		SetLocalRotation(LocalRotation + _Value);
	}

	inline void SetLocalMove(const float4& _Value)
	{
		SetLocalPosition(LocalPosition + _Value);
	}

	inline void SetWorldMove(const float4& _Value)
	{
		SetLocalPosition(WorldPosition + _Value);
	}

	inline float4 GetLocalScale() const
	{
		return LocalScale;
	}
	inline float4 GetLocalRotation() const
	{
		return LocalRotation;
	}
	inline float4 GetLocalPosition() const
	{
		return LocalPosition;
	}

	inline float4x4 GetLocalWorld() const
	{
		return LocalWorldMat;
	}

	inline float4x4 GetWorldWorld() const
	{
		return WorldWorldMat;
	}

	inline float4x4 GetWorldViewProjection() const
	{
		return WorldViewProjectMat;
	}

	inline float4 GetForwardVector() const
	{
		return WorldWorldMat.ArrV[2].NormalizeReturn();
	}

	inline float4 GetBackVector() const
	{
		return -(WorldWorldMat.ArrV[2].NormalizeReturn());
	}

	inline float4 GetUpVector() const
	{
		return WorldWorldMat.ArrV[1].NormalizeReturn();
	}

	inline float4 GetDownVector() const
	{
		return -(WorldWorldMat.ArrV[1].NormalizeReturn());
	}

	inline float4 GetRightVector() const
	{
		return WorldWorldMat.ArrV[0].NormalizeReturn();
	}

	inline float4 GetLeftVector() const
	{
		return -(WorldWorldMat.ArrV[0].NormalizeReturn());
	}

	void CalculateWorld();

	void CalculateWorldViewProjection();

	void DetachTransform();

	void SetParentTransform(GameEngineTransform& _Child);

	// void PushChild(GameEngineTransform* _Child);

	void SetView(const float4x4& _Mat)
	{
		View = _Mat;
	}

	void SetProjection(const float4x4& _Mat)
	{
		Projection = _Mat;
	}

protected:

private:
	GameEngineTransform* Parent;
	std::list<GameEngineTransform*> Childs;

	// 로컬과 월드의 차이가 뭐냐 개념을 확실히 잡아야합니다..
	float4 LocalScale;
	float4 LocalRotation;
	float4 LocalPosition;

	// WorldScale.w 0
	float4 WorldScale;
	// WorldScale.w 0
	float4 WorldRotation;
	// WorldPosition.w 1
	float4 WorldPosition;

	float4x4 LocalScaleMat; // 크
	float4x4 LocalRotateMat; // 자
	float4x4 LocalPositionMat; // 이
	float4x4 LocalWorldMat;

	float4x4 View;
	float4x4 Projection;

	float4x4 WorldWorldMat; // 나의 로컬 world * 부모의 world
	float4x4 WorldViewMat;
	float4x4 WorldViewProjectMat;


	void CalculateWorldScale(const float4& _Local)
	{
		LocalScale = _Local;
		LocalScale.w = 0.0f; // 이동을 적용받지 않기.
		// DirectX::XMVector3TransformCoord // 1로 곱하기
		// DirectX::XMVector3TransformNormal // 0넣고 곱하기

		if (nullptr != Parent)
		{
			WorldScale = LocalScale * Parent->WorldScale;
		}
		else
		{
			WorldScale = LocalScale;
		}

		CollisionScaleSetting();

		LocalScaleMat.Scale(LocalScale);

		for (GameEngineTransform* Child : Childs)
		{
			Child->CalculateWorldScale(Child->LocalScale);
			Child->CalculateWorldPosition(Child->LocalPosition);
		}

	}
	void CalculateWorldRotation(const float4& _Local)
	{
		LocalRotation = _Local;
		LocalRotation.w = 0.0f; // 이동을 적용받지 않기.

		if (nullptr != Parent)
		{
			WorldRotation = LocalRotation + Parent->WorldRotation;
		}
		else
		{
			WorldRotation = LocalRotation;
		}

		CollisionRotationSetting();

		LocalRotateMat.RotationDegree(LocalRotation);

		for (GameEngineTransform* Child : Childs)
		{
			Child->CalculateWorldRotation(Child->LocalRotation);
			Child->CalculateWorldPosition(Child->LocalPosition);
		}
	}

	void CalculateWorldPosition(const float4& _Local)
	{
		LocalPosition = _Local;
		LocalPosition.w = 1.0f; // 이동을 적용받기 위해서.

		if (nullptr != Parent)
		{
			WorldPosition = LocalPosition * Parent->WorldWorldMat;
		}
		else
		{
			WorldPosition = LocalPosition;
		}

		CollisionPositionSetting();

		LocalPositionMat.Position(LocalPosition);

		for (GameEngineTransform* Child : Childs)
		{
			Child->CalculateWorldPosition(Child->LocalPosition);
		}
	}

	CollisionData CollisionDataObject;

	void CollisionScaleSetting();
	void CollisionRotationSetting();
	void CollisionPositionSetting();
	void CollisionDataSetting();

	virtual void Start() {}
	virtual void Update(float _DeltaTime) {}
	virtual void End() {}


	/////////////////////////// 충돌관련
public:
	static bool SphereToSphere(const GameEngineTransform& _Left, const GameEngineTransform& _Right);

	static bool AABBToAABB(const GameEngineTransform& _Left, const GameEngineTransform& _Right);

	static bool OBBToOBB(const GameEngineTransform& _Left, const GameEngineTransform& _Right);
};

