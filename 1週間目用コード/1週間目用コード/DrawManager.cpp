/*�@�Q�[�����ł̕`���S�Ă����ōs���Ă���@*/

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

/*�@�����o���J�E���g�@*/
static int TimeCount = 0;
static int LoadCount = 0;

/*�@�����őS�Ẳ摜�𐶐��ƕ`������Ă���@���ӁF�u�����Ԃɒ��ӂ����鎖�@*/
void DrawManager()
{
	CUSTOMVERTEX cv[4];

	TimeCount++;

	BackDraw();
	DrawVertex(g_hornet, HORNET_TEX);
	DrawVertex(g_Bird, BIRD_TEX);
	DrawVertex(g_Goal, GOAL_TEX);
	DrawVertex(g_balloon, BALLOON_TEX);
	DrawVertex(g_Cloud, CLOUD_TEX);

	if (TimeCount > 180)
	{
		LoadCount++;

		DrawVertex(g_Thunder, THUNDER_TEX);

		if (LoadCount > 60)
		{
			TimeCount = 0;
			LoadCount = 0;
		}
	}
}