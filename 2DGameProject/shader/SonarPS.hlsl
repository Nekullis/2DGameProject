//----------------------------------------------------------------------
// @filename SonarPS.hlsl
// @author: Fukuma Kyohei
// @explanation
// ソナー時の描画に関するhlslファイル
//----------------------------------------------------------------------

//敵画像
Texture2D EnemyTexture : register(t0);
//マスク画像
Texture2D MaskTexture : register(t1);
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
    //色を取得
    float4 enemy = EnemyTexture.Sample(Samp, input.Tex);
    float4 mask = MaskTexture.Sample(Samp, input.Tex);
    
    //黒ならピクセルを描かないように
    if (mask.r < 0.1f)
    {
        discard;
    }
    
    return enemy;
}