//カラスはCrow　名前を後で全部変える

#include<Windows.h>
#include<d3d9.h>
#include"Main.h"

#define BIRDSPEED 4

CHARCTER_STATE g_EasyBird[16];
CHARCTER_STATE g_NormalBird[30];
CHARCTER_STATE g_HardBird[25];

void EasyBirdInit()
{
	//EasyMoodのカラス
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

void NormalBirdInit()
{
	g_NormalBird[0];
	g_NormalBird[1];
	g_NormalBird[2];
	g_NormalBird[3];
	g_NormalBird[4];
	g_NormalBird[5];
	g_NormalBird[6];
	g_NormalBird[7];
	g_NormalBird[8];
	g_NormalBird[9];
	g_NormalBird[10];
	g_NormalBird[11];
	g_NormalBird[12];
	g_NormalBird[13];
	g_NormalBird[14];
	g_NormalBird[15];
	g_NormalBird[16];
	g_NormalBird[17];
	g_NormalBird[18];
	g_NormalBird[19];
	g_NormalBird[20];
	g_NormalBird[21];
	g_NormalBird[22];
	g_NormalBird[23];
	g_NormalBird[24];
	g_NormalBird[25];
	g_NormalBird[26];
	g_NormalBird[27];
	g_NormalBird[28];
	g_NormalBird[29];
	g_NormalBird[30];

}

void HardBirdInit()
{
	g_HardBird[0];
	g_HardBird[1];
	g_HardBird[2];
	g_HardBird[3];
	g_HardBird[4];
	g_HardBird[5];
	g_HardBird[6];
	g_HardBird[7];
	g_HardBird[8];
	g_HardBird[9];
	g_HardBird[10];
	g_HardBird[11];
	g_HardBird[12];
	g_HardBird[13];
	g_HardBird[14];
	g_HardBird[15];
	g_HardBird[16];
	g_HardBird[17];
	g_HardBird[18];
	g_HardBird[19];
	g_HardBird[20];
	g_HardBird[21];
	g_HardBird[22];
	g_HardBird[23];
	g_HardBird[24];
	g_HardBird[25];
}

void BirdControl()
{
	for (int i = 0; i < 16; i++)
	{
		g_EasyBird[i].x -= BIRDSPEED;
	}
}