#include<Windows.h>
#include<d3d9.h>
#include"Main.h"

#define BIRDSPEED 5

CHARCTER_STATE g_Bird = { 3000.f,300.f,64.f,0.f };

void BirdControl()
{
	g_Bird.x -= BIRDSPEED;
}