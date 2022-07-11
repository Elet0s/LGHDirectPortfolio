#include "PreCompile.h"
#include "GameEngineConstantBuffer.h"

std::map<std::string, std::map<int, GameEngineConstantBuffer*>> GameEngineConstantBuffer::NamedRes;


GameEngineConstantBuffer::GameEngineConstantBuffer()
{
}

GameEngineConstantBuffer::~GameEngineConstantBuffer()
{
	if (nullptr != Buffer)
	{
		Buffer->Release();
		Buffer = nullptr;
	}
}



void GameEngineConstantBuffer::Create(const D3D11_SHADER_BUFFER_DESC& _Desc, ID3D11ShaderReflectionConstantBuffer* _CBufferPtr)
{
	ShaderDesc = _Desc;

	BufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	BufferDesc.ByteWidth = ShaderDesc.Size;

	BufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
	BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

	BufferDesc.MiscFlags = 0;
	BufferDesc.StructureByteStride = 0;

	if (S_OK != GameEngineDevice::GetDevice()->CreateBuffer(&BufferDesc, nullptr, &Buffer))
	{
		MsgBoxAssert("������� ������ �����߽��ϴ�.");
	}
}

void GameEngineConstantBuffer::ChangeData(const void* _Data, size_t _Size)
{
	if (BufferDesc.ByteWidth != _Size)
	{
		MsgBoxAssert("��������� ����Ʈ ũ�Ⱑ ���� ���� �ʽ��ϴ�.");
	}

	memset(&SettingResources, 0, sizeof(SettingResources));

	// � �׷��� ���ҽ��� �������� �ƹ��� �ǵ��� ���ϰ� ��.
	// �׷���ī�带 ������ ����ϴ�.
	GameEngineDevice::GetContext()->Map(Buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &SettingResources);

	if (nullptr == SettingResources.pData)
	{
		MsgBoxAssert("�׷���ī�� ���ۿ� �������� ���߽��ϴ�..");
	}

	memcpy_s(SettingResources.pData, BufferDesc.ByteWidth, _Data, BufferDesc.ByteWidth);


	// ������ �ٽ� �ݾ���� �մϴ�.
	GameEngineDevice::GetContext()->Unmap(Buffer, 0);
}