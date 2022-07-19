#pragma once
#include "GameEngineCore.h"

// ���� : ����� GameEngineCore�� Ŭ�������� GEngine�� ������� �ʾƾ� �Ѵ�.
//        ���� => �� Ŭ������ ��ɵ��� ö���ϰ� �������鿡�� �����Ǵ� �̴ϴ�.
class GEngine
{
public:
	static void ChangeLevel(std::string _Name);


protected:

private:
	GEngine();
	virtual ~GEngine() = 0;

	GEngine(const GEngine& _Other) = delete;
	GEngine(GEngine&& _Other) noexcept = delete;
	GEngine& operator=(const GEngine& _Other) = delete;
	GEngine& operator=(GEngine&& _Other) noexcept = delete;

};

