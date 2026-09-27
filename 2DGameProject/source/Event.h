//----------------------------------------------------------------------
// @filename Event.h
// @author: Fukuma Kyohei
// @explanation
// ゲーム内イベント処理の基底クラス
//----------------------------------------------------------------------
#pragma once
#include <string>
#include "Collider.h"

class Event
{
public:
    Event(const std::string& type, float x, float y);
    virtual ~Event();

    //イベント実行
    virtual void Execute();

    //イベント情報獲得
    const std::string& GetType() const { return m_type; }
    const float GetX() const { return m_x; }
    const float GetY() const { return m_y; }
    //collider取得
    const Collider GetCollider() const { return m_collider; }
    //トリガー
    bool IsTriggerd() { return m_isTriggerd; }

    //セッター
    void SetTriggerd(bool trigger) { m_isTriggerd = trigger; }

private:
    //イベント種類
    std::string m_type;

    //イベント座標
    float m_x;
    float m_y;

    //イベントの当たり判定
    Collider m_collider;

    //一度発生したら二度は条件を除き発生しないトリガー
    bool m_isTriggerd;
};

