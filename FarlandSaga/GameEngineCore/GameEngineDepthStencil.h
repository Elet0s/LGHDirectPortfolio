#pragma once
#include "GameEngineRes.h"

// �������ٽ� �����̶�
// �������ٽ� �ؽ�ó��



// ���� : ���� �ȼ����̴��� ��°���� ����Ÿ�ٿ� ����Ҷ� ���� ���̰� ���� �������� ���� ó��
class GameEngineDepthStencil : public GameEngineRes<GameEngineDepthStencil>
{
	//public:
	//	static GameEngineDepthStencil* Create(const float4 _Scale);

public:
	GameEngineDepthStencil();
	~GameEngineDepthStencil();

	GameEngineDepthStencil(const GameEngineDepthStencil& _Other) = delete;
	GameEngineDepthStencil(GameEngineDepthStencil&& _Other) noexcept = delete;
	GameEngineDepthStencil& operator=(const GameEngineDepthStencil& _Other) = delete;
	GameEngineDepthStencil& operator=(GameEngineDepthStencil&& _Other) noexcept = delete;

protected:

private:

};

