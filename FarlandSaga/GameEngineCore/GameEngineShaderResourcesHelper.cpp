#include "PreCompile.h"
#include "GameEngineShaderResourcesHelper.h"
#include "GameEnginePixelShader.h"
#include "GameEngineVertexShader.h"
#include "GameEngineConstantBuffer.h"
#include "GameEngineTexture.h"
#include "GameEngineSampler.h"

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

	for (const std::pair<std::string, GameEngineTextureSetter>& Setter : TextureSetterMap)
	{
		Setter.second.Setting();
	}

	for (const std::pair<std::string, GameEngineSamplerSetter>& Setter : SamplerSetterMap)
	{
		Setter.second.Setting();
	}
}

void GameEngineShaderResourcesHelper::ResourcesCheck(GameEngineRenderingPipeLine* _Line)
{
	ShaderCheck(_Line->GetVertexShader());
	ShaderCheck(_Line->GetPixelShader());

}

void Test() {
	int a = 0;
	// 왜 안되는거야!!!!
}

void GameEngineShaderResourcesHelper::ShaderCheck(GameEngineShader* _Shader)
{
	// 픽셀쉐이더와 버텍스 쉐이더에서 transform데이터 같은 중요 상수버퍼의 이름을 똑같이 해서 사용하고 싶다면??????
	for (const std::pair<std::string, GameEngineConstantBufferSetter>& Data : _Shader->ConstantBufferMap)
	{
		std::multimap<std::string, GameEngineConstantBufferSetter>::iterator InsertIter =
			ConstantBufferMap.insert(std::make_pair(Data.first, Data.second));

		GameEngineConstantBufferSetter& Setter = InsertIter->second;

		switch (InsertIter->second.ShaderType)
		{
		case ShaderType::Vertex:
			Setter.SettingFunction = std::bind(&GameEngineConstantBuffer::VSSetting, Setter.Res, Setter.BindPoint);
			break;
		case ShaderType::Pixel:
			Setter.SettingFunction = std::bind(&GameEngineConstantBuffer::PSSetting, Setter.Res, Setter.BindPoint);
			break;
		default:
			break;
		}


	}

	for (const std::pair<std::string, GameEngineTextureSetter>& Data : _Shader->TextureSetterMap)
	{
		std::multimap<std::string, GameEngineTextureSetter>::iterator InsertIter =
			TextureSetterMap.insert(std::make_pair(Data.first, Data.second));

		GameEngineTextureSetter& Setter = InsertIter->second;

		switch (InsertIter->second.ShaderType)
		{
		case ShaderType::Vertex:
			Setter.SettingFunction = std::bind(&GameEngineTexture::VSSetting, Setter.Res, Setter.BindPoint);
			break;
		case ShaderType::Pixel:
			Setter.SettingFunction = std::bind(&GameEngineTexture::PSSetting, Setter.Res, Setter.BindPoint);
			break;
		default:
			break;
		}

	}


	for (const std::pair<std::string, GameEngineSamplerSetter>& Data : _Shader->SamplerSetterMap)
	{
		std::multimap<std::string, GameEngineSamplerSetter>::iterator InsertIter =
			SamplerSetterMap.insert(std::make_pair(Data.first, Data.second));

		GameEngineSamplerSetter& Setter = InsertIter->second;

		switch (InsertIter->second.ShaderType)
		{
		case ShaderType::Vertex:
			Setter.SettingFunction = std::bind(&GameEngineSampler::VSSetting, Setter.Res, Setter.BindPoint);
			break;
		case ShaderType::Pixel:
			Setter.SettingFunction = std::bind(&GameEngineSampler::PSSetting, Setter.Res, Setter.BindPoint);
			break;
		default:
			break;
		}

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

void GameEngineShaderResourcesHelper::SetConstantBufferNew(const std::string& _Name, const void* _Data, UINT _Size)
{
	if (false == IsConstantBufferSetter(_Name))
	{
		MsgBoxAssertString(_Name + " 존재하지 않는 상수버퍼를 세팅하려고 했습니다.");
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

		if (0 == NameStartIter->second.OriginalData.size()
			|| NameStartIter->second.OriginalData.size() != _Size)
		{
			NameStartIter->second.OriginalData.resize(_Size);
		}

		NameStartIter->second.SetData = &NameStartIter->second.OriginalData[0];
		memcpy_s(&NameStartIter->second.OriginalData[0], _Size, _Data, _Size);

		NameStartIter->second.Size = _Size;
	}
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