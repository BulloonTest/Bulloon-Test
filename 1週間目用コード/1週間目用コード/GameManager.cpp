/*　ゲームの処理をここで走らせている　*/

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

/*最初の三秒間止めるためのカウント*/
static int GameCount = 0;

/*　ここでゲームを動かしている　*/
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
		/*ここで1足していく*/
		GameCount++;

		/*　　初期化　*/
		if (GameCount < 60)
		{
			CloudInit();
			BirdInit();
			EasyHornetInit();
			EasyCoordinateInit();
			EasyRecoveryInit();
		}

		/*3秒間過ぎると動き始める*/
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

		/*カウントダウンは最初の３秒間経つと消えるように*/
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
