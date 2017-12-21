#include"Main.h"
#include"Score.h"
#include"CollisionManager.h"
#include"DraManager.h"
#include"HP.h"

static int GameCount = 0;

void ClearRun()
{
	GameCount++;
	DrawManager();
	FinalScore(GameCount, BonusScore, balloon_hp);
}