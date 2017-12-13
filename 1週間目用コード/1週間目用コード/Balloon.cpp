/*　風船の表示：行動　*/

#include<Windows.h>
#include<d3d9.h>
#include<dinput.h>
#include"Dinput.h"
#include"Main.h"
#include"Rotation.h"

#define WIDTH	1280
#define	HEIGHT	720

static float Gravity = 1.2;

/*パラメーター*/
// キャメルケースなら g_Balloon
CHARCTER_STATE g_balloon = { 100.f,400.f,64.f, 0.f,true };

void BalloonControl()
{
	static float da = 0.6f;

	KEYSTATE key[256];
	KeyCheckDinput(&key[DIK_SPACE], DIK_SPACE);

	static int cnt;

	/*重力を足していって下に落ちていくように*/
	g_balloon.y += Gravity;

	// 押してる時と押してない時は同時で条件を満たさないので
	// if elseに変更する
	/*SPEACEボタンを押している間は浮く*/
	if (key[DIK_SPACE] == ON)
	{
		g_balloon.y -= 6;
		g_balloon.ang = 0.f;
	}

	/*離すと最後に少し上に上昇するように*/
	if (key[DIK_SPACE] == RELEASE)
	{
		cnt = 10;
	}
	
	if (--cnt > 0)
	{
		g_balloon.y -= 3;
	}

	g_balloon.ang += da;

	if (fabs(g_balloon.ang) > 15.f) 
	{
		da *= -1;
	}

}