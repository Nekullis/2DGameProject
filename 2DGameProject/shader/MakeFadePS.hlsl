//----------------------------------------------------------------------
// @filename MakeFadePS.hlsl
// @author: Fukuma Kyohei
// @explanation
// ソナーフェードに関するhlslファイル
//----------------------------------------------------------------------

Texture2D Tex0 : register(t0);
SamplerState Samp : register(s0);

struct PS_INPUT
{
    float4 Pos : SV_Position;
    float4 Dif : COLOR0;
    float2 Tex : TEXCOORD0;
};

float4 main(PS_INPUT input):SV_Target
{
    float4 col = Tex0.Sample(Samp, input.Tex);
    
    //少しずつ暗くする
    col *= 0.95f;
    
    //充分に暗くなったら完全に0にする
    if (max(col.r, max(col.g, col.b))<0.1f)
    {
        return float4(0, 0, 0, 0);

    }
    
    return col;
}
