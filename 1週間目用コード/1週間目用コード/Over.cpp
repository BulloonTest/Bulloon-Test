#include<Windows.h>
#include<d3dx9.h>
#include"BackGround.h"
#include"main.h"

#define WIDTH	1280
#define	HEIGHT	720

CHARCTER_STATE g_Over = { 0.f, 0.f,0.f,0.f ,true };

void OverDraw()
{
	CUSTOMVERTEX OverScene[]
	{
		{ g_Over.x, g_Over.y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Over.x + WIDTH, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Over.x + WIDTH, g_Over.y + HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Over.x, g_Over.y + HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[GAMEOVER_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, OverScene, sizeof(CUSTOMVERTEX));
}