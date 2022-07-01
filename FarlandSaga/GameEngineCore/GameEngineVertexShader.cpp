#include "PreCompile.h"
#include "GameEngineVertexShader.h"

GameEngineVertexShader::GameEngineVertexShader()
{
}

GameEngineVertexShader::~GameEngineVertexShader()
{
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
	NewRes->CreateVersion("vs", _VersionHigh, _VersionLow);
	NewRes->SetEntryPoint(_EntryPoint);

	return nullptr;
}
