/* ` â_(è·äQï®) ` */

#include<Windows.h>
#include<d3dx9.h>
#include"Main.h"
#include"Cloud.h"

#define GAMESPEED 1.5

CHARCTER_STATE g_Cloud = { 1400.f,150.f,128.f, 0.f ,true };
CHARCTER_STATE g_Thunder = { g_Cloud.x,g_Cloud.y + 105.f,64.f, 0.f ,true };

CHARCTER_STATE g_EasyCloud[9];
CHARCTER_STATE g_EasyThunder[9];

static int TimeCount = 0;
static int LoadCount = 0;

void CloudControl()
{
	g_Cloud .x -= GAMESPEED;
	g_Thunder.x -= GAMESPEED;
}