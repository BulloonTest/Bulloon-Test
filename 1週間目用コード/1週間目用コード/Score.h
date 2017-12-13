#ifndef SCORE_H
#define	SCORE_H

#define UI_SCORE_W	72
#define UI_SCORE_H	72
#define UI_SCORE_X	1000
#define UI_SCORE_Y	30

#define UI_SCORE_D	40	//1åÖÇÃïù

enum DRAWDIRECT {
	NOR,
	REV,
};

void ScoreMakeVertex(CUSTOMVERTEX* cv, float w, float h, float tu, float tv, float tw, float th, DRAWDIRECT dd = NOR);
void ScoreRender(int GameCnt,float GameBonus);
void FinalScore(int GameCnt, float GameBonus, int Hp);
extern float BonusScore;

#endif