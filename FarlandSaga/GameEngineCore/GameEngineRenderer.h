#pragma once
#include "GameEngineTransformComponent.h"
#include "GameEngineLevel.h"

struct RenderOption
{
	float DeltaTime = 0.0f;
	float SumDeltaTime = 0.0f;
	int Temp0;
	int Temp1;
};
//
//class GameEngineRenderSet 
//{
//public:
//    // �̹� ������� ������ ������������ ���ͼ� ����.
//    GameEngineRenderingPipeLine* PipeLine;
//    GameEngineShaderResourcesHelper ShaderHelper;
//
//
//
//};

class GameEngineRenderingPipeLine;
class GameEngineRenderer : public GameEngineTransformComponent
{
	friend class GameEngineLevel;
	friend class GameEngineCamera;

public:
	RenderOption renderOption;

	GameEngineRenderer();
	~GameEngineRenderer();

	GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

	// float4x4 ViewPort;
	void ChangeCamera(CAMERAORDER _Order);

	GameEngineRenderingPipeLine* GetClonePipeLine(GameEngineRenderingPipeLine* _Rendering);

	inline int GetRenderingOrder()
	{
		return RenderingOrder;
	}

	void SetRenderingOrder(int _Order);

	virtual void InstancingOn()
	{
		IsInstancing = true;
	};

protected:
	virtual void Start();
	virtual void Update(float _DeltaTime) {}
	virtual void End() {}

	void PushRendererToMainCamera();
	void PushRendererToUICamera();


	class GameEngineCamera* Camera;
	CAMERAORDER CameraOrder;
	int RenderingOrder;
	bool IsInstancing;

private:
	virtual void Render(float _DeltaTime) = 0;

};

