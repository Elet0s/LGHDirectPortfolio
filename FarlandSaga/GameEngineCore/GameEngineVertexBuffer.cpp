#include "GameEngineVertexBuffer.h"
#include <GameEngineBase/GameEngineString.h>

GameEngineVertexBuffer::GameEngineVertexBuffer()
{
}

GameEngineVertexBuffer::~GameEngineVertexBuffer()
{
}


GameEngineVertexBuffer* GameEngineVertexBuffer::CreateRes(const std::vector<float4>& _Vertex, const std::string& _Name /*= ""*/)
{
	std::string Name = GameEngineString::ToUpperReturn(_Name);

	GameEngineVertexBuffer* NewMesh = new GameEngineVertexBuffer();
	NewMesh->SetName(Name);
	NewMesh->Vertexs = _Vertex;
	return NewMesh;
}


void GameEngineVertexBuffer::Create(const std::string& _Name, const std::vector<float4>& _Vertex)
{
	GameEngineVertexBuffer* NewMesh = CreateRes(_Vertex, _Name);
	NamedRes.insert(std::make_pair(NewMesh->GetNameCopy(), NewMesh));
}

void GameEngineVertexBuffer::Create(const std::vector<float4>& _Vertex)
{
	GameEngineVertexBuffer* NewMesh = CreateRes(_Vertex);
	UnNamedRes.push_back(NewMesh);
}