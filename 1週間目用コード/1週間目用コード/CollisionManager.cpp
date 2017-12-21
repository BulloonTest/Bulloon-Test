/*�@�Q�[���̓����蔻���S�Ă����ōs���Ă���@*/

#include"Main.h"
#include"BackGround.h"
#include"Balloon.h"
#include"hornet.h"
#include"Cloud.h"
#include"Goal.h"
#include"Countdown.h"
#include"CollisionJudgment.h"
#include"Bird.h"
#include"Bonus.h"
#include"Scene.h"
#include"Score.h"
#include"HP.h"
#include"Recovery.h"

/*�@�}�b�v�̏c�̑傫���@*/
#define	HEIGHT	720

int balloon_hp = MAX_HP;


/*�@�����蔻��������őS�čs���Ă���@*/
void ManagerCollision()
{

	/*�v���C���[�ƃS�[��()*/
	if (CollisionBB(g_balloon, g_Goal))
	{
		Scenemanagement = CLEAR_SCENE;
	}

	//EasyMood�̎��̔���	

	/*�v���C���[�ƖI*/
	for (int i = 0; i < 16; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyHornet[i])) && (g_EasyHornet[i].activflg == true))
		{
			g_EasyHornet[i].activflg = false;
			balloon_hp--;
		}
	}

	/*�v���C���[�Ɖ񕜃A�C�e��*/
	for (int i = 0; i < 4; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyRecovery[i])) && (g_EasyRecovery[i].activflg == true))
		{
			g_EasyRecovery[i].activflg = false;
			balloon_hp++;
		}
	}

	/*�v���C���[�Ɖ_*/
	for (int i = 0; i < 9; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyCloud[i])) && (g_EasyCloud[i].activflg == true))
		{
			g_EasyCloud[i].activflg = false;
			balloon_hp--;
		}
		/*�v���C���[�Ɨ�*/
		if ((CollisionBB(g_balloon, g_EasyThunder[i])) && (g_EasyThunder[i].activflg == true))
		{
			g_EasyThunder[i].activflg = false;
			balloon_hp--;
		}
	}

	/*�v���C���[�ƒ��̓����蔻��*/
	for (int i = 0; i < 16; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyBird[i])) && (g_EasyBird[i].activflg == true))
		{
			g_EasyBird[i].activflg = false;
			balloon_hp--;
		}
	}

	/*�v���C���[�ƃ{�[�i�X�A�C�e�����̓����蔻��*/
	for (int i = 0; i < 34; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyBonus_Small[i])) && (g_EasyBonus_Small[i].activflg == true))
		{
 			g_EasyBonus_Small[i].activflg = false;
			BonusScore += 50;
		}
	}

	/*�v���C���[�ƃ{�[�i�X�A�C�e�����̔���*/
	for (int i = 0; i < 15; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyBonus_M[i])) && (g_EasyBonus_M[i].activflg == true))
		{
			g_EasyBonus_M[i].activflg = false;
			BonusScore += 100;
		}
	}

	/*�v���C���[�ƃ{�[�i�X�A�C�e����*/
	for (int i = 0; i < 6; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyBonus_Big[i])) && (g_EasyBonus_Big[i].activflg == true))
		{
			g_EasyBonus_Big[i].activflg = false;
			BonusScore += 200;
		}
	}

	//�����ł�
	/*�v���C���[����ʉ��ɉ�����߂����*/
	if (g_balloon.y >= HEIGHT - g_balloon.scale - g_balloon.scale / 2)
	{
   		g_balloon.y += 2;
		g_balloon.y = 300.f;
		balloon_hp--;
	}

	/*�v���C���[����ɏオ��߂����*/
	if (g_balloon.y <= 0 + g_balloon.scale)
	{
		g_balloon.y += 2;
		g_balloon.y = 300.f;
		balloon_hp--;
	}
}