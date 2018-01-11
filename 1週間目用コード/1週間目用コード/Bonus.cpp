#include"Main.h"

#define GAMESPEED 1.5
#define EASYBONUS_SMAIL 34
#define EASYBONUS_M 15
#define EASYBONUS_B 6
#define HARDBONUS_S 32

//Ea
CHARCTER_STATE g_EasyBonus_Small[34];
CHARCTER_STATE g_EasyBonus_M[15];
CHARCTER_STATE g_EasyBonus_Big[6];

//Nomal
CHARCTER_STATE g_NormalBonus_Small[30];
CHARCTER_STATE g_NormalBonus_M[17];
CHARCTER_STATE g_NormalBonus_Big[12];

//Hard
CHARCTER_STATE g_HardBonus_Small[32];
CHARCTER_STATE g_HardBonus_M[14];
CHARCTER_STATE g_HardBonus_Big[11];

void EasyCoordinateInit()
{
	//EasyMoodのボーナスアイテム小
	g_EasyBonus_Small[0]  = { 384.f,  360.f,64.f,0.f,true };
	g_EasyBonus_Small[1]  = { 512.f,  360.f,64.f,0.f,true };
	g_EasyBonus_Small[2]  = { 640.f,  360.f,64.f,0.f,true };
	g_EasyBonus_Small[3]  = { 896.f,  144.f,64.f,0.f,true };
	g_EasyBonus_Small[4]  = { 1280.F, 432.f,64.f,0.f,true };
	g_EasyBonus_Small[5]  = { 1536.f, 504.f,64.f,0.f,true };
	g_EasyBonus_Small[6]  = { 1920.f, 360.f,64.f,0.f,true };
	g_EasyBonus_Small[7]  = { 2048.f, 216.f,64.f,0.f,true };
	g_EasyBonus_Small[8]  = { 2560.f, 360.f,64.f,0.f,true };
	g_EasyBonus_Small[9]  = { 3200.f, 144.f,64.f,0.f,true };
	g_EasyBonus_Small[10] = { 3456.f, 288.f,64.f,0.f,true };
	g_EasyBonus_Small[11] = { 3712.f, 288.f,64.f,0.f,true };
	g_EasyBonus_Small[12] = { 4096.f, 432.f,64.f,0.f,true };
	g_EasyBonus_Small[13] = { 4224.f, 360.f,64.f,0.f,true };
	g_EasyBonus_Small[14] = { 4352.f, 288.f,64.f,0.f,true };
	g_EasyBonus_Small[15] = { 4480.f, 216.f,64.f,0.f,true };
	g_EasyBonus_Small[16] = { 4608.f, 144.f,64.f,0.f,true };
	g_EasyBonus_Small[17] = { 4864.f, 144.f,64.f,0.f,true };
	g_EasyBonus_Small[18] = { 4992.f, 216.f,64.f,0.f,true };
	g_EasyBonus_Small[19] = { 5120.f, 288.f,64.f,0.f,true };
	g_EasyBonus_Small[20] = { 5248.f, 360.f,64.f,0.f,true };
	g_EasyBonus_Small[21] = { 5632.f, 288.f,64.f,0.f,true };
	g_EasyBonus_Small[22] = { 5888.f, 432.f,64.f,0.f,true };
	g_EasyBonus_Small[23] = { 6016.f, 504.f,64.f,0.f,true };
	g_EasyBonus_Small[24] = { 6144.f, 504.f,64.f,0.f,true };
	g_EasyBonus_Small[25] = { 7296.f, 432.f,64.f,0.f,true };
	g_EasyBonus_Small[26] = { 7424.f, 432.f,64.f,0.f,true };
	g_EasyBonus_Small[27] = { 7552.f, 432.f,64.f,0.f,true };
	g_EasyBonus_Small[28] = { 7680.f, 432.f,64.f,0.f,true };
	g_EasyBonus_Small[29] = { 7808.f, 432.f,64.f,0.f,true };
	g_EasyBonus_Small[30] = { 9472.f, 360.f,64.f,0.f,true };
	g_EasyBonus_Small[31] = { 10368.f,288.f,64.f,0.f,true };
	g_EasyBonus_Small[32] = { 10880.f,288.f,64.f,0.f,true };
	g_EasyBonus_Small[33] = { 11008.f,288.f,64.f,0.f,true };

	//Easyのボーナスアイテム中
	g_EasyBonus_M[0]  = { 1536.f,  72.f,64.f,0.f,true };
	g_EasyBonus_M[1]  = { 2304.f,  288.f,64.f,0.f,true };
	g_EasyBonus_M[2]  = { 3584.f,  288.f,64.f,0.f,true };
	g_EasyBonus_M[3]  = { 4736.f,  72.f,64.f,0.f,true };
	g_EasyBonus_M[4]  = { 6528.F, 288.f,64.f,0.f,true };
	g_EasyBonus_M[5]  = { 7040.f, 216.f,64.f,0.f,true };
	g_EasyBonus_M[6]  = { 8576.f, 144.f,64.f,0.f,true };
	g_EasyBonus_M[7]  = { 8704.f, 144.f,64.f,0.f,true };
	g_EasyBonus_M[8]  = { 8832.f, 144.f,64.f,0.f,true };
	g_EasyBonus_M[9]  = { 8960.f, 144.f,64.f,0.f,true };
	g_EasyBonus_M[10] = { 9088.f, 144.f,64.f,0.f,true };
	g_EasyBonus_M[11] = { 9600.f, 432.f,64.f,0.f,true };
	g_EasyBonus_M[12] = { 9984.f, 72.f,64.f,0.f,true };
	g_EasyBonus_M[13] = { 11136.f, 288.f,64.f,0.f,true };
	g_EasyBonus_M[14] = { 11264.f, 288.f,64.f,0.f,true };

	//Easyのボーナスアイテム大
	g_EasyBonus_Big[0] = { 5376.f,  432.f,64.f,0.f,true };
	g_EasyBonus_Big[1] = { 5632.f,   72.f,64.f,0.f,true };
	g_EasyBonus_Big[2] = { 6784.f,   72.f,64.f,0.f,true };
	g_EasyBonus_Big[3] = { 8320.f,  432.f,64.f,0.f,true };
	g_EasyBonus_Big[4] = { 10752.F, 288.f,64.f,0.f,true };
	g_EasyBonus_Big[5] = { 11392.f, 288.f,64.f,0.f,true };
}

