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
	// �ȼ����̴��� ���ؽ� ���̴����� transform������ ���� �߿� ��������� �̸��� �Ȱ��� �ؼ� ����ϰ� �ʹٸ�??????
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

		MsgBox("�������� �ʴ� ������۸� �����Ϸ��� �߽��ϴ�.");
		return;
	}

	if (16 > _Size)
	{

		MsgBox("�ּ��� 16����Ʈ �̻��� ������ ����� �մϴ�.");
		return;
	}

	std::string Name = GameEngineString::ToUpperReturn(_Name);

	std::multimap<std::string, GameEngineConstantBufferSetter>::iterator NameStartIter
		= ConstantBufferMap.lower_bound(Name);

	std::multimap<std::string, GameEngineConstantBufferSetter>::iterator NameEndIter
		= ConstantBufferMap.upper_bound(Name);

	for (; NameStartIter != NameEndIter; ++NameStartIter)
	{
		// Ʈ�������� �ٲ��
		NameStartIter->second.SetData = _Data;
		NameStartIter->second.Size = _Size;
	}

}