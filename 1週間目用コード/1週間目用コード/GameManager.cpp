/*�@�Q�[���̏����������ő��点�Ă���@*/

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

/*�ŏ��̎O�b�Ԏ~�߂邽�߂̃J�E���g*/
static int GameCount = 0;

/*�@�����ŃQ�[���𓮂����Ă���@*/
void ManagerRun()
{
	switch (Scenemanagement)
	{
	case TITLE_SCENE:
		DrawManager();
		break;
	case CHANGE_SCENE:
		DrawManager();
		break;
	case EASY_SCENE:
		/*������1�����Ă���*/
		GameCount++;

		/*�@�@�������@*/
		if (GameCount < 60)
		{
			CloudInit();
			BirdInit();
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

		if (balloon_hp == 0)
		{
			Scenemanagement = OVER_SCENE;
		}

		/*�J�E���g�_�E���͍ŏ��̂R�b�Ԍo�Ə�����悤��*/
		if (GameCount < STARTCOUNT)
		{
			CountDraw();
		}
		else
		{
			ScoreRender(GameCount, BonusScore);
		}
		break;
	case NOMAL_SCENE:
		DrawManager();
		break;
	case HARD_SCENE:
		DrawManager();
		break;
	case CLEAR_SCENE:
		DrawManager();
		FinalScore(GameCount, BonusScore, balloon_hp);
		break;
	case OVER_SCENE:
		DrawManager();
		break;
	}

}
