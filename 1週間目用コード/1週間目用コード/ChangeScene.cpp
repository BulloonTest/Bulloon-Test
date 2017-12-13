#include<Windows.h>
#include<d3dx9.h>
#include"BackGround.h"
#include"main.h"

#define WIDTH	1280
#define	HEIGHT	720

CHARCTER_STATE g_Change = { 0.f, 0.f,0.f,0.f ,true };

void ChangeDraw()
{
	CUSTOMVERTEX ChangeScene[]
	{
		{ g_Change.x, g_Change.y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Change.x + WIDTH, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Change.x + WIDTH, g_Change.y + HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Change.x, g_Change.y + HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[CHANGE_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ChangeScene, sizeof(CUSTOMVERTEX));
}