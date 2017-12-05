/*�@�w�i�̕\���F�s���@*/

#include<Windows.h>
#include<d3dx9.h>
#include"BackGround.h"
#include"main.h"

#define WIDTH	1280
#define	HEIGHT	720

#define GAMESPEED 1.5

// �L�������P�[�X�Ȃ�g_Map ntk
CHARCTER_STATE g_map = { 0.f, 0.f,0.f,0.f };
CHARCTER_STATE g_map2 = { WIDTH, HEIGHT,0.f,0.f };


void BackDraw()
{
	// BackGround��BackGround2�͈ꕔ�̒l���Ⴄ�����ŏ����͓����Ȃ̂�
	// �֐������ɒ��킵�Ăق���
	/*�w�i*/
	CUSTOMVERTEX BackGround[]
	{
		{ g_map.x, g_map.y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_map.x + WIDTH, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_map.x + WIDTH, g_map.y + HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_map.x, g_map.y + HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[BACKGROUND_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, BackGround, sizeof(CUSTOMVERTEX));

	CUSTOMVERTEX BackGround2[]
	{
		{ g_map2.x, g_map.y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_map2.x + WIDTH, g_map.y, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_map2.x + WIDTH, g_map2.y, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_map2.x, g_map2.y , 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[BACKGROUND_TEX2]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, BackGround2, sizeof(CUSTOMVERTEX));
}

void BackControl()
{
	/*�}�b�v�̎�����*/
	g_map.x -= GAMESPEED;
	g_map2.x -= GAMESPEED;

	/*�����Ń��[�v�����Ă���*/
	if (g_map.x < -WIDTH)
	{
		g_map.x = 0;
	}

	if (g_map2.x < -0)
	{
		g_map2.x = WIDTH;
	}
}