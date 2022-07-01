#pragma once
#include "GameEngineRes.h"
#include <GameEngineBase/GameEngineMath.h>
#include <vector>
#include <string>
#include <map>
#include <list>

// Ό³Έν :
class GameEngineIndexBuffer : public GameEngineRes<GameEngineIndexBuffer>
{
	friend GameEngineRes<GameEngineIndexBuffer>;

public:
	template<typename IndexType>
	static GameEngineIndexBuffer* Create(const std::string& _Name, const std::vector<IndexType>& _Vertex)
	{
		return Create(_Name, &_Vertex[0], _Vertex.size() * sizeof(IndexType));
	}


	static GameEngineIndexBuffer* Create(const std::string& _Name, const void* _Data, size_t _Size);

private:
	// constrcuter destructer
	GameEngineIndexBuffer();
	~GameEngineIndexBuffer();

	// delete Function
	GameEngineIndexBuffer(const GameEngineIndexBuffer& _Other) = delete;
	GameEngineIndexBuffer(GameEngineIndexBuffer&& _Other) noexcept = delete;
	GameEngineIndexBuffer& operator=(const GameEngineIndexBuffer& _Other) = delete;
	GameEngineIndexBuffer& operator=(GameEngineIndexBuffer&& _Other) noexcept = delete;

protected:
	void BufferCreate(const void* _Data, size_t _Size);


private:
	// nullptr
	D3D11_BUFFER_DESC BufferDesc;

	D3D11_SUBRESOURCE_DATA Data;

	ID3D11Buffer* Buffer;

};

