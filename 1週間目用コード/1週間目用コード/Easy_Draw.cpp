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
#include"Bonus.h"
#include"HP.h"
#include"Recovery.h"
#include"Score.h"

/*　雷を出すカウント　*/
static int TimeCount = 0;
static int LoadCount = 0;

void EasyDraw()
{
	TimeCount++;

	BackDraw();
	DrawVertex(g_balloon, BALLOON_TEX);
	DrawVertex(g_Goal, GOAL_TEX);
	UI_Draw();

	/*マジックナンバーをなくすように*/
	for (int i = 0; i < 16; i++)
	{
		DrawVertex(g_EasyBird[i], BIRD_TEX);
	}

	for (int i = 0; i < 9; i++)
	{
		DrawVertex(g_EasyCloud[i], CLOUD_TEX);
		if (TimeCount > 180)
		{
			LoadCount++;

			DrawVertex(g_EasyThunder[i], THUNDER_TEX);

			if (LoadCount > 60)
			{
				TimeCount = 0;
				LoadCount = 0;
			}
		}
	}

	for (int i = 0; i < 34; i++)
	{
		if (g_EasyBonus_Small[i].activflg == true)
		{
			DrawVertex(g_EasyBonus_Small[i], BONUS_SMAIL_TEX);
		}
	}

	for (int i = 0; i < 15; i++)
	{
		if (g_EasyBonus_M[i].activflg == true)
		{
			DrawVertex(g_EasyBonus_M[i], BONUS_M_TEX);
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (g_EasyBonus_Big[i].activflg == true)
		{
			DrawVertex(g_EasyBonus_Big[i], BONUS_BIG_TEX);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (g_EasyRecovery[i].activflg == true)
		{
			DrawVertex(g_EasyRecovery[i], RECOVERY_TEX);
		}
	}

	for (int i = 0; i < 16; i++)
	{
		DrawVertex(g_EasyHornet[i], HORNET_TEX);
	}
}