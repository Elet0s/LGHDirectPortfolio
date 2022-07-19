#include "PreCompile.h"
#include "GameEngineRenderTarget.h"
#include "GameEngineDepthStencilTexture.h"

GameEngineRenderTarget::GameEngineRenderTarget()
	: DepthStencilView(nullptr)
{
}

GameEngineRenderTarget::~GameEngineRenderTarget()
{
}

//GameEngineRenderTarget* GameEngineRenderTarget::Create(const std::string& _Name, ID3D11Texture2D* _Texture) 
//{
//
//}

GameEngineRenderTarget* GameEngineRenderTarget::Create(const std::string& _Name)
{
	return CreateResName(_Name);
}

void GameEngineRenderTarget::CreateRenderTargetTexture(ID3D11Texture2D* _Texture, float4 _Color)
{
	GameEngineTexture* NewTexture = GameEngineTexture::Create(_Texture);

	RenderTargets.push_back(NewTexture);
	RenderTargetViews.push_back(NewTexture->CreateRenderTargetView());
	ClearColors.push_back(_Color);
}

void GameEngineRenderTarget::Clear()
{
	for (size_t i = 0; i < RenderTargetViews.size(); i++)
	{
		GameEngineDevice::GetContext()->ClearRenderTargetView(RenderTargetViews[i], ClearColors[i].Arr1D);
	}

	if (nullptr != DepthStencilView)
	{
		// GameEngineDevice::GetContext()->ClearDepthStencilView();
	}
}

void GameEngineRenderTarget::CreateDepthTexture(int _Index)
{
	DepthTexture = GameEngineDepthStencilTexture::Create(RenderTargets[_Index]->GetScale());
}

void GameEngineRenderTarget::Setting()
{
	// int* NewInt = new int[10];

	// GameEngineRenderTarget** NewInt = new GameEngineRenderTarget*[10]

	if (0 == RenderTargetViews.size())
	{
		MsgBoxAssert("����Ÿ�ٺ䰡 �������� �ʴ� ����Ÿ���� �����Ϸ��� �߽��ϴ�.");
	}

	GameEngineDevice::GetContext()->OMSetRenderTargets(static_cast<UINT>(RenderTargetViews.size()), &RenderTargetViews[0], DepthStencilView);
}