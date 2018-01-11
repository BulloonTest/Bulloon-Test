/*�@EasyMood�̃Q�[�������������ŏ����Ă���@*/

#include"Main.h"
#include"Render.h"
#include"BackGround.h"
#include"Balloon.h"
#include"hornet.h"
#include"Cloud.h"
#include"Goal.h"
#include"Countdown.h"
#include"CollisionJudgment.h"
#include"Bird.h"
#include"CollisionManager.h"
#include"DraManager.h"
#include"Bonus.h"
#include"HP.h"
#include"Score.h"
#include"GameManager.h"
#include"Scene.h"
#include"Recovery.h"
#include"EasyRun.h"

/*�ŏ��̎O�b�Ԏ~�߂邽�߂̃J�E���g*/
int GameCount = 0;

void EasyRun()
{
	/*������1�����Ă���*/
	GameCount++;

	/*�@�@�������@*/
	if (GameCount < 60)
	{
		EasyCloudInit();
		EasyBirdInit();
		EasyHornetInit();
		EasyCoordinateInit();
		EasyRecoveryInit();
	}

	/*3�b�ԉ߂���Ɠ����n�߂�*/
	if (GameCount > STARTCOUNT)
	{
		BalloonControl();
		BirdControl();
		HornetControl();
		BackControl();
		CloudControl();
		Goalcountrol();
		RecoveryControl();
		EasyBonusCountrol();
		CountControl();
		ManagerCollision();
	}

	DrawManager();

	/*�@�̗͂������Ȃ�����GameOver��ʂɈڍs����@*/
	if (balloon_hp == 0)
	{
		Scenemanagement = OVER_SCENE;
	}

	/*�J�E���g�_�E���͍ŏ��̂R�b�Ԍo�ƃX�R�A�ɂȂ�*/
	if (GameCount < STARTCOUNT)
	{
		CountDraw();
	}
	else
	{
		ScoreRender(GameCount, BonusScore);
	}
}