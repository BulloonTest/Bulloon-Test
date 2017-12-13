#include<Windows.h>
#include<d3d9.h>
#include"Main.h"


CHARCTER_STATE g_EasyRecovery[4];

void EasyRecoveryInit()
{
	g_EasyRecovery[0] = { 3712.f,  648.f,64.f,0.f,true };
	g_EasyRecovery[1] = { 6784.f,  648.f,64.f,0.f,true };
	g_EasyRecovery[2] = { 6912.f,  648.f,64.f,0.f,true };
	g_EasyRecovery[3] = { 9216.f,  648.f,64.f,0.f,true };
}

void RecoveryControl()
{
	for (int i = 0; i < 4; i++)
	{
		g_EasyRecovery[i].x -= 1.5;
		g_EasyRecovery[i].y -= 0.05;
	}
}