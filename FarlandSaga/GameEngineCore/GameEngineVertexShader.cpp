#include "PreCompile.h"
#include "GameEngineVertexShader.h"
#include <GameEngineBase/GameEngineString.h>

GameEngineVertexShader::GameEngineVertexShader()
	: ShaderPtr(nullptr)
{
}

GameEngineVertexShader::~GameEngineVertexShader()
{
	if (nullptr != ShaderPtr)
	{
		ShaderPtr->Release();
		ShaderPtr = nullptr;
	}
}

// Color.hlsl
// ���� ���̴����ϳ���
// ���ؽ����̴��� 2�� �ۼ����մϴ�.

// Color_VS

GameEngineVertexShader* GameEngineVertexShader::Load(std::string _Path, std::string _EntryPoint, UINT _VersionHigh /*= 5*/, UINT _VersionLow /*= 0*/)
{
	return Load(_Path, GameEnginePath::GetFileName(_Path), _EntryPoint, _VersionHigh, _VersionLow);
}


GameEngineVertexShader* GameEngineVertexShader::Load(std::string _Path, std::string _Name, std::string _EntryPoint, UINT _VersionHigh = 5, UINT _VersionLow = 0)
{
	GameEngineVertexShader* NewRes = CreateResName(_Name);
	NewRes->ShaderCompile(_Path, _EntryPoint, _VersionHigh, _VersionLow);

	return nullptr;
}


void GameEngineVertexShader::ShaderCompile(std::string _Path, std::string _EntryPoint, UINT _VersionHigh, UINT _VersionLow)
{
	CreateVersion("vs", _VersionHigh, _VersionLow);
	SetEntryPoint(_EntryPoint);

	unsigned int Flag = 0;

#ifdef _DEBUG
	Flag = D3D10_SHADER_DEBUG;
#endif

	// ���̴������� �⺻������ ����� �Ʒ��� ���� ��ġ�� �Ǿ ���� �Ǿ��ִµ�
	// 1000
	// 0100
	// 2010
	// 0301

	// 1020
	// 0103
	// 0010
	// 0001


	Flag |= D3DCOMPILE_PACK_MATRIX_ROW_MAJOR;

	ID3DBlob* Error;

	std::wstring UnicodePath = GameEngineString::AnsiToUnicodeReturn(_Path);

	// ���̴� 
	if (D3DCompileFromFile(
		UnicodePath.c_str(), // ���� ���
		nullptr,  // ��ũ�� ()
		nullptr,  // ��� ()
		_EntryPoint.c_str(), // ������ COLOR_VS(
		Version.c_str(),  // vs_5_0
		Flag,
		0,
		&BinaryPtr,
		&Error)
		)
	{
		std::string ErrorText = reinterpret_cast<char*>(Error->GetBufferPointer());
		MsgBoxAssertString(ErrorText);
		return;
	}

	// �̹� �� �����ϵ� ���̴� �ڵ��� ���̳ʸ��� �־��༭ �����ϴ� ����� �٤��ϴ�.
	if (S_OK != GameEngineDevice::GetDevice()->CreateVertexShader(
		BinaryPtr->GetBufferPointer(),
		BinaryPtr->GetBufferSize(),
		nullptr,
		&ShaderPtr))
	{
		MsgBoxAssert("���ؽ� ���̴� �ڵ� ������ �����߽��ϴ�.");
	}


}