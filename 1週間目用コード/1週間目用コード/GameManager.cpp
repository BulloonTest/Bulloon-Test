/*　ゲームの処理をここで走らせている　*/

#include"Main.h"
#include"DraManager.h"
#include"Scene.h"
#include"EasyRun.h"
#include"ClearRun.h"

/*　ここでゲームを動かしている　*/
void ManagerRun()
{
	switch (Scenemanagement)
	{
	case TITLE_SCENE:
		DrawManager();
		break;
	case CHANGE_SCENE:
		DrawManager();
		break;
	case EASY_SCENE:
		EasyRun();
		//ここにDrawをかく
		break;
	case NOMAL_SCENE:
		DrawManager();
		break;
	case HARD_SCENE:
		DrawManager();
		break;
	case CLEAR_SCENE:
		ClearRun();
		break;
	case OVER_SCENE:
		DrawManager();
		break;
	}

}
