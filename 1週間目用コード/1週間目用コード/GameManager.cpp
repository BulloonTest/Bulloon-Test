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

/*　プレイヤーのライフ変更の為のカウント　*/

/*最初の三秒間止めるためのカウント*/
static int GameCount = 0;

/*　ここでゲームを動かしている　*/
void ManagerRun()
{
	/*ここで1足していく*/
	GameCount++;

	/*3秒間過ぎると動き始める*/
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

	/*カウントダウンは最初の３秒間経つと消えるように*/
	if (GameCount < 210)
	{
		CountDraw();
	}

}