#include"Main.h"
#include"Settexture.h"
#include"Dinput.h"
#include"BackGround.h"
#include"Balloon.h"
#include"hornet.h"
#include"Cloud.h"
#include"Goal.h"

/*�ŏ��̎O�b�Ԏ~�߂邽�߂̃J�E���g*/
static int GameCount = 0;

void ManagerRun()
{
	/*������1�����Ă���*/
	GameCount++;

	/*3�b�ԉ߂���Ɠ����n�߂�*/
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