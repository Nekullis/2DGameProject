#include "ShaderUtility.h"

void ShaderUtility::CreateFullScreenQuad(VERTEX2DSHADER* vertex, float width, float height)
{
    //ç∂è„
    vertex[0].pos = VGet(0.0f, 0.0f, 0.0f);
    vertex[0].u = 0.0f;
    vertex[0].v = 0.0f;
    //âEè„
    vertex[1].pos = VGet(width, 0.0f, 0.0f);
    vertex[1].u = 1.0f;
    vertex[1].v = 0.0f;
    //ç∂â∫
    vertex[2].pos = VGet(0.0f, height, 0.0f);
    vertex[2].u = 0.0f;
    vertex[2].v = 1.0f;
    //ç∂â∫
    vertex[3].pos = VGet(0.0f, height, 0.0f);
    vertex[3].u = 0.0f;
    vertex[3].v = 1.0f;
    //âEè„
    vertex[4].pos = VGet(width, 0.0f, 0.0f);
    vertex[4].u = 1.0f;
    vertex[4].v = 0.0f;
    //âEâ∫
    vertex[5].pos = VGet(width, height, 0.0f);
    vertex[5].u = 1.0f;
    vertex[5].v = 1.0f;

    for (int i = 0; i < 6; i++)
    {
        vertex[i].rhw = 1.0f;
        vertex[i].dif = { 255,255,255,255 };
        vertex[i].spc = { 0,0,0,0 };
        vertex[i].su = 0.0f;
        vertex[i].sv = 0.0f;
    }
}
