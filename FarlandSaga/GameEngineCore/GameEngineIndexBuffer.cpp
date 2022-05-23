#include "GameEngineIndexBuffer.h"
#include <GameEngineBase/GameEngineString.h>

GameEngineIndexBuffer::GameEngineIndexBuffer()
{
}

GameEngineIndexBuffer::~GameEngineIndexBuffer()
{
}


GameEngineIndexBuffer* GameEngineIndexBuffer::CreateRes(const std::vector<int>& _Indexs, const std::string& _Name /*= ""*/)
{
	std::string Name = GameEngineString::ToUpperReturn(_Name);

	GameEngineIndexBuffer* NewMesh = new GameEngineIndexBuffer();
	NewMesh->SetName(Name);
	NewMesh->Indexs = _Indexs;
	return NewMesh;
}

void GameEngineIndexBuffer::Create(const std::string& _Name, const std::vector<int>& _Indexs)
{
	GameEngineIndexBuffer* NewMesh = CreateRes(_Indexs, _Name);
	NamedRes.insert(std::make_pair(NewMesh->GetNameCopy(), NewMesh));
}

void GameEngineIndexBuffer::Create(const std::vector<int>& _Indexs)
{
	GameEngineIndexBuffer* NewMesh = CreateRes(_Indexs);
	UnNamedRes.push_back(NewMesh);
}