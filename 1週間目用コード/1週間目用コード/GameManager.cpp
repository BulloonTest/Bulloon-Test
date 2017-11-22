#include"Main.h"
#include"Settexture.h"
#include"Dinput.h"
#include"BackGround.h"
#include"Balloon.h"
#include"hornet.h"
#include"Cloud.h"
#include"Goal.h"

/*Å‰‚ÌŽO•bŠÔŽ~‚ß‚é‚½‚ß‚ÌƒJƒEƒ“ƒg*/
static int GameCount = 0;

void ManagerRun()
{
	/*‚±‚±‚Å1‘«‚µ‚Ä‚¢‚­*/
	GameCount++;

	/*3•bŠÔ‰ß‚¬‚é‚Æ“®‚«Žn‚ß‚é*/
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