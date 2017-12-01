/*　ゲーム内での描画を全てここで行っている　*/

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

/*　雷を出すカウント　*/
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