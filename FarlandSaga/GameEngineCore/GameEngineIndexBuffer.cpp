#include "PreCompile.h"
#include "GameEngineIndexBuffer.h"
#include <GameEngineBase/GameEngineString.h>

GameEngineIndexBuffer::GameEngineIndexBuffer()
	: Buffer(nullptr)
{
}

GameEngineIndexBuffer::~GameEngineIndexBuffer()
{
	if (nullptr != Buffer)
	{
		Buffer->Release();
		Buffer = nullptr;
	}
}


GameEngineIndexBuffer* GameEngineIndexBuffer::Create(const std::string& _Name, const void* _Data, size_t _Size)
{
	GameEngineIndexBuffer* NewRes = CreateResName(_Name);
	NewRes->BufferCreate(_Data, _Size);
	return NewRes;
}

void GameEngineIndexBuffer::BufferCreate(const void* _Data, size_t _Size)
{
	D3D11_SUBRESOURCE_DATA Data;
	Data.pSysMem = _Data;

	BufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	BufferDesc.ByteWidth = static_cast<UINT>(_Size);
	BufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
	BufferDesc.CPUAccessFlags = 0;

	BufferDesc.MiscFlags = 0;
	BufferDesc.StructureByteStride = 0;

	if (S_OK != GameEngineDevice::GetDevice()->CreateBuffer(&BufferDesc, &Data, &Buffer))
	{
		MsgBoxAssert("버텍스 버퍼 생성에 실패했습니다.");
	}
}