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
	MakeVertex(g_hornet, cv);
	TexSetDraw(g_pD3Device, g_pTexture[HORNET_TEX], cv);
	MakeVertex(g_Bird,cv);
	TexSetDraw(g_pD3Device, g_pTexture[BIRD_TEX], cv);
	MakeVertex(g_Goal,cv);
	TexSetDraw(g_pD3Device, g_pTexture[GOAL_TEX], cv);
	MakeVertex(g_balloon,cv);
	TexSetDraw(g_pD3Device, g_pTexture[BALLOON_TEX], cv);
	MakeVertex(g_Cloud,cv);
	TexSetDraw(g_pD3Device, g_pTexture[CLOUD_TEX], cv);

	if (TimeCount > 180)
	{
		LoadCount++;

		MakeVertex(g_Thunder,cv);
		TexSetDraw(g_pD3Device, g_pTexture[THUNDER_TEX], cv);

		if (LoadCount > 60)
		{
			TimeCount = 0;
			LoadCount = 0;
		}
	}
}