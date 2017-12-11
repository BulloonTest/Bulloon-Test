/*　蜂(障害物)の表示：行動　*/

#include<Windows.h>
#include<d3d9.h>
#include"hornet.h"
#include"Main.h"
#include"Rotation.h"

#define GAMESPEED 1.5

CHARCTER_STATE g_hornet = { 700.f,300.f,64.f, 0.f,true };
CHARCTER_STATE g_EasyHornet[4];

static int count = 0;
static bool activ = false;

void HornetControl()
{
	count++;

	g_hornet.x -= GAMESPEED;

	if (count > 60)
	{
		g_hornet.y -= 3.5;
	}
	else
	{
		g_hornet.y += 3.5;
	}

	if (count > 130)
	{
		count = 0;
	}

}
