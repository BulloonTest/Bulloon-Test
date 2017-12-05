/* ` â_(è·äQï®) ` */

#include<Windows.h>
#include<d3dx9.h>
#include"Main.h"
#include"Cloud.h"

#define GAMESPEED 1.5

CHARCTER_STATE g_Cloud = { 1400.f,150.f,128.f, 0.f };
CHARCTER_STATE g_Thunder = { g_Cloud.x,g_Cloud.y + 105.f,64.f, 0.f };

static int TimeCount = 0;
static int LoadCount = 0;

void CloudDraw()
{
	CUSTOMVERTEX cloud[]
	{
		{ g_Cloud.x - g_Cloud.scale, g_Cloud.y - g_Cloud.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Cloud.x + g_Cloud.scale, g_Cloud.y - g_Cloud.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Cloud.x + g_Cloud.scale, g_Cloud.y + g_Cloud.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Cloud.x - g_Cloud.scale, g_Cloud.y + g_Cloud.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	g_pD3Device->SetTexture(0, g_pTexture[CLOUD_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cloud, sizeof(CUSTOMVERTEX));
}

void ThunderDraw()
{
	TimeCount++;

	if (TimeCount > 180)
	{
		LoadCount++;

		CUSTOMVERTEX Thunder[]
		{
			{ g_Thunder.x - g_Thunder.scale, g_Thunder.y - g_Thunder.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ g_Thunder.x + g_Thunder.scale, g_Thunder.y - g_Thunder.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ g_Thunder.x + g_Thunder.scale, g_Thunder.y + g_Thunder.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ g_Thunder.x - g_Thunder.scale, g_Thunder.y + g_Thunder.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
		};
		g_pD3Device->SetTexture(0, g_pTexture[THUNDER_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Thunder, sizeof(CUSTOMVERTEX));

		if (LoadCount > 60)
		{
			TimeCount = 0;
			LoadCount = 0;
		}
	}
}

void CloudControl()
{
	g_Cloud .x -= GAMESPEED;
	g_Thunder.x -= GAMESPEED;
}