void NormalCoordinateInit()
{
	//Nomalのボーナスアイテム小
	g_NormalBonus_Small[0];
	g_NormalBonus_Small[1];
	g_NormalBonus_Small[2];
	g_NormalBonus_Small[3];
	g_NormalBonus_Small[4];
	g_NormalBonus_Small[5];
	g_NormalBonus_Small[6];
	g_NormalBonus_Small[7];
	g_NormalBonus_Small[8];
	g_NormalBonus_Small[9];
	g_NormalBonus_Small[10];
	g_NormalBonus_Small[11];
	g_NormalBonus_Small[12];
	g_NormalBonus_Small[13];
	g_NormalBonus_Small[14];
	g_NormalBonus_Small[15];
	g_NormalBonus_Small[16];
	g_NormalBonus_Small[17];
	g_NormalBonus_Small[18];
	g_NormalBonus_Small[19];
	g_NormalBonus_Small[20];
	g_NormalBonus_Small[21];
	g_NormalBonus_Small[22];
	g_NormalBonus_Small[23];
	g_NormalBonus_Small[24];
	g_NormalBonus_Small[25];
	g_NormalBonus_Small[26];
	g_NormalBonus_Small[27];
	g_NormalBonus_Small[28];
	g_NormalBonus_Small[29];
	g_NormalBonus_Small[30];

	//Nomalのボーナスアイテム中
	g_NormalBonus_M[0];
	g_NormalBonus_M[1];
	g_NormalBonus_M[2];
	g_NormalBonus_M[3];
	g_NormalBonus_M[4];
	g_NormalBonus_M[5];
	g_NormalBonus_M[6];
	g_NormalBonus_M[7];
	g_NormalBonus_M[8];
	g_NormalBonus_M[9];
	g_NormalBonus_M[10];
	g_NormalBonus_M[11];
	g_NormalBonus_M[12];
	g_NormalBonus_M[13];
	g_NormalBonus_M[14];
	g_NormalBonus_M[15];
	g_NormalBonus_M[16];

	//Nomalのボーナスアイテム大
	g_NormalBonus_Big[0];
	g_NormalBonus_Big[1];
	g_NormalBonus_Big[2];
	g_NormalBonus_Big[3];
	g_NormalBonus_Big[4];
	g_NormalBonus_Big[5];
	g_NormalBonus_Big[6];
	g_NormalBonus_Big[7];
	g_NormalBonus_Big[8];
	g_NormalBonus_Big[9];
	g_NormalBonus_Big[10];
	g_NormalBonus_Big[11];
}

