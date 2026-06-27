#pragma once
#include <DxLib.h>

namespace ShaderUtility
{
    //6頂点でのフルスクリーン矩形の生成
    //vertex = vertex[6]
    void CreateFullScreenQuad(VERTEX2DSHADER* vertex, float width, float height);
}
