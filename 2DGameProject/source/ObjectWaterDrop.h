#pragma once
#include "GameObject.h"
class ObjectWaterDrop : public GameObject
{
public:
    ObjectWaterDrop(float x, float y);
    virtual ~ObjectWaterDrop();

    void Update() override;
    void Draw() override;
};

