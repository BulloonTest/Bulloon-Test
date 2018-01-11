/*　HP(体力)の表示：行動　*/

/*　HP(体力)の表示：行動　*/
#include "HP.h"
#include"hornet.h"
#include"Cloud.h"
#include"CollisionJudgment.h"
#include"Bird.h"

/*　HP(体力)の表示：行動　*/

CUSTOMVERTEX hp[4];


void MakeVertex(CUSTOMVERTEX* cv, float w, float h)
{
	cv[0].x = cv[3].x = 0;
	cv[1].x = cv[2].x = w;
	cv[0].y = cv[1].y = 0;
	cv[2].y = cv[3].y = h;

	for (int i = 0; i < 4; i++)
	{
		cv[i].z = 1.0f;
		cv[i].rhw = 1.0f;
		cv[i].color = 0xFFFFFFFF;
	}
	cv[0].tu = cv[3].tu = 0;		// 統合ファイルでは使えない
	cv[0].tv = cv[1].tv = 0;
	cv[1].tu = cv[2].tu = 1.0f;
	cv[2].tv = cv[3].tv = 1.0f;
}

void SetVertexPos(CUSTOMVERTEX* result, float x, float y, float w, float h, float size)
{
	float dw, dh;

	dw = w * size;
	dh = h * size;

	result[0].x = x - dw / 2;
	result[1].x = x + dw / 2;
	result[2].x = x + dw / 2;
	result[3].x = x - dw / 2;
	result[0].y = y - dh / 2;
	result[1].y = y - dh / 2;
	result[2].y = y + dh / 2;
	result[3].y = y + dh / 2;
}

void RenderObject(CUSTOMVERTEX* cv, int TexNo)
{
	g_pD3Device->SetTexture(0, g_pTexture[TexNo]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cv, sizeof(CUSTOMVERTEX));
}

void UI_Draw()
{
	// 残気を3つ表示
	int i;

	for (i = 0; i < balloon_hp; i++)
	{
		MakeVertex(hp, UI_HP_W, UI_HP_H);
		SetVertexPos(hp, 20.0f + 40.0f * i, 20.0f, UI_HP_W, UI_HP_H);
		RenderObject(hp, HP1_TEX);
	}
	for (; i < MAX_HP; i++)
	{
		MakeVertex(hp, UI_HP_W, UI_HP_H);
		SetVertexPos(hp, 20.0f + 40.0f * i, 20.0f, UI_HP_W, UI_HP_H);
		RenderObject(hp, HP2_TEX);
	}
}
