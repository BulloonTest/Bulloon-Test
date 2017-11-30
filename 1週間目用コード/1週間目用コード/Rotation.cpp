/*回転の処理をここで書く*/

#include<Windows.h>
#include<stdio.h>
#include"Main.h"

void Rotation(CUSTOMVERTEX* pObj,float angle)
{
	double rad;
	float cx, cy;
	float temp_x;
	float temp_y;

	/* キャラクターの中心座標(x座標、y座標の足した半分)を出している */
	cx = (pObj[0].x + pObj[1].x) / 2;
	cy = (pObj[0].y + pObj[3].y) / 2;

	rad = D3DXToRadian(angle);

	for (int i = 0; i < 4; i++)
	{
		temp_x = pObj[i].x - cx;
		temp_y = pObj[i].y - cy;

		pObj[i].x = (float)(temp_x * cos(rad) - temp_y * sin(rad)) + cx;
		pObj[i].y = (float)(temp_y * cos(rad) + temp_x * sin(rad)) + cy;
	}
}