// #include "myshader.hlsli"

// SV_POSITION �ø�ƽ
// �׷���ī�忡�� �̳༮�� �̷� �η��ϱ� �ϰ� �ڵ����� ó���ϴ� �༮�� ������ �ϰ�.

// t1

// Create("TransformData");
#include "TransformHeader.fx"

struct Input
{
    float4 Pos : POSITION;
    float4 Color : COLOR;
};

struct Output
{
    // �����Ͷ��������� ����Ʈ�� ���ؼ� �̳༮���� �ȼ��� ��������.
    float4 Pos : SV_POSITION;
    
    // �����Ͷ��������� ����Ʈ�� ���ؼ� �̳༮���� �ȼ��� ��������.
    float4 Pos2 : POSITION;
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
    
    NewOutPut.Pos2 = _Input.Pos;
    // NewOutPut.Pos.w = 1.0f;
    NewOutPut.Color = _Input.Color;
    
    return NewOutPut;
}

cbuffer ResultColor : register(b0)
{
    float4 PlusColor;
    float4 MultyplyColor;
}

//cbuffer ResultColor2 : register(b2)
//{
//    float4 PlusColor2;
//    float4 MultyplyColor2;
//}

float4 Color_PS(Output _Input) : SV_Target0
{
    // � ���͸� ������ ���̸� �������ݴϴ�.
    
    
    //float4 ScreenCenter = float4(640.0f, 360.0f, 0.0f, 1.0f);
    
    //float4 Dir = _Input.Pos - S    
    
    float Len = length(_Input.Pos2.xy);
    if (Len >= 0.5f)
    {
        return float4(1.0f, 0.0f, 1.0f, 1.0f); //clip(-1);
    }
    
    // float Len = length(_Input.Pos);
    
    // ������� ����.
    
    //      1
    //if (_Input.Pos.x >= 2.0f)
    //{
    //    clip(-1);
    //}
    
    //if (_Input.Pos2.x >= -0.2f)
    //{
    //    clip(-1);
    //}
    
    //for (int i = 0; i < 10; ++i)
    //{
        
    //}
    
    return _Input.Color /** MultyplyColor + PlusColor*/;
}
