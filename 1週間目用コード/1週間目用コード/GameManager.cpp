/*　ゲームの処理をここで走らせている　*/

#include"Main.h"
#include"Render.h"
#include"Dinput.h"
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

/*　プレイヤーのライフ変更の為のカウント　*/

/*最初の三秒間止めるためのカウント*/
static int GameCount = 0;

static int TimeCount = 0;
static int LoadCount = 0;

/*　ここで全ての画像を生成と描画をしている　注意：置く順番に注意をする事　*/
void DrawManager()
{
	TimeCount++;

	BackDraw();
	Make(g_hornet, HORNET_TEX);
	Make(g_Bird, BIRD_TEX);
	Make(g_Goal, GOAL_TEX);
	Make(g_balloon, BALLOON_TEX);
	Make(g_cloud, CLOUD_TEX);

	if (TimeCount > 180)
	{
		LoadCount++;

		Make(g_Thunder, THUNDER_TEX);

		if (LoadCount > 60)
	{
			TimeCount = 0;
			LoadCount = 0;
		}
	}
}

/*　当たり判定をここで全て行っている　*/
void ManagerCollision()
{
	/*プレイヤーと蜂*/
	if (collisionBB(g_balloon, g_hornet))
	{
     		g_balloon.y += 2;
	}

	/*プレイヤーと雲*/
	if (collisionBB(g_balloon, g_cloud))
	{
		g_balloon.y += 2;
	}

	/*プレイヤーと雷*/
	if (collisionBB(g_balloon, g_Thunder))
	{
		g_balloon.y += 2;
	}

	/*プレイヤーとゴール()*/
	if (collisionBB(g_balloon, g_Goal))
	{
		g_balloon.y += 2;
	}

	/*プレイヤーと鳥の当たり判定*/
	if (collisionBB(g_balloon, g_Bird))
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