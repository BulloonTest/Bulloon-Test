/*　スコアの表示：行動　*/

#include "Main.h"
#include "Score.h"
#include "HP.h"
#include "GameManager.h"

float BonusScore = 0;

void ScoreMakeVertex(CUSTOMVERTEX* cv, float w, float h, float tu, float tv, float tw, float th, DRAWDIRECT dd)
{
	cv[0].x = cv[3].x = 0;
	cv[1].x = cv[2].x = w;
	cv[0].y = cv[1].y = 0;
	cv[2].y = cv[3].y = h;

	for (int i = 0; i < 4; i++)
	{
		cv[i].z = 1.0f;
		cv[i].rhw = 1.0f;
		cv[i].color = 0xFFFFFFFF;
	}

	cv[0].tu = cv[3].tu = ((dd == NOR) ? tu : tu + w) / tw;  //if文？  ddがNORなら　tu / tw を代入？　偽なら tu + w / tw を代入？
	cv[1].tu = cv[2].tu = ((dd == NOR) ? tu + w : tu) / tw;
	cv[0].tv = cv[1].tv = tv / th;
	cv[2].tv = cv[3].tv = (tv + h) / th;
}

void ScoreRender(int GameCnt,float GameBonus)
{
	CUSTOMVERTEX cv[4];

	int score;
	int degit;

	score = (GameCnt - STARTCOUNT) / 60 * 10 + GameBonus;

	for (int i = 0; i < 10; i++) 
	{
		degit = score % 10;

		ScoreMakeVertex(cv, UI_SCORE_W, UI_SCORE_H, degit * 72, 0, 2048.0f, 1024.0f);
		SetVertexPos(cv, UI_SCORE_X - i * UI_SCORE_D, UI_SCORE_Y, UI_SCORE_W, UI_SCORE_H,1.f);
		RenderObject(cv, SCORE_TEX);

		score /= 10;

		if (score == 0) break;

	}
}

void FinalScore(int GameCnt, float GameBonus,int Hp)
{
	CUSTOMVERTEX cv[4];

	int score;
	int degit;

	score = (GameCnt - STARTCOUNT) / 60 * 10 + GameBonus + Hp;

	for (int i = 0; i < 10; i++)
	{
		degit = score % 10;

		ScoreMakeVertex(cv, UI_SCORE_W, UI_SCORE_H, degit * 72, 0, 2048.0f, 1024.0f);
		SetVertexPos(cv, UI_SCORE_X - i * UI_SCORE_D, UI_SCORE_Y, UI_SCORE_W, UI_SCORE_H, 1.f);
		RenderObject(cv, SCORE_TEX);

		score /= 10;

		if (score == 0) break;

	}
}