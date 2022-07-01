#include "PreCompile.h"
#include "GameEngineVertexShader.h"

GameEngineVertexShader::GameEngineVertexShader()
{
}

GameEngineVertexShader::~GameEngineVertexShader()
{
}

// Color.hlsl
// 같은 쉐이더파일내에
// 버텍스쉐이더를 2개 작성못합니다.

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
