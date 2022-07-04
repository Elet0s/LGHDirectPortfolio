#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineRes.h"
#include <vector>
#include <string>
#include <map>
#include <list>
#include "GameEngineVertexs.h"

// Ό³Έν :
class GameEngineVertexBuffer : public GameEngineRes<GameEngineVertexBuffer>
{
public:
	friend GameEngineRes<GameEngineVertexBuffer>;

public:
	template<typename VertexType>
	static GameEngineVertexBuffer* Create(const std::string& _Name, const std::vector<VertexType>& _Vertex)
	{
		return Create(_Name, &_Vertex[0], static_cast<UINT>(_Vertex.size()), static_cast<UINT>(sizeof(VertexType)), VertexType::LayOut);
	}


	static GameEngineVertexBuffer* Create(const std::string& _Name, const void* _Data, UINT _VertexSize, UINT _VertexCount, const GameEngineLayOutDesc& _LayOut);
	// static GameEngineVertexBuffer* Create(const std::vector<float4>& _Vertex);

	const GameEngineLayOutDesc* GetLayOutDesc()
	{
		return LayOutDesc;
	}

	void Setting();

private:
	// constrcuter destructer
	GameEngineVertexBuffer();
	~GameEngineVertexBuffer();

	// delete Function
	GameEngineVertexBuffer(const GameEngineVertexBuffer& _Other) = delete;
	GameEngineVertexBuffer(GameEngineVertexBuffer&& _Other) noexcept = delete;
	GameEngineVertexBuffer& operator=(const GameEngineVertexBuffer& _Other) = delete;
	GameEngineVertexBuffer& operator=(GameEngineVertexBuffer&& _Other) noexcept = delete;



protected:
	void BufferCreate(const void* _Data, UINT _VertexSize, UINT _VertexCount);


private:
	// nullptr
	D3D11_BUFFER_DESC BufferDesc;

	ID3D11Buffer* Buffer;

	UINT VertexCount;

	UINT VertexSize;

	UINT OffSet;

	const GameEngineLayOutDesc* LayOutDesc;

};

