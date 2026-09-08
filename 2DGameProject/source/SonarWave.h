//----------------------------------------------------------------------
// @filename SonarWave.h
// @author: Fukuma Kyohei
// @explanation
// ソナーのデータ構造体クラス
//----------------------------------------------------------------------
#pragma once
#include "Vector2D.h"
#include <unordered_set>

class GameObject;

struct DistortionEvent
{
    //歪ませる方向(ラジアン)
    float angle;

    //歪みの強さ
    float power;

    //歪みを維持する時間
    float time;
};

class SonarWave
{
public:
    SonarWave();

    void Start(const Vector2D& pos, float landingSpeed);
    void Update();
    void Draw()const;

    bool IsActive()const { return m_active; }
    //既に通知済み
    bool HasHitObject(GameObject* object) const;
    //通知済みに登録
    void AddHitObject(GameObject* object);
    //歪みを追加
    void AddDistortion(float angle, float power, float time);
    //指定角度の歪み量を計算
    float CalcDistortion(float angle) const;

    //ゲッター
    Vector2D GetPosition()const { return m_position; }
    float GetRadius()const { return m_radius; }

private:
    //位置
    Vector2D m_position;
    //半径
    float m_radius;
    //最大範囲
    float m_maxRadius;
    //到達速度
    float m_speed;
    //α値
    float m_alpha;
    //ソナー発動中
    bool m_active;
    //現在発生している歪み演出
    std::vector<DistortionEvent> m_distortions;
    //このソナーが既に反応させたオブジェクト
    std::unordered_set<GameObject*> m_hitobjects;

};

