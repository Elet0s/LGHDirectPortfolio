#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include <GameEngineCore/GameEngineCore.h>

// ���� : ���α׷� ��ü�� �����ϰ� �Ѵ�.
class ContentsCore : public GameEngineCore
{
public:
	ContentsCore();
	~ContentsCore();

	ContentsCore(const ContentsCore& _Other) = delete;
	ContentsCore(ContentsCore&& _Other) noexcept = delete;
	ContentsCore& operator=(const ContentsCore& _Other) = delete;
	ContentsCore& operator=(ContentsCore&& _Other) noexcept = delete;

	// float4 StartWindowSize() override { return { 800.0f, 600.0f }; } ;
	// float4 StartWindowPosition() override { return { -2000,0 }; };


	std::string GetWindowTitle() override
	{
		return "MyGame";
	}

protected:
	void Start() override;

	// �� ���α׷��� ��� ��Ȳ������ ��� Update�ϸ鼭 üũ������ �ִٸ� ���⼭ �Ѵ�.
	// ������ ���� ������ �׷����� ����. ������ ���� �����̰� ���� ����Ű�� ������ �����Ѵ�.
	// Ÿ��Ʋ�� �ѱ�ų� �̷�
	void Update(float _DeltaTime) override;

	void End() override;

private:

};

