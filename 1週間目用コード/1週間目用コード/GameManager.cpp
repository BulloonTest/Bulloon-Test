/*�@�Q�[���̏����������ő��点�Ă���@*/

#include"Main.h"
#include"Render.h"
#include"Dinput.h"
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

/*�@�v���C���[�̃��C�t�ύX�ׂ̈̃J�E���g�@*/

/*�ŏ��̎O�b�Ԏ~�߂邽�߂̃J�E���g*/
static int GameCount = 0;

static int TimeCount = 0;
static int LoadCount = 0;

/*�@�����őS�Ẳ摜�𐶐��ƕ`������Ă���@���ӁF�u�����Ԃɒ��ӂ����鎖�@*/
void DrawManager()
{
	TimeCount++;

	BackDraw();
	Make(g_hornet, HORNET_TEX);
	Make(g_Bird, BIRD_TEX);
	Make(g_Goal, GOAL_TEX);
	Make(g_balloon, BALLOON_TEX);
	Make(g_cloud, CLOUD_TEX);

	if (TimeCount > 180)
	{
		LoadCount++;

		Make(g_Thunder, THUNDER_TEX);

		if (LoadCount > 60)
	{
			TimeCount = 0;
			LoadCount = 0;
		}
	}
}

/*�@�����蔻��������őS�čs���Ă���@*/
void ManagerCollision()
{
	/*�v���C���[�ƖI*/
	if (collisionBB(g_balloon, g_hornet))
	{
     		g_balloon.y += 2;
	}

	/*�v���C���[�Ɖ_*/
	if (collisionBB(g_balloon, g_cloud))
	{
		g_balloon.y += 2;
	}

	/*�v���C���[�Ɨ�*/
	if (collisionBB(g_balloon, g_Thunder))
	{
		g_balloon.y += 2;
	}

	/*�v���C���[�ƃS�[��()*/
	if (collisionBB(g_balloon, g_Goal))
	{
		g_balloon.y += 2;
	}

	/*�v���C���[�ƒ��̓����蔻��*/
	if (collisionBB(g_balloon, g_Bird))
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


/*�@�����ŃQ�[���𓮂����Ă���@*/
void ManagerRun()
{
	/*������1�����Ă���*/
	GameCount++;

	/*3�b�ԉ߂���Ɠ����n�߂�*/
	if (GameCount > 200)
	{
		BalloonControl();
		HornetControl();
		BirdControl();
		BackControl();
		CloudControl();
		Goalcountrol();
		CountControl();
		ManagerCollision();
	}

	DrawManager();

	/*�J�E���g�_�E���͍ŏ��̂R�b�Ԍo�Ə�����悤��*/
	if (GameCount < 210)
	{
		CountDraw();
	}

}