/*�@�I(��Q��)�̕\���F�s���@*/

#include<Windows.h>
#include<d3d9.h>
#include"hornet.h"
#include"Main.h"
#include"Rotation.h"

#define GAMESPEED 1.5

CHARCTER_STATE g_hornet = { 700.f,300.f,64.f, 0.f,true };

static int count = 0;
static bool activ = false;

void HornetDraw()
{
	CUSTOMVERTEX Hornet[]
	{
		{ g_hornet.x - g_hornet.scale, g_hornet.y - g_hornet.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_hornet.x + g_hornet.scale, g_hornet.y - g_hornet.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_hornet.x + g_hornet.scale, g_hornet.y + g_hornet.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_hornet.x - g_hornet.scale, g_hornet.y + g_hornet.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	/*������*/
	/*�����ŉ�]�֐����g���ĉ����g��h�炵�Ă���*/
	if (count > 60)
	{
		Rotation(Hornet, 5.f);
	}
	else
	{
		Rotation(Hornet, -0.2f);
	}

	g_pD3Device->SetTexture(0, g_pTexture[HORNET_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Hornet, sizeof(CUSTOMVERTEX));
}

void HornetControl()
{
	count++;

	g_hornet.x -= GAMESPEED;

	if (count > 60)
	{
		g_hornet.y -= 3.5;
	}
	else
	{
		g_hornet.y += 3.5;
	}

	if (count > 130)
	{
		count = 0;
	}

}
