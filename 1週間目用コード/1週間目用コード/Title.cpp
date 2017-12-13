#include<Windows.h>
#include<d3dx9.h>
#include"BackGround.h"
#include"main.h"

#define WIDTH	1280
#define	HEIGHT	720

CHARCTER_STATE g_Title = { 0.f, 0.f,0.f,0.f ,true };

void TitleDraw()
{
	CUSTOMVERTEX TitleScene[]
	{
		{ g_Title.x, g_Title.y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Title.x + WIDTH, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Title.x + WIDTH, g_Title.y + HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Title.x, g_Title.y + HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[TITLE_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TitleScene, sizeof(CUSTOMVERTEX));
}