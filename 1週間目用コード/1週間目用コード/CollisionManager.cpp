/*　ゲームの当たり判定を全てここで行っている　*/

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

/*　マップの縦の大きさ　*/
#define	HEIGHT	720

int balloon_hp = MAX_HP;


/*　当たり判定をここで全て行っている　*/
void ManagerCollision()
{

	/*プレイヤーとゴール()*/
	if (CollisionBB(g_balloon, g_Goal))
	{
		Scenemanagement = CLEAR_SCENE;
	}

	//EasyMoodの時の判定	

	/*プレイヤーと蜂*/
	for (int i = 0; i < 16; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyHornet[i])) && (g_EasyHornet[i].activflg == true))
		{
			g_EasyHornet[i].activflg = false;
			balloon_hp--;
		}
	}

	/*プレイヤーと回復アイテム*/
	for (int i = 0; i < 4; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyRecovery[i])) && (g_EasyRecovery[i].activflg == true))
		{
			g_EasyRecovery[i].activflg = false;
			balloon_hp++;
		}
	}

	/*プレイヤーと雲*/
	for (int i = 0; i < 9; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyCloud[i])) && (g_EasyCloud[i].activflg == true))
		{
			g_EasyCloud[i].activflg = false;
			balloon_hp--;
		}
		/*プレイヤーと雷*/
		if ((CollisionBB(g_balloon, g_EasyThunder[i])) && (g_EasyThunder[i].activflg == true))
		{
			g_EasyThunder[i].activflg = false;
			balloon_hp--;
		}
	}

	/*プレイヤーと鳥の当たり判定*/
	for (int i = 0; i < 16; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyBird[i])) && (g_EasyBird[i].activflg == true))
		{
			g_EasyBird[i].activflg = false;
			balloon_hp--;
		}
	}

	/*プレイヤーとボーナスアイテム小の当たり判定*/
	for (int i = 0; i < 34; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyBonus_Small[i])) && (g_EasyBonus_Small[i].activflg == true))
		{
 			g_EasyBonus_Small[i].activflg = false;
			BonusScore += 50;
		}
	}

	/*プレイヤーとボーナスアイテム中の判定*/
	for (int i = 0; i < 15; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyBonus_M[i])) && (g_EasyBonus_M[i].activflg == true))
		{
			g_EasyBonus_M[i].activflg = false;
			BonusScore += 100;
		}
	}

	/*プレイヤーとボーナスアイテム大*/
	for (int i = 0; i < 6; i++)
	{
		if ((CollisionBB(g_balloon, g_EasyBonus_Big[i])) && (g_EasyBonus_Big[i].activflg == true))
		{
			g_EasyBonus_Big[i].activflg = false;
			BonusScore += 200;
		}
	}

	//何時でも
	/*プレイヤーが画面下に下がり過ぎると*/
	if (g_balloon.y >= HEIGHT - g_balloon.scale - g_balloon.scale / 2)
	{
   		g_balloon.y += 2;
		g_balloon.y = 300.f;
		balloon_hp--;
	}

	/*プレイヤーが上に上がり過ぎると*/
	if (g_balloon.y <= 0 + g_balloon.scale)
	{
		g_balloon.y += 2;
		g_balloon.y = 300.f;
		balloon_hp--;
	}
}