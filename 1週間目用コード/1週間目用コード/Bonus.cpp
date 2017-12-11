#include"Main.h"

#define GAMESPEED 1.5
#define EASYBONUSSMAIL 34

CHARCTER_STATE g_EasyBonus_Small[34];
CHARCTER_STATE g_EasyBonus_[14];
CHARCTER_STATE g_EasyBonus_Big[7];


void EasyCoordinateInit()
{
	//å„ÇÕçÇÇ≥Çí≤êÆ
	g_EasyBonus_Small[0]  = { 384.f,  300.f,64.f,0.f,true };
	g_EasyBonus_Small[1]  = { 512.f,  300.f,64.f,0.f,true };
	g_EasyBonus_Small[2]  = { 640.f,  300.f,64.f,0.f,true };
	g_EasyBonus_Small[3]  = { 896.f,  150.f,64.f,0.f,true };
	g_EasyBonus_Small[4]  = { 1280.F, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[5]  = { 1536.f, 450.f,64.f,0.f,true };
	g_EasyBonus_Small[6]  = { 1920.f, 500.f,64.f,0.f,true };
	g_EasyBonus_Small[7]  = { 2048.f, 250.f,64.f,0.f,true };
	g_EasyBonus_Small[8]  = { 2560.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[9]  = { 3200.f, 150.f,64.f,0.f,true };
	g_EasyBonus_Small[10] = { 3456.f, 150.f,64.f,0.f,true };
	g_EasyBonus_Small[11] = { 3712.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[12] = { 4096.f, 400.f,64.f,0.f,true };
	g_EasyBonus_Small[13] = { 4224.f, 350.f,64.f,0.f,true };
	g_EasyBonus_Small[14] = { 4352.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[15] = { 4480.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[16] = { 4608.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[17] = { 4864.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[18] = { 4992.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[19] = { 5120.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[20] = { 5248.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[21] = { 5632.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[22] = { 5888.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[23] = { 6016.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[24] = { 6144.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[25] = { 7296.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[26] = { 7424.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[27] = { 7552.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[28] = { 7680.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[29] = { 7808.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[30] = { 9472.f, 300.f,64.f,0.f,true };
	g_EasyBonus_Small[31] = { 10368.f,300.f,64.f,0.f,true };
	g_EasyBonus_Small[32] = { 10880.f,300.f,64.f,0.f,true };
	g_EasyBonus_Small[33] = { 11008.f,300.f,64.f,0.f,true };

}

void BonusCountrol()
{
	for (int i = 0; i < EASYBONUSSMAIL; i++)
	{
		g_EasyBonus_Small[i].x -= GAMESPEED;
	}
}