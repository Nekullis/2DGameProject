//----------------------------------------------------------------------
// @filename SonarPS.hlsl
// @author: Fukuma Kyohei
// @explanation
// ソナー時の描画に関するhlslファイル
//----------------------------------------------------------------------

#define MAX_DISTORTION 8
//本体
Texture2D Tex0 : register(t0);
//マスク画像
Texture2D Tex1 : register(t1);
//テクスチャから色を取得するための変数
SamplerState Samp : register(s0);

struct DISTORTION_DATA
{
    float2 Position;
    float Timer;
    float Dummy;
};

cbuffer DistortionBuffer : register(b0)
{
    DISTORTION_DATA Distortion[MAX_DISTORTION];
    int DistortionCount;
    float3 Padding;
}

//uvのxy座標を入れるための構造体
struct PS_INPUT
{
    float4 Pos : SV_Position;
    float4 Dif : COLOR0;
    float2 Tex : TEXCOORD0;
};

float4 main(PS_INPUT input) : SV_Target
{
    //描画用uv
    float2 uv = input.Tex;
    
    //最大数まで歪みを加算
    for (int i = 0; i < DistortionCount; i++)
    {
        //敵との距離
        float2 diff = Distortion[i].Position;
        float dist = length(diff);
        
        //歪み半径
        const float Radius = 0.12f;
        
        //影響度
        float influence = saturate((Radius - dist) / Radius);
        
        //歪み方向
        float2 dir = normalize(diff + 0.0001f);
        
        //揺れ
        float wave = sin(dist * 120.0f - Distortion[i].Timer * 20.0f);
        
        //uvをゆがませる
        uv += dir * wave * influence * 0.15f;
    }
    //テクスチャ取得
    float4 scene = Tex0.Sample(Samp, uv);
    float mask = Tex1.Sample(Samp, input.Tex).r;

    return float4(scene.rgb * mask, scene.a);
}