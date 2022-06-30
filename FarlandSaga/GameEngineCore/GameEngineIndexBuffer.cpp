#include "PreCompile.h"
#include "GameEngineIndexBuffer.h"
#include <GameEngineBase/GameEngineString.h>

GameEngineIndexBuffer::GameEngineIndexBuffer()
{
}

GameEngineIndexBuffer::~GameEngineIndexBuffer()
{
}


GameEngineIndexBuffer* GameEngineIndexBuffer::Create(const std::string& _Name, const std::vector<int>& _Indexs)
{
	GameEngineIndexBuffer* NewRes = CreateResName(_Name);
	NewRes->Indexs = _Indexs;
	return NewRes;
}

GameEngineIndexBuffer* GameEngineIndexBuffer::Create(const std::vector<int>& _Indexs)
{
	GameEngineIndexBuffer* NewRes = CreateResUnName();
	NewRes->Indexs = _Indexs;
	return NewRes;
}