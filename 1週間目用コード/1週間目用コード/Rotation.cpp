/*‰ñ“]‚Ìˆ—‚ğ‚±‚±‚Å‘‚­*/

#include<Windows.h>
#include<stdio.h>
#include"Main.h"

void Rotation(CUSTOMVERTEX* pObj,float angle)
{
	double rad;
	float temp_x;
	float temp_y;

	//rad = angle * (3.141592 / 180);

	rad = D3DXToRadian(angle);

	for (int i = 0; i < 4; i++)
	{
		temp_x = pObj[i].x;
		temp_y = pObj[i].y;

		pObj[i].x = (float)(temp_x*cos(rad) - temp_y*sin(rad));
		pObj[i].y = (float)(temp_y*cos(rad) + temp_x*sin(rad));
	}
}