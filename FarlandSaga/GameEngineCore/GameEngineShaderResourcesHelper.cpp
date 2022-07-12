#include "PreCompile.h"
#include "GameEngineShaderResourcesHelper.h"
#include "GameEnginePixelShader.h"
#include "GameEngineVertexShader.h"

GameEngineShaderResourcesHelper::GameEngineShaderResourcesHelper()
{
}

GameEngineShaderResourcesHelper::~GameEngineShaderResourcesHelper()
{
}

void GameEngineShaderResourcesHelper::AllResourcesSetting()
{
	for (const std::pair<std::string, GameEngineConstantBufferSetter>& Setter : ConstantBufferMap)
	{
		Setter.second.Setting();
	}
}

void GameEngineShaderResourcesHelper::ResourcesCheck(GameEngineRenderingPipeLine* _Line)
{
	ShaderCheck(_Line->GetVertexShader());
	ShaderCheck(_Line->GetPixelShader());

}

void GameEngineShaderResourcesHelper::ShaderCheck(GameEngineShader* _Shader)
{
	// 픽셀쉐이더와 버텍스 쉐이더에서 transform데이터 같은 중요 상수버퍼의 이름을 똑같이 해서 사용하고 싶다면??????
	for (const std::pair<std::string, GameEngineConstantBufferSetter>& Data : _Shader->ConstantBufferMap)
	{
		ConstantBufferMap.insert(std::make_pair(Data.first, Data.second));
	}

	for (const std::pair<std::string, GameEngineTextureSetter>& Data : _Shader->TextureSetterMap)
	{
		TextureSetterMap.insert(std::make_pair(Data.first, Data.second));
	}


}

bool GameEngineShaderResourcesHelper::IsConstantBufferSetter(const std::string& _Name)
{
	std::string Key = GameEngineString::ToUpperReturn(_Name);

	if (ConstantBufferMap.end() != ConstantBufferMap.find(Key))
	{
		return true;
	}

	return false;
}

void GameEngineShaderResourcesHelper::SetConstantBufferLink(
	const std::string& _Name,
	const void* _Data,
	UINT _Size)
{
	if (false == IsConstantBufferSetter(_Name))
	{

		MsgBox("존재하지 않는 상수버퍼를 세팅하려고 했습니다.");
		return;
	}

	if (16 > _Size)
	{

		MsgBox("최소한 16바이트 이상의 세팅을 해줘야 합니다.");
		return;
	}

	std::string Name = GameEngineString::ToUpperReturn(_Name);

	std::multimap<std::string, GameEngineConstantBufferSetter>::iterator NameStartIter
		= ConstantBufferMap.lower_bound(Name);

	std::multimap<std::string, GameEngineConstantBufferSetter>::iterator NameEndIter
		= ConstantBufferMap.upper_bound(Name);

	for (; NameStartIter != NameEndIter; ++NameStartIter)
	{
		// 트랜스폼이 바뀌면
		NameStartIter->second.SetData = _Data;
		NameStartIter->second.Size = _Size;
	}

}