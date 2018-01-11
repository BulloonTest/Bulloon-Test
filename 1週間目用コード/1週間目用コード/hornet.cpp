/*　蜂(障害物)の表示：行動　*/

#include<Windows.h>
#include<d3d9.h>
#include"hornet.h"
#include"Main.h"
#include"Rotation.h"

#define GAMESPEED 15
#define EASYHORNET 16

CHARCTER_STATE g_EasyHornet[16];
CHARCTER_STATE g_NormalHornet[5];
CHARCTER_STATE g_HardHornet[5];

static int count = 0;

void EasyHornetInit()
{
	g_EasyHornet[0]  = { 4096.f,144.f,64.f, 0.f,true };
	g_EasyHornet[1]  = { 5376.f,72.f,64.f, 0.f,true };
	g_EasyHornet[2]  = { 9600.f,72.f,64.f, 0.f,true };
	g_EasyHornet[3]  = { 9984.f,504.f,64.f, 0.f,true };
	g_EasyHornet[4]  = { 12096.f,144.f,64.f, 0.f,true };
	g_EasyHornet[5]  = { 14376.f,360.f,64.f, 0.f,true };
	g_EasyHornet[6]  = { 15600.f,432.f,64.f, 0.f,true };
	g_EasyHornet[7]  = { 19984.f,504.f,64.f, 0.f,true };
	g_EasyHornet[8]  = { 24096.f,576.f,64.f, 0.f,true };
	g_EasyHornet[9]  = { 25376.f,576.f,64.f, 0.f,true };
	g_EasyHornet[10] = { 29600.f,360.f,64.f, 0.f,true };
	g_EasyHornet[11] = { 29984.f,360.f,64.f, 0.f,true };
	g_EasyHornet[12] = { 30096.f,144.f,64.f, 0.f,true };
	g_EasyHornet[13] = { 30376.f,400.f,64.f, 0.f,true };
	g_EasyHornet[14] = { 30600.f,400.f,64.f, 0.f,true };
	g_EasyHornet[15] = { 30984.f,144.f,64.f, 0.f,true };
}

void NormalHornetInit()
{

}

void HardHornetInit()
{

}

void HornetControl()
{
	count++;
	for (int i = 0; i < EASYHORNET; i++)
	{
		g_EasyHornet[i].x -= GAMESPEED;
	}

	if (count > 60)
	{
		for (int i = 0; i < EASYHORNET; i++)
		{
			g_EasyHornet[i].y -= 3.5;
		}
	}
	else
	{
		for (int i = 0; i < EASYHORNET; i++)
		{
			g_EasyHornet[i].y += 3.5;
		}
	}

	if (count > 120)
	{
		count = 0;
	}

	for (int i = 0; i < 16; i++)
	{
		if (g_EasyHornet[i].y < 0)
		{
 			g_EasyHornet[i].y = 720.f;
		}
	}
}
