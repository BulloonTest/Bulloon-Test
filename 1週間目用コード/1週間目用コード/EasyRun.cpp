/*　EasyMoodのゲーム処理をここで書いている　*/

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

/*最初の三秒間止めるためのカウント*/
int GameCount = 0;

void EasyRun()
{
	/*ここで1足していく*/
	GameCount++;

	/*　　初期化　*/
	if (GameCount < 60)
	{
		EasyCloudInit();
		EasyBirdInit();
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

	/*　体力が無くなったらGameOver画面に移行する　*/
	if (balloon_hp == 0)
	{
		Scenemanagement = OVER_SCENE;
	}

	/*カウントダウンは最初の３秒間経つとスコアになる*/
	if (GameCount < STARTCOUNT)
	{
		CountDraw();
	}
	else
	{
		ScoreRender(GameCount, BonusScore);
	}
}