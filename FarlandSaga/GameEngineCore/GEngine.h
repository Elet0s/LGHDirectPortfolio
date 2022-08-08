#pragma once
#include "GameEngineCore.h"

// ���� : ����� GameEngineCore�� Ŭ�������� GEngine�� ������� �ʾƾ� �Ѵ�.
//        ���� => �� Ŭ������ ��ɵ��� ö���ϰ� �������鿡�� �����Ǵ� �̴ϴ�.
class GEngine
{
	static bool CollisionDebug;

public:
	static void ChangeLevel(std::string _Name);
	static void CollisionDebugOn();
	static void CollisionDebugOff();
	static void CollisionDebugSwitch();

	static bool IsCollisionDebug();


protected:

private:
	GEngine();
	virtual ~GEngine() = 0;
	GEngine(const GEngine& _Other) = delete;
	GEngine(GEngine&& _Other) noexcept = delete;
	GEngine& operator=(const GEngine& _Other) = delete;
	GEngine& operator=(GEngine&& _Other) noexcept = delete;

};

