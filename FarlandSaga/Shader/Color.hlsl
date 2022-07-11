// #include "myshader.hlsli"

// SV_POSITION 시맨틱
// 그래픽카드에게 이녀석은 이런 부류니까 니가 자동으로 처리하는 녀석이 있으면 하고.

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
    // 레스터라이저한테 뷰포트를 곱해서 이녀석으로 픽셀을 건져내줘.
    float4 Pos : SV_POSITION;
    
    // 레스터라이저한테 뷰포트를 곱해서 이녀석으로 픽셀을 건져내줘.
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
    // 쉐이더의 경우에는 대부분의 상황에서 형변환이 가능하다.
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
    // 어떤 벡터를 넣으면 길이를 리턴해줍니다.
    
    // float4 ScreenSize = { 1280, 720 };
    
    // float Len = length(_Input.Pos);
    
    // 출력하지 마라.
    
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
    
    return _Input.Color/* * MultyplyColor + PlusColor*/;
}
