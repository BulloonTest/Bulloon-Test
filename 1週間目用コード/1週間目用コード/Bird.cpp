#include<Windows.h>
#include<d3d9.h>
#include"Main.h"

#define BIRDSPEED 5

CHARCTER_STATE g_Bird = { 3000.f,450.f,64.f,0.f,true };
CHARCTER_STATE g_EasyBird[16];

void BirdInit()
{
	g_EasyBird[0]  = { 384.f,  300.f,64.f,0.f,true };
	g_EasyBird[1]  = { 512.f,  300.f,64.f,0.f,true };
	g_EasyBird[2]  = { 640.f,  300.f,64.f,0.f,true };
	g_EasyBird[3]  = { 896.f,  150.f,64.f,0.f,true };
	g_EasyBird[4]  = { 1280.F, 300.f,64.f,0.f,true };
	g_EasyBird[5]  = { 1536.f, 450.f,64.f,0.f,true };
	g_EasyBird[6]  = { 1920.f, 500.f,64.f,0.f,true };
	g_EasyBird[7]  = { 2048.f, 250.f,64.f,0.f,true };
	g_EasyBird[8]  = { 2560.f, 300.f,64.f,0.f,true };
	g_EasyBird[9]  = { 3200.f, 150.f,64.f,0.f,true };
	g_EasyBird[10] = { 3456.f, 150.f,64.f,0.f,true };
	g_EasyBird[11] = { 3712.f, 300.f,64.f,0.f,true };
	g_EasyBird[12] = { 4096.f, 400.f,64.f,0.f,true };
	g_EasyBird[13] = { 4224.f, 350.f,64.f,0.f,true };
	g_EasyBird[14] = { 4352.f, 300.f,64.f,0.f,true };
	g_EasyBird[15] = { 4480.f, 300.f,64.f,0.f,true };
}

void BirdControl()
{
	g_Bird.x -= BIRDSPEED;
}