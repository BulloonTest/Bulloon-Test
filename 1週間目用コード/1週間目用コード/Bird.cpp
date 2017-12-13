#include<Windows.h>
#include<d3d9.h>
#include"Main.h"

#define BIRDSPEED 4

CHARCTER_STATE g_EasyBird[16];

void BirdInit()
{
	g_EasyBird[0]  = { 896.f,  360.f,64.f,0.f,true };
	g_EasyBird[1]  = { 1408.f,  216.f,64.f,0.f,true };
	g_EasyBird[2]  = { 1536.f,  288.f,64.f,0.f,true };
	g_EasyBird[3]  = { 2304.f,  72.f,64.f,0.f,true };
	g_EasyBird[4]  = { 2304.F, 576.f,64.f,0.f,true };
	g_EasyBird[5]  = { 2688.f, 72.f,64.f,0.f,true };
	g_EasyBird[6]  = { 3072.f, 432.f,64.f,0.f,true };
	g_EasyBird[7]  = { 4736.f, 432.f,64.f,0.f,true };
	g_EasyBird[8]  = { 5888.f, 72.f,64.f,0.f,true };
	g_EasyBird[9]  = { 6016.f, 144.f,64.f,0.f,true };
	g_EasyBird[10] = { 6144.f, 216.f,64.f,0.f,true };
	g_EasyBird[11] = { 8192.f, 432.f,64.f,0.f,true };
	g_EasyBird[12] = { 10368.f, 72.f,64.f,0.f,true };
	g_EasyBird[13] = { 10368.f, 504.f,64.f,0.f,true };
	g_EasyBird[14] = { 10496.f, 144.f,64.f,0.f,true };
	g_EasyBird[15] = { 10496.f, 432.f,64.f,0.f,true };
}

void BirdControl()
{
	for (int i = 0; i < 16; i++)
	{
		g_EasyBird[i].x -= BIRDSPEED;
	}
}