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
}


GameEngineVertexBuffer* GameEngineVertexBuffer::Create(const std::string& _Name, const void* _Data, size_t _Size)
{
	GameEngineVertexBuffer* NewRes = CreateResName(_Name);

	D3D11_SUBRESOURCE_DATA Data;
	Data.pSysMem = _Data;

	//UINT ByteWidth; // 할당하려는 버퍼의 크기
	//D3D11_USAGE Usage; // 할당하려는 버퍼의 액세스 권한과 용도
	//UINT BindFlags; // 버퍼의 랜더링적 용도
	//UINT CPUAccessFlags; // CPU에서 액세스 할수 있는지
	//UINT MiscFlags; // 
	//UINT StructureByteStride;

	NewRes->BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	NewRes->BufferDesc.ByteWidth = static_cast<UINT>(_Size);
	NewRes->BufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
	// BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_READ;
	NewRes->BufferDesc.CPUAccessFlags = 0;

	// 추가 옵션인데 쓰지 않을겁니다.
	NewRes->BufferDesc.MiscFlags = 0;
	// 버텍스 버퍼에서는 세팅해줄 필요도 없다.
	NewRes->BufferDesc.StructureByteStride = 0;

	if (S_OK != GameEngineDevice::GetDevice()->CreateBuffer(&NewRes->BufferDesc, &Data, &NewRes->Buffer))
	{
		MsgBoxAssert("버텍스 버퍼 생성에 실패했습니다.");
	}

	return NewRes;
}