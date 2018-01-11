#include"Main.h"
#include"Score.h"
#include"CollisionManager.h"
#include"DraManager.h"
#include"HP.h"
#include "GameManager.h"
#include"EasyRun.h"

void ClearRun()
{
	DrawManager();
	FinalScore(GameCount, BonusScore, balloon_hp);
}