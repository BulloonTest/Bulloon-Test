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

/*　マップの縦の大きさ　*/
#define	HEIGHT	720

/*　当たり判定をここで全て行っている　*/
void ManagerCollision()
{
	/*プレイヤーと蜂*/
	if (CollisionBB(g_balloon, g_hornet))
	{
		g_balloon.y += 2;
	}

	/*プレイヤーと雲*/
	if (CollisionBB(g_balloon, g_Cloud))
	{
		g_balloon.y += 2;
	}

	/*プレイヤーと雷*/
	if (CollisionBB(g_balloon, g_Thunder))
	{
		g_balloon.y += 2;
	}

	/*プレイヤーとゴール()*/
	if (CollisionBB(g_balloon, g_Goal))
	{
		g_balloon.y += 2;
	}

	/*プレイヤーと鳥の当たり判定*/
	if (CollisionBB(g_balloon, g_Bird))
	{
		g_balloon.y += 2;
	}

	/*プレイヤーが画面下に下がり過ぎると*/
	if (g_balloon.y >= HEIGHT - g_balloon.scale - g_balloon.scale / 2)
	{
   		g_balloon.y += 2;
	}

	/*プレイヤーが上に上がり過ぎると*/
	if (g_balloon.y <= 0 + g_balloon.scale)
	{
		g_balloon.y += 2;
	}
}