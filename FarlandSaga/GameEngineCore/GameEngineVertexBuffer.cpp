#include "PreCompile.h"
#include "GameEngineVertexBuffer.h"
#include <GameEngineBase/GameEngineString.h>

GameEngineVertexBuffer::GameEngineVertexBuffer()
	: Buffer(nullptr)
	, BufferDesc{}
{
}

GameEngineVertexBuffer::~GameEngineVertexBuffer()
{
	if (nullptr != Buffer)
	{
		Buffer->Release();
	}
}


GameEngineVertexBuffer* GameEngineVertexBuffer::Create(const std::string& _Name, const void* _Data, size_t _Size)
{
	GameEngineVertexBuffer* NewRes = CreateResName(_Name);

	D3D11_SUBRESOURCE_DATA Data;
	Data.pSysMem = _Data;

	//UINT ByteWidth; // �Ҵ��Ϸ��� ������ ũ��
	//D3D11_USAGE Usage; // �Ҵ��Ϸ��� ������ �׼��� ���Ѱ� �뵵
	//UINT BindFlags; // ������ �������� �뵵
	//UINT CPUAccessFlags; // CPU���� �׼��� �Ҽ� �ִ���
	//UINT MiscFlags; // 
	//UINT StructureByteStride;

	NewRes->BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	NewRes->BufferDesc.ByteWidth = static_cast<UINT>(_Size);
	NewRes->BufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
	// BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_READ;
	NewRes->BufferDesc.CPUAccessFlags = 0;

	// �߰� �ɼ��ε� ���� �����̴ϴ�.
	NewRes->BufferDesc.MiscFlags = 0;
	// ���ؽ� ���ۿ����� �������� �ʿ䵵 ����.
	NewRes->BufferDesc.StructureByteStride = 0;

	if (S_OK != GameEngineDevice::GetDevice()->CreateBuffer(&NewRes->BufferDesc, &Data, &NewRes->Buffer))
	{
		MsgBoxAssert("���ؽ� ���� ������ �����߽��ϴ�.");
	}

	return NewRes;
}