void HardCoordinateInit()
{
	//HardMoodのボーナスアイテム小
	g_HardBonus_Small[0]  = {  512.f,  360.f,64.f,0.f,true };
	g_HardBonus_Small[1]  = {  768.f,  360.f,64.f,0.f,true };
	g_HardBonus_Small[2]  = {  896.f,  288.f,64.f,0.f,true };
	g_HardBonus_Small[3]  = { 1024.f,  216.f,64.f,0.f,true };
	g_HardBonus_Small[4]  = { 2560.F, 288.f,64.f,0.f,true };
	g_HardBonus_Small[5]  = { 2688.f, 288.f,64.f,0.f,true };
	g_HardBonus_Small[6]  = { 3456.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[7]  = { 3584.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[8]  = { 3712.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[9]  = { 3840.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[10] = { 3968.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[11] = { 4096.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[12] = { 4224.f, 144.f,64.f,0.f,true };
	g_HardBonus_Small[13] = { 4352.f, 144.f,64.f,0.f,true };
	g_HardBonus_Small[14] = { 4480.f, 144.f,64.f,0.f,true };
	g_HardBonus_Small[15] = { 4608.f, 144.f,64.f,0.f,true };
	g_HardBonus_Small[16] = { 4736.f, 144.f,64.f,0.f,true };;
	g_HardBonus_Small[17] = { 5120.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[18] = { 5376.f, 288.f,64.f,0.f,true };
	g_HardBonus_Small[19] = { 5504.f, 288.f,64.f,0.f,true };
	g_HardBonus_Small[20] = { 5632.f, 288.f,64.f,0.f,true };
	g_HardBonus_Small[21] = { 6272.f, 144.f,64.f,0.f,true };
	g_HardBonus_Small[22] = { 6528.f, 72.f,64.f,0.f,true };
	g_HardBonus_Small[23] = { 7168.f, 288.f,64.f,0.f,true };
	g_HardBonus_Small[24] = { 7552.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[25] = { 8320.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[26] = { 8576.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[27] = { 9344.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[28] = { 9472.f, 504.f,64.f,0.f,true };
	g_HardBonus_Small[29] = { 9856.f, 144.f,64.f,0.f,true };
	g_HardBonus_Small[30] = { 9984.f, 144.f,64.f,0.f,true };
	g_HardBonus_Small[31] = { 10752.f,288.f,64.f,0.f,true };

	//Hardアイテム中
	g_HardBonus_M[0];
	g_HardBonus_M[1];
	g_HardBonus_M[2];
	g_HardBonus_M[3];
	g_HardBonus_M[4];
	g_HardBonus_M[5];
	g_HardBonus_M[6];
	g_HardBonus_M[7];
	g_HardBonus_M[8];
	g_HardBonus_M[9];
	g_HardBonus_M[10];
	g_HardBonus_M[11];
	g_HardBonus_M[12];
	g_HardBonus_M[13];

	//Hardアイテム中
	g_HardBonus_Big[0];
	g_HardBonus_Big[1];
	g_HardBonus_Big[2];
	g_HardBonus_Big[3];
	g_HardBonus_Big[4];
	g_HardBonus_Big[5];
	g_HardBonus_Big[6];
	g_HardBonus_Big[7];
	g_HardBonus_Big[8];
	g_HardBonus_Big[9];
	g_HardBonus_Big[10];
}

void EasyBonusCountrol()
{
	for (int i = 0; i < EASYBONUS_SMAIL; i++)
	{
		g_EasyBonus_Small[i].x -= GAMESPEED;
	}

	for (int i = 0; i < EASYBONUS_M; i++)
	{
		g_EasyBonus_M[i].x -= GAMESPEED;
	}

	for (int i = 0; i < EASYBONUS_B; i++)
	{
		g_EasyBonus_Big[i].x -= GAMESPEED;
	}
}

void HardBonusCountrol()
{
	for (int i = 0; i < HARDBONUS_S; i++)
	{
		g_HardBonus_Small[i].x -= GAMESPEED;
	}
}