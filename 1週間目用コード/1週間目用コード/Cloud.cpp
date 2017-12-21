/* ` â_(è·äQï®) ` */

#include<Windows.h>
#include<d3dx9.h>
#include"Main.h"
#include"Cloud.h"

#define GAMESPEED 1.5
#define EASYCLOUD 9

CHARCTER_STATE g_EasyCloud[9];
CHARCTER_STATE g_EasyThunder[9];

void CloudInit()
{
	/* EasyMood */
	g_EasyCloud[0]   = { 7424.f,72.f,64.f, 0.f ,true };
	g_EasyCloud[1]   = { 7552.f,72.f,64.f, 0.f ,true };
	g_EasyCloud[2]   = { 7680.f,72.f,64.f, 0.f ,true };
	g_EasyCloud[3]   = { 7808.f,72.f,64.f, 0.f ,true };
	g_EasyCloud[4]   = { 8576.f,360.f,64.f, 0.f ,true };
	g_EasyCloud[5]   = { 8704.f,360.f,64.f, 0.f ,true };
	g_EasyCloud[6]   = { 8832.f,360.f,64.f, 0.f ,true };
	g_EasyCloud[7]   = { 8960.f,360.f,64.f, 0.f ,true };
	g_EasyCloud[8]   = { 9088.f,360.f,64.f, 0.f ,true };
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

void CloudControl()
{
	for (int i = 0; i < EASYCLOUD; i++)
	{
		g_EasyCloud[i].x -= GAMESPEED;
		g_EasyThunder[i].x -= GAMESPEED;
	}
}