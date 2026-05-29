#include "Physics.h"

bool Physics::ResolveBoxCollision(MYRECT& moving, const MYRECT& wall)
{
    //当たっていなければ終了
    if (!IsHitBox(moving, wall))
    {
        return false;
    }

    //moving右 - wall左
    int overlapLeft = (moving.x + moving.w) - wall.x;
    //wall右 - moving左
    int overlapRight = (wall.x + wall.w) - moving.x;
    //moving下 - wall上
    int overlapTop = (moving.y + moving.h) - wall.y;
    //wall下 - moving上
    int overlapBottom = (wall.y + wall.h) - moving.y;

    //最小重なり量
    int minOverlapX = (overlapLeft < overlapRight) ? overlapLeft : overlapRight;
    int minOverlapY = (overlapTop < overlapBottom) ? overlapTop : overlapBottom;

    //小さい方向へ押し戻す
    //横方向の方が浅い
    if (minOverlapX < minOverlapY)
    {
        //左側から衝突
        if (overlapLeft < overlapRight)
        {
            moving.x -= overlapLeft;
        }
        //右側から衝突
        else
        {
            moving.x += overlapRight;
        }
    }
    //縦方向の方が浅い
    else
    {
        //上から衝突
        if (overlapTop < overlapBottom)
        {
            moving.y -= overlapTop;
        }
        //下から衝突
        else
        {
            moving.x += overlapBottom;
        }
    }

    return true;
}
