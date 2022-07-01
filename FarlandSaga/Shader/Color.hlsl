// #include "myshader.hlsli"

// SV_POSITION 시맨틱
// 그래픽카드에게 이녀석은 이런 부류니까 니가 자동으로 처리하는 녀석이 있으면 하고.

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
    // 쉐이더의 경우에는 대부분의 상황에서 형변환이 가능하다.
    // 0
    Output NewOutPut = (Output)0;
    NewOutPut.Pos = _Input.Pos;
    NewOutPut.Color = _Input.Color;

    return NewOutPut;
}



//float4 main( float4 pos : POSITION ) : SV_POSITION
//{
//	return pos;
//}

//struct PSOutput
//{
//    float4 Pos : SV_Target0;
//};

float4 Color_PS(Output _Input) : SV_Target0
{
    return _Input.Color;
}
