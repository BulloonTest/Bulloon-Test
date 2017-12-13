/*　ゴール(クリアの為に必要)　*/

#include<Windows.h>
#include<d3dx9.h>
#include"Main.h"
#include"Goal.h"

#define GAMESPEED 1.5

CHARCTER_STATE g_Goal = { 11776.f,400.f,128.f, 0.f ,true };

void Goalcountrol()
{
	g_Goal.x -= GAMESPEED;
}