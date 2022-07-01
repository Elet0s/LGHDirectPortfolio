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
	NewRes->BufferCreate(_Data, _Size);
	return NewRes;
}

void GameEngineVertexBuffer::BufferCreate(const void* _Data, size_t _Size)
{
	D3D11_SUBRESOURCE_DATA Data;
	Data.pSysMem = _Data;

	//UINT ByteWidth; // �Ҵ��Ϸ��� ������ ũ��
	//D3D11_USAGE Usage; // �Ҵ��Ϸ��� ������ �׼��� ���Ѱ� �뵵
	//UINT BindFlags; // ������ �������� �뵵
	//UINT CPUAccessFlags; // CPU���� �׼��� �Ҽ� �ִ���
	//UINT MiscFlags; // 
	//UINT StructureByteStride;

	BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	BufferDesc.ByteWidth = static_cast<UINT>(_Size);
	BufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
	// BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_READ;
	BufferDesc.CPUAccessFlags = 0;

	// �߰� �ɼ��ε� ���� �����̴ϴ�.
	BufferDesc.MiscFlags = 0;
	// ���ؽ� ���ۿ����� �������� �ʿ䵵 ����.
	BufferDesc.StructureByteStride = 0;

	if (S_OK != GameEngineDevice::GetDevice()->CreateBuffer(&BufferDesc, &Data, &Buffer))
	{
		MsgBoxAssert("���ؽ� ���� ������ �����߽��ϴ�.");
	}
}