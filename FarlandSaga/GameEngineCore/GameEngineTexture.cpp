#include "PreCompile.h"
#include "GameEngineTexture.h"

GameEngineTexture::GameEngineTexture()
	: Texture2D(nullptr)
	, RenderTargetView(nullptr)
	, ShaderResourceView(nullptr)
{
}

GameEngineTexture::~GameEngineTexture()
{
	if (nullptr != ShaderResourceView)
	{
		ShaderResourceView->Release();
	}

	if (nullptr != RenderTargetView)
	{
		RenderTargetView->Release();
	}

	if (nullptr != Texture2D)
	{
		Texture2D->Release();
	}
}

ID3D11RenderTargetView* GameEngineTexture::CreateRenderTargetView()
{
	if (nullptr != RenderTargetView)
	{
		return RenderTargetView;
	}

	if (S_OK != GameEngineDevice::GetDevice()->CreateRenderTargetView(Texture2D, nullptr, &RenderTargetView))
	{
		MsgBoxAssert("����Ÿ�� ������ �����߽��ϴ�.");
	}

	return RenderTargetView;
}

GameEngineTexture* GameEngineTexture::Create(ID3D11Texture2D* _Texture)
{
	GameEngineTexture* NewRes = CreateResUnName();
	NewRes->Texture2D = _Texture;
	return NewRes;
}

GameEngineTexture* GameEngineTexture::Create(const std::string& _Name, ID3D11Texture2D* _Texture)
{
	GameEngineTexture* NewRes = CreateResName(_Name);
	NewRes->Texture2D = _Texture;
	return NewRes;
}

GameEngineTexture* GameEngineTexture::Load(const std::string& _Path, const std::string& _Name)
{
	GameEngineTexture* NewRes = CreateResName(_Name);
	NewRes->TextureLoad(_Path);
	return NewRes;
}

void GameEngineTexture::TextureLoad(const std::string& _Path)
{
	std::string Ex = GameEngineString::ToUpperReturn(GameEnginePath::GetExtension(_Path));

	std::wstring LoadPath = GameEngineString::AnsiToUnicodeReturn(_Path);

	if (Ex == "TGA")
		// && S_OK != DirectX::LoadFromTGAFile(LoadPath.c_str(), DirectX::WIC_FLAGS_NONE, &Metadata, Image))
	{
		MsgBoxAssertString(_Path + "���� ó������ ���� �̹��� �����Դϴ�.");
	}
	else if (Ex == "DDS")
		// && S_OK != DirectX::LoadFromDDSFile(LoadPath.c_str(), DirectX::WIC_FLAGS_NONE, &Metadata, Image))
	{
		MsgBoxAssertString(_Path + "���� ó������ ���� �̹��� �����Դϴ�.");
	}
	else if (S_OK != DirectX::LoadFromWICFile(LoadPath.c_str(), DirectX::WIC_FLAGS_NONE, &Metadata, Image))
	{
		MsgBoxAssertString(_Path + "�ε忡 �����߽��ϴ�.");
	}

	// GameEngineDevice::GetDevice()->�����ؽ�ó�Լ�

	if (S_OK != DirectX::CreateShaderResourceView(
		GameEngineDevice::GetDevice(),
		Image.GetImages(),
		Image.GetImageCount(),
		Image.GetMetadata(),
		&ShaderResourceView
	))
	{
		MsgBoxAssertString(_Path + "���̴� ���ҽ� ������ �����߽��ϴ�.");
	}
}

void GameEngineTexture::VSSetting(int _BindPoint)
{
	if (nullptr == ShaderResourceView)
	{
		MsgBoxAssert("�������� �ʴ� �ؽ�ó�� ����� �� �����ϴ�.");
	}

	GameEngineDevice::GetContext()->VSSetShaderResources(_BindPoint, 1, &ShaderResourceView);
}

void GameEngineTexture::PSSetting(int _BindPoint)
{
	if (nullptr == ShaderResourceView)
	{
		MsgBoxAssert("�������� �ʴ� �ؽ�ó�� ����� �� �����ϴ�.");
	}

	GameEngineDevice::GetContext()->PSSetShaderResources(_BindPoint, 1, &ShaderResourceView);
}