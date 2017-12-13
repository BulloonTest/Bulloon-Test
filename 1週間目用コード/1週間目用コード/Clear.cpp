#include<Windows.h>
#include<d3dx9.h>
#include"BackGround.h"
#include"main.h"

#define WIDTH	1280
#define	HEIGHT	720

CHARCTER_STATE g_Clear = { 0.f, 0.f,0.f,0.f ,true };

void ClearDraw()
{
	CUSTOMVERTEX ClearScene[]
	{
		{ g_Clear.x, g_Clear.y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Clear.x + WIDTH, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Clear.x + WIDTH, g_Clear.y + HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Clear.x, g_Clear.y + HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[CLEAR_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ClearScene, sizeof(CUSTOMVERTEX));
}