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

/*�@�v���C���[�̃��C�t�ύX�ׂ̈̃J�E���g�@*/

/*�ŏ��̎O�b�Ԏ~�߂邽�߂̃J�E���g*/
static int GameCount = 0;

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