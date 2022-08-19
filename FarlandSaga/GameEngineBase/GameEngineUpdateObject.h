#pragma once
#include <string>
#include <list>
#include "GameEngineTime.h"
#include "GameEngineDebugObject.h"


class GameEngineUpdateObject : public GameEngineDebugObject
{
public:
	GameEngineUpdateObject();
	virtual ~GameEngineUpdateObject();

	GameEngineUpdateObject(const GameEngineUpdateObject& _Other) = delete;
	GameEngineUpdateObject(GameEngineUpdateObject&& _Other) noexcept = delete;
	GameEngineUpdateObject& operator=(const GameEngineUpdateObject& _Other) = delete;
	GameEngineUpdateObject& operator=(GameEngineUpdateObject&& _Other) noexcept = delete;

	inline bool& IsUpdateRef()
	{
		return IsUpdate_;
	}

	inline void On()
	{
		IsUpdate_ = true;
		OnEvent();
	}

	inline void Off()
	{
		IsUpdate_ = false;
		OnEvent();
	}

	inline void OnOffSwitch()
	{
		IsUpdate_ = !IsUpdate_;
		IsUpdate_ == true ? OnEvent() : OffEvent();
	}

	inline bool IsUpdate()
	{
		if (nullptr != Parent)
		{
			return IsUpdate_ && false == IsDeath_ && true == Parent->IsUpdate();
		}
		else
		{
			return IsUpdate_ && false == IsDeath_;
		}

	}

	inline bool IsDeath()
	{
		if (nullptr != Parent)
		{
			return IsDeath_ || true == Parent->IsDeath();
		}
		else {
			return IsDeath_;
		}
	}

	void AddAccTime(float _DeltaTime)
	{
		AccTime_ += _DeltaTime;
	}

	float GetAccTime()
	{
		return AccTime_;
	}

	void ReSetAccTime()
	{
		AccTime_ = 0.0f;
	}

	inline 	void Death()
	{
		IsDeath_ = true;
	}

	void ReleaseUpdate(float _DeltaTime)
	{
		if (false == IsReleaseUpdate_)
		{
			return;
		}

		DeathTime_ -= _DeltaTime;

		if (0.0f >= DeathTime_)
		{
			IsDeath_ = true;
		}
	}

	inline void Death(float _Time)
	{
		IsReleaseUpdate_ = true;
		DeathTime_ = _Time;
	}

	inline int GetOrder()
	{
		return Order_;
	}

	virtual inline void SetOrder(int _Order)
	{
		Order_ = _Order;
	}

	template<typename ParentType>
	ParentType* GetParent()
	{
		return dynamic_cast<ParentType*>(Parent);
	}

	GameEngineUpdateObject* GetParent()
	{
		return Parent;
	}

	template<typename ParentType>
	ParentType* GetRoot()
	{
		return dynamic_cast<ParentType*>(GetRoot());
	}

	GameEngineUpdateObject* GetRoot()
	{
		GameEngineUpdateObject* CurObject = this;

		while (nullptr != CurObject->GetParent())
		{
			CurObject = CurObject->GetParent();
		}

		return CurObject;
	}


	virtual void SetParent(GameEngineUpdateObject* _Parent);
	virtual void DetachObject();

	virtual void ReleaseHierarchy();

	// 이 오브젝트가 프레임구조안에서 돌고 있다.
	virtual void Update(float _DeltaTime) = 0;

	void AllUpdate(float _DeltaTime);

	void AllOnEvent();

	void AllOffEvent();
protected:
	// 이 오브젝트가 동작을 하기 시작했다.
	virtual void OnEvent() {}//레벨체인지 스타트
												//레벨에선 이런개념 액터나 컴포넌트도 갖고있다.
	// 이 오브젝트가 꺼졌다.
	virtual void OffEvent() {}//레벨체인지 엔드

	// 이 오브젝트가 만들어졌다.
	virtual void Start() = 0;

	// 이 오브젝트가 메모리가 삭제된다.
	virtual void End() = 0;

	virtual void ReleaseObject(std::list<GameEngineUpdateObject*>& _RelaseList);

	template<typename ConvertType>
	std::list<ConvertType*> GetConvertChilds()
	{
		std::list<ConvertType*> NewList;

		for (GameEngineUpdateObject* Child : Childs)
		{
			ConvertType* ConvertPtr = dynamic_cast<ConvertType*>(Child);
			if (nullptr != ConvertPtr)
			{
				NewList.push_back(ConvertPtr);
			}
		}

		return NewList;
	}

	std::list<GameEngineUpdateObject*> Childs;

private:
	int Order_;
	bool IsReleaseUpdate_;
	float DeathTime_;
	float AccTime_;

	bool IsUpdate_;
	bool IsDeath_;

	GameEngineUpdateObject* Parent;
};

