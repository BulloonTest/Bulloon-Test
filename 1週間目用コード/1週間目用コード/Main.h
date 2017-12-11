#ifndef MAIN_H
#define MAIN_H

#define SAFE_RELEASE(p){if(p){(p)->Release();(p)=NULL;}}

#include<windows.h>
#include<d3dx9.h>
#include<dsound.h>

/* 頂点構造体 */
typedef struct _CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
}CUSTOMVERTEX, *LPCUSTOMVRTEX;

enum TEXTURE
{
	/*　背景　*/
	BACKGROUND_TEX,
	BACKGROUND_TEX2,
	BALLOON_TEX,//風船
	HORNET_TEX,//蜂
	CLOUD_TEX,//雲
	GOAL_TEX,//ゴール
	THUNDER_TEX,//雷
	HP_TEX,//体力
	SCORE_TEX,//スコア
	/*　カウントダウン　*/
	COUNT3_TEX,
	COUNT2_TEX,
	COUNT1_TEX,
	COUNTGO_TEX,
	BIRD_TEX,//鳥
	CUMULONIMBUS,//入道雲

	TEXMAX
};

typedef struct _CHARCTER_STATE
{
	float x, y, scale, ang;
	bool activflg;
}CHARCTER_STATE, *LPCHARCTER_STATE;

extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	画像の情報を入れておく為の配列
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3Dのデバイス
extern D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	パラメータ
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		//	Direct3Dのインターフェイス

extern int Scenemanagement;

#endif