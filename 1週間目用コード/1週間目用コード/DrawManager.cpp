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
#include"Bonus.h"
#include"EasyDraw.h"
#include"Scene.h"
#include"Title.h"
#include"ChangeScene.h"
#include"Clear.h"
#include"Over.h"
#include"Score.h"

/*　ここで全ての画像を生成と描画をしている　注意：置く順番に注意をする事　*/
void DrawManager()
{
	switch (Scenemanagement)
	{
	case TITLE_SCENE:
		TitleDraw();
		break;
	case CHANGE_SCENE:
		ChangeDraw();
		break;
	case EASY_SCENE:
		EasyDraw();
		break;
	case NOMAL_SCENE:
		break;
	case HARD_SCENE:
		break;
	case CLEAR_SCENE:
		ClearDraw();
		break;
	case OVER_SCENE:
		OverDraw();
		break;
	}

}
//
//enum SCENE_LIST
//{
//	TITLE_SCENE,
//	EASY_SCENE,
//	NOMAL_SCENE,
//	HARD_SCENE,
//	EXTRA_SCENE,
//	MAX_SCENE,
//};