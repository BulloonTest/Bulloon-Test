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

/*マジックナンバーをなくすように*/
void EasyDraw()
{
	TimeCount++;

	BackDraw();
	DrawVertex(g_Goal, GOAL_TEX);

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

	Draws(34, g_EasyBonus_Small, BONUS_SMAIL_TEX);
	Draws(15, g_EasyBonus_M, BONUS_M_TEX);
	Draws(6, g_EasyBonus_Big, BONUS_BIG_TEX);
	Draws(4, g_EasyRecovery, RECOVERY_TEX);
	Draws(16, g_EasyHornet, HORNET_TEX);
	//Draws(16, g_EasyBird, BIRD_TEX);
	DrawsSwitch(16, g_EasyBird, BIRD_TEX, BIRD1_TEX);

	DrawVertex(g_balloon, BALLOON_TEX);

	UI_Draw();
}

//関数化する前の物

//for (int i = 0; i < 34; i++)
//{
//	if (g_EasyBonus_Small[i].activflg == true)
//	{
//		DrawVertex(g_EasyBonus_Small[i], BONUS_SMAIL_TEX);
//	}
//}

/*for (int i = 0; i < 15; i++)
{
if (g_EasyBonus_M[i].activflg == true)
{
DrawVertex(g_EasyBonus_M[i], BONUS_M_TEX);
}
}*/

//for (int i = 0; i < 6; i++)
//{
//	if (g_EasyBonus_Big[i].activflg == true)
//	{
//		DrawVertex(g_EasyBonus_Big[i], BONUS_BIG_TEX);
//	}
//}

/*for (int i = 0; i < 4; i++)
{
if (g_EasyRecovery[i].activflg == true)
{
DrawVertex(g_EasyRecovery[i], RECOVERY_TEX);
}
}*/

/*for (int i = 0; i < 16; i++)
{
DrawVertex(g_EasyHornet[i], HORNET_TEX);
}*/

//for (int i = 0; i < 16; i++)
//{
//	DrawVertex(g_EasyBird[i], BIRD_TEX);
//}