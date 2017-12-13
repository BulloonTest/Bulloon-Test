#ifndef HP_H
#define	HP_H

#define UI_HP_W (72)
#define UI_HP_H (72)

#define MAX_HP (3)

#include"Main.h"

extern int balloon_hp;

void UI_Draw();
void SetVertexPos(CUSTOMVERTEX* result, float x, float y, float w, float h, float size=1.0f);
void RenderObject(CUSTOMVERTEX* cv, int TexNo);


#endif