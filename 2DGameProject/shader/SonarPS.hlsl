//----------------------------------------------------------------------
// @filename SonarPS.hlsl
// @author: Fukuma Kyohei
// @explanation
// ソナー時の描画に関するhlslファイル
//----------------------------------------------------------------------

//本体
Texture2D Tex0 : register(t0);
//マスク画像
Texture2D Tex1 : register(t1);
//テクスチャから色を取得するための変数
SamplerState Samp : register(s0);

//uvのxy座標を入れるための構造体
struct PS_INPUT
{
    float4 Pos : SV_Position;
    float4 Dif : COLOR0;
    float2 Tex : TEXCOORD0;
};

float4 main(PS_INPUT input) : SV_Target
{
    float4 scene = Tex0.Sample(Samp, input.Tex);
    float mask = Tex1.Sample(Samp, input.Tex).r;

    return float4(scene.rgb * mask, scene.a);
}