/*�@�Q�[���̓����蔻���S�Ă����ōs���Ă���@*/

#include"Main.h"
#include"BackGround.h"
#include"Balloon.h"
#include"hornet.h"
#include"Cloud.h"
#include"Goal.h"
#include"Countdown.h"
#include"CollisionJudgment.h"
#include"Bird.h"

/*�@�}�b�v�̏c�̑傫���@*/
#define	HEIGHT	720

/*�@�����蔻��������őS�čs���Ă���@*/
void ManagerCollision()
{
	/*�v���C���[�ƖI*/
	if (CollisionBB(g_balloon, g_hornet))
	{
		g_balloon.y += 2;
	}

	/*�v���C���[�Ɖ_*/
	if (CollisionBB(g_balloon, g_Cloud))
	{
		g_balloon.y += 2;
	}

	/*�v���C���[�Ɨ�*/
	if (CollisionBB(g_balloon, g_Thunder))
	{
		g_balloon.y += 2;
	}

	/*�v���C���[�ƃS�[��()*/
	if (CollisionBB(g_balloon, g_Goal))
	{
		g_balloon.y += 2;
	}

	/*�v���C���[�ƒ��̓����蔻��*/
	if (CollisionBB(g_balloon, g_Bird))
	{
		g_balloon.y += 2;
	}

	/*�v���C���[����ʉ��ɉ�����߂����*/
	if (g_balloon.y >= HEIGHT - g_balloon.scale - g_balloon.scale / 2)
	{
   		g_balloon.y += 2;
	}

	/*�v���C���[����ɏオ��߂����*/
	if (g_balloon.y <= 0 + g_balloon.scale)
	{
		g_balloon.y += 2;
	}
}