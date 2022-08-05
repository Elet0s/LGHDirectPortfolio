#include "PreCompile.h"
#include "GameEngineCoreDebug.h"
#include <GameEngineBase/GameEngineTransform.h>

namespace GameEngineDebug
{
	enum class DebugRenderType
	{
		Sphere,
		Box,
	};

	struct DebugRenderData
	{
		DebugRenderType Type;
		TransformData Data;
	};

	std::vector<DebugRenderData> DebugData;

	void DrawBox(const GameEngineTransform& _Trans)
	{
		// DebugData[0].Data = _Trans.Gettransf
	}

	void DrawBox(float4 _Postion, float4 _Rot, float4 _Scale)
	{
		GameEngineTransform Trans;
		Trans.SetWorldPosition(_Postion);
		Trans.SetWorldRotation(_Rot);
		Trans.SetWorldScale(_Scale);
		// DebugData.push_back(DebugRenderData());
		int a = 0;
	}

	void DrawSphere()
	{

	};

	void Debug3DRender()
	{
		// ±×¸°´Ù

		// DebugData.push_back(DebugRenderData());

		DebugData.clear();
		int a = 0;
	}

};