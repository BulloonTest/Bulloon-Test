/* ` â_(è·äQï®) ` */

#include<Windows.h>
#include<d3dx9.h>
#include"Main.h"
#include"Cloud.h"

#define GAMESPEED 1.5
#define EASYCLOUD 9

CHARCTER_STATE g_EasyCloud[9];
CHARCTER_STATE g_EasyThunder[9];

CHARCTER_STATE g_NormalCloud[24];
CHARCTER_STATE g_NormalThunder[24];

CHARCTER_STATE g_HardCloud[14];
CHARCTER_STATE g_HardThunder[14];

void EasyCloudInit()
{
	/* EasyMood */
	g_EasyCloud[0]   = { 7424.f,72.f, 96.f, 0.f ,true };
	g_EasyCloud[1]   = { 7552.f,72.f, 96.f, 0.f ,true };
	g_EasyCloud[2]   = { 7680.f,72.f, 96.f, 0.f ,true };
	g_EasyCloud[3]   = { 7808.f,72.f, 96.f, 0.f ,true };
	g_EasyCloud[4]   = { 8576.f,360.f,96.f, 0.f ,true };
	g_EasyCloud[5]   = { 8704.f,360.f,96.f, 0.f ,true };
	g_EasyCloud[6]   = { 8832.f,360.f,96.f, 0.f ,true };
	g_EasyCloud[7]   = { 8960.f,360.f,96.f, 0.f ,true };
	g_EasyCloud[8]   = { 9088.f,360.f,96.f, 0.f ,true };

	g_EasyThunder[0] = { 7424.f,177.f,64.f, 0.f ,true };
	g_EasyThunder[1] = { 7552.f,177.f,64.f, 0.f ,true };
	g_EasyThunder[2] = { 7680.f,177.f,64.f, 0.f ,true };
	g_EasyThunder[3] = { 7808.f,177.f,64.f, 0.f ,true };
	g_EasyThunder[4] = { 8576.f,465.f,64.f, 0.f ,true };
	g_EasyThunder[5] = { 8704.f,465.f,64.f, 0.f ,true };
	g_EasyThunder[6] = { 8832.f,465.f,64.f, 0.f ,true };
	g_EasyThunder[7] = { 8960.f,465.f,64.f, 0.f ,true };
	g_EasyThunder[8] = { 9088.f,465.f,64.f, 0.f ,true };
}

void NormalCloudInit()
{
	g_NormalCloud[0];
	g_NormalCloud[1];
	g_NormalCloud[2];
	g_NormalCloud[3];
	g_NormalCloud[4];
	g_NormalCloud[5];
	g_NormalCloud[6];
	g_NormalCloud[7];
	g_NormalCloud[8];
	g_NormalCloud[9];
	g_NormalCloud[10];
	g_NormalCloud[11];
	g_NormalCloud[12];
	g_NormalCloud[13];
	g_NormalCloud[14];
	g_NormalCloud[15];
	g_NormalCloud[16];
	g_NormalCloud[17];
	g_NormalCloud[18];
	g_NormalCloud[19];
	g_NormalCloud[20];
	g_NormalCloud[21];
	g_NormalCloud[22];
	g_NormalCloud[23];

	g_NormalThunder[0];
	g_NormalThunder[1];
	g_NormalThunder[2];
	g_NormalThunder[3];
	g_NormalThunder[4];
	g_NormalThunder[5];
	g_NormalThunder[6];
	g_NormalThunder[7];
	g_NormalThunder[8];
	g_NormalThunder[9];
	g_NormalThunder[10];
	g_NormalThunder[11];
	g_NormalThunder[12];
	g_NormalThunder[13];
	g_NormalThunder[14];
	g_NormalThunder[15];
	g_NormalThunder[16];
	g_NormalThunder[17];
	g_NormalThunder[18];
	g_NormalThunder[19];
	g_NormalThunder[20];
	g_NormalThunder[21];
	g_NormalThunder[22];
	g_NormalThunder[23];
}

void HardCloudInit()
{
	g_HardCloud[0];
	g_HardCloud[1];
	g_HardCloud[2];
	g_HardCloud[3];
	g_HardCloud[4];
	g_HardCloud[5];
	g_HardCloud[6];
	g_HardCloud[7];
	g_HardCloud[8];
	g_HardCloud[9];
	g_HardCloud[10];
	g_HardCloud[11];
	g_HardCloud[12];
	g_HardCloud[13];

	g_HardThunder[0];
	g_HardThunder[1];
	g_HardThunder[2];
	g_HardThunder[3];
	g_HardThunder[4];
	g_HardThunder[5];
	g_HardThunder[6];
	g_HardThunder[7];
	g_HardThunder[8];
	g_HardThunder[9];
	g_HardThunder[10];
	g_HardThunder[11];
	g_HardThunder[12];
	g_HardThunder[13];
}

void CloudControl()
{
	for (int i = 0; i < EASYCLOUD; i++)
	{
		g_EasyCloud[i].x -= GAMESPEED;
		g_EasyThunder[i].x -= GAMESPEED;
	}
}