#pragma once
#include "GameEngineDevice.h"
#include "GameEngineRes.h"

class GameEngineLayOutDesc;
class GameEngineVertexShader;
class GameEngineInputLayOut : public GameEngineRes<GameEngineInputLayOut>
{
public:
	static GameEngineInputLayOut* Create(const GameEngineLayOutDesc& _Desc, GameEngineVertexShader* _Shader);


public:
	GameEngineInputLayOut();
	~GameEngineInputLayOut();

	GameEngineInputLayOut(const GameEngineInputLayOut& _Other) = delete;
	GameEngineInputLayOut(GameEngineInputLayOut&& _Other) noexcept = delete;
	GameEngineInputLayOut& operator=(const GameEngineInputLayOut& _Other) = delete;
	GameEngineInputLayOut& operator=(GameEngineInputLayOut&& _Other) noexcept = delete;

	void CreateRes(const GameEngineLayOutDesc& _Desc, GameEngineVertexShader* _Shader);

	void Setting();

protected:

private:
	ID3D11InputLayout* InputLayOut;


};

