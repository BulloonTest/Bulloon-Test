#include"Main.h"
#include"Settexture.h"
#include"Dinput.h"
#include"BackGround.h"
#include"Balloon.h"
#include"hornet.h"
#include"Cloud.h"
#include"Goal.h"

/*最初の三秒間止めるためのカウント*/
static int GameCount = 0;

void ManagerRun()
{
	/*ここで1足していく*/
	GameCount++;

	/*3秒間過ぎると動き始める*/
	if (GameCount > 180)
	{
		BalloonControl();
		HornetControl();
		BackControl();
		CloudControl();
		Goalcountrol();
	}

	BackDraw();
	HornetDraw();
	CloudDraw();
	GoalDraw();
	BalloonDraw();
	RainCloudDraw();
}