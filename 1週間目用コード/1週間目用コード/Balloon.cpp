/*�@���D�̕\���F�s���@*/

#include<Windows.h>
#include<d3d9.h>
#include<dinput.h>
#include"Dinput.h"
#include"Main.h"
#include"Rotation.h"

#define WIDTH	1280
#define	HEIGHT	720

static float Gravity = 1.2;

/*�p�����[�^�[*/
// �L�������P�[�X�Ȃ� g_Balloon
CHARCTER_STATE g_balloon = { 100.f,400.f,64.f, 0.f,true };

void BalloonControl()
{
	static float da = 0.6f;

	KEYSTATE key[256];
	KeyCheckDinput(&key[DIK_SPACE], DIK_SPACE);

	static int cnt;

	/*�d�͂𑫂��Ă����ĉ��ɗ����Ă����悤��*/
	g_balloon.y += Gravity;

	// �����Ă鎞�Ɖ����ĂȂ����͓����ŏ����𖞂����Ȃ��̂�
	// if else�ɕύX����
	/*SPEACE�{�^���������Ă���Ԃ͕���*/
	if (key[DIK_SPACE] == ON)
	{
		g_balloon.y -= 6;
		g_balloon.ang = 0.f;
	}

	/*�����ƍŌ�ɏ�����ɏ㏸����悤��*/
	if (key[DIK_SPACE] == RELEASE)
	{
		cnt = 10;
	}
	
	if (--cnt > 0)
	{
		g_balloon.y -= 3;
	}

	g_balloon.ang += da;

	if (fabs(g_balloon.ang) > 15.f) 
	{
		da *= -1;
	}

}