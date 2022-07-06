// #include "myshader.hlsli"

// SV_POSITION �ø�ƽ
// �׷���ī�忡�� �̳༮�� �̷� �η��ϱ� �ϰ� �ڵ����� ó���ϴ� �༮�� ������ �ϰ�.

// t1

// Create("TransformData");

cbuffer TransformData : register(b0)
{
    float4 LocalPosition;
    float4 LocalRotation;
    float4 LocalScaling;
    
    float4 WorldPosition;
    float4 WorldRotation;
    float4 WorldScaling;
    
    float4x4 LocalPositionMatrix;
    float4x4 LocalRotationMatrix;
    float4x4 LocalScalingMatrix;
    
    float4x4 LocalWorldMatrix;
    float4x4 WorldWorldMatrix;
    float4x4 View;
    float4x4 Projection;
    
    float4x4 WorldView;
    float4x4 WorldViewProjection;
};

struct Input
{
    float4 Pos : POSITION;
    float4 Color : COLOR;
};

struct Output
{
    float4 Pos : SV_POSITION;
    float4 Color : COLOR;
};

// 1000
// 0100
// 2010
// 0301

// 1020
// 0103
// 0010
// 0001

Output Color_VS(Input _Input)
{
    // ���̴��� ��쿡�� ��κ��� ��Ȳ���� ����ȯ�� �����ϴ�.
    // 0
    Output NewOutPut = (Output) 0;
    NewOutPut.Pos = _Input.Pos;
    NewOutPut.Pos.w = 1.0f;
    NewOutPut.Pos = mul(NewOutPut.Pos, WorldViewProjection);
    // NewOutPut.Pos.w = 1.0f;
    NewOutPut.Color = _Input.Color;
    
    return NewOutPut;
}

cbuffer ResultColor : register(b2)
{
    float4 PlusColor;
    float4 MultyplyColor;
}

float4 Color_PS(Output _Input) : SV_Target0
{
    return _Input.Color * MultyplyColor + PlusColor;
}
