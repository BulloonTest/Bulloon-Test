/*�@�Q�[���̏����������ő��点�Ă���@*/

#include"Main.h"
#include"DraManager.h"
#include"Scene.h"
#include"EasyRun.h"
#include"ClearRun.h"

/*�@�����ŃQ�[���𓮂����Ă���@*/
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
		//������Draw������
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
