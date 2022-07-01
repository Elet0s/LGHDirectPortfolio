#include "PreCompile.h"
#include "GameEngineInputLayOut.h"
#include "GameEngineVertexs.h"
#include "GameEngineVertexShader.h"

GameEngineInputLayOut::GameEngineInputLayOut()
{
}

GameEngineInputLayOut::~GameEngineInputLayOut()
{
}


void GameEngineInputLayOut::Create(const GameEngineLayOutDesc& _Desc, GameEngineVertexShader* _Shader)
{
	if (
		S_OK != GameEngineDevice::GetDevice()->CreateInputLayout(
			&_Desc.InputLayOutDesc[0],
			static_cast<UINT>(_Desc.InputLayOutDesc.size()),
			_Shader->BinaryPtr->GetBufferPointer(),
			_Shader->BinaryPtr->GetBufferSize(),
			&InputLayOut)
		)
	{
		MsgBoxAssert("인풋레이아웃 생성에 실패했습니다");
	}



}
