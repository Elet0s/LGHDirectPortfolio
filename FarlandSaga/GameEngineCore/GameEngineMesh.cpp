#include "GameEngineMesh.h"
#include "GameEngineBase/GameEngineString.h"

GameEngineMesh::GameEngineMesh()
{
}

GameEngineMesh::~GameEngineMesh()
{
}

GameEngineMesh* GameEngineMesh::CreateRes(const std::vector<float4>& _Vertex, const std::string& _Name /*= ""*/)
{
	std::string Name = GameEngineString::ToUpperReturn(_Name);

	GameEngineMesh* NewMesh = new GameEngineMesh();
	NewMesh->SetName(Name);
	NewMesh->Vertex = _Vertex;
	return NewMesh;
}

void GameEngineMesh::Create(const std::string& _Name, const std::vector<float4>& _Vertex)
{
	GameEngineMesh* NewMesh = CreateRes(_Vertex, _Name);
	NamedRes.insert(std::make_pair(NewMesh->GetNameCopy(), NewMesh));
}

void GameEngineMesh::Create(const std::vector<float4>& _Vertex)
{
	GameEngineMesh* NewMesh = CreateRes(_Vertex);
	UnNamedRes.push_back(NewMesh);
}