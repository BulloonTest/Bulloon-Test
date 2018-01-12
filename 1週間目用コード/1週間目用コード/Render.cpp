/*　画像の設定：作成：貼り付けを行っています　*/

#include<Windows.h>
#include<d3dx9.h>
#include"main.h"
#include"Rotation.h"
#include"EasyRun.h"

//RenderStateの設定をここで
void SetTexture()
{
	/*ここを徹底的に勉強する事*/
	g_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}

//FromFileをここで関数化させました
void CreateTexture(const char* text, TEXTURE texture_ID)
{
	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT(text),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[texture_ID]);
}

void LoadTexture()
{
	//頂点に入れるデータを設定
	g_pD3Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	CreateTexture("Texture/背景(昼).png", BACKGROUND_TEX);
	CreateTexture("Texture/背景(昼).png", BACKGROUND_TEX2);
	CreateTexture("Texture/背景(夕).png", BACKGROUND_TEX3);
	CreateTexture("Texture/背景(夜).png", BACKGROUND_TEX4);
	CreateTexture("Texture/プレイヤー.png", BALLOON_TEX);
	CreateTexture("Texture/蜂2.png", HORNET_TEX);
	CreateTexture("Texture/鳥.png", BIRD_TEX);
	CreateTexture("Texture/鳥1.png", BIRD1_TEX);
	CreateTexture("Texture/雷雲2.png", CLOUD_TEX);
	CreateTexture("Texture/雷2.png", THUNDER_TEX);
	CreateTexture("Texture/カウントダウン3.png", COUNT3_TEX);
	CreateTexture("Texture/カウントダウン2.png", COUNT2_TEX);
	CreateTexture("Texture/カウントダウン1.png", COUNT1_TEX);
	CreateTexture("Texture/カウントダウン0.png", COUNTGO_TEX);
	CreateTexture("Texture/ボーナスアイテム小.png", BONUS_SMAIL_TEX);
	CreateTexture("Texture/ボーナスアイテム中.png", BONUS_M_TEX);
	CreateTexture("Texture/ボーナスアイテム大.png", BONUS_BIG_TEX);
	CreateTexture("Texture/風船アイコン１.png", HP1_TEX);
	CreateTexture("Texture/風船アイコン２.png", HP2_TEX);
	CreateTexture("Texture/Score.png", SCORE_TEX);
	CreateTexture("Texture/タイトル (2).png", TITLE_TEX);
	CreateTexture("Texture/ステージ選択.png", CHANGE_TEX);
	CreateTexture("Texture/ゲームクリア.png", CLEAR_TEX);
	CreateTexture("Texture/ゲームオーバー (1).png", GAMEOVER_TEX);
	CreateTexture("Texture/風船2.png", RECOVERY_TEX);
	CreateTexture("Texture/ゴールライン.png", GOAL_TEX);
}

//描画はしない：分けとく
void MakeVertex(CHARCTER_STATE Obj, CUSTOMVERTEX cv[])
{
	cv[0].x = cv[3].x = Obj.x - Obj.scale;
	cv[1].x = cv[2].x = Obj.x + Obj.scale;

	cv[0].y = cv[1].y = Obj.y - Obj.scale;
	cv[2].y = cv[3].y = Obj.y + Obj.scale;

	for (int i = 0; i < 4; i++)
	{
		cv[i].z = 1.f;
		cv[i].rhw = 1.f;
		cv[i].color = 0xFFFFFFFF;
	}

	cv[0].tu = cv[0].tv = cv[1].tv = cv[3].tu = 0.f;
	cv[1].tu = cv[2].tu = cv[2].tv = cv[3].tv = 1.f;

	Rotation(cv, Obj.ang);
}

//描画だけ
void CreateVertex(float Topx, float Topy, float Height, float Whidth, TEXTURE texture_ID)
{
	CUSTOMVERTEX cv[4];

	cv[0].x = Topx;
	cv[0].y = Topy;
	cv[1].x = Topx + Whidth;
	cv[1].y = Topy;
	cv[2].x = Topx + Whidth;;
	cv[2].y = Topy + Height;
	cv[3].x = Topx;
	cv[3].y = Topy + Height;

	for (int i = 0; i < 4; i++)
	{
		cv[i].z = 1.f;
		cv[i].rhw = 1.f;
		cv[i].color = 0xFFFFFFFF;
	}

	cv[0].tu = cv[0].tv = cv[1].tv = cv[3].tu = 0.f;
	cv[1].tu = cv[2].tu = cv[2].tv = cv[3].tv = 1.f;

	g_pD3Device->SetTexture(0, g_pTexture[texture_ID]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cv, sizeof(CUSTOMVERTEX));
}

//回転させて尚且つ描画も一緒に
void DrawVertex(CHARCTER_STATE Obj, TEXTURE texture_ID)
{
	CUSTOMVERTEX cv[4];

	cv[0].x = cv[3].x = Obj.x - Obj.scale;
	cv[1].x = cv[2].x = Obj.x + Obj.scale;

	cv[0].y = cv[1].y = Obj.y - Obj.scale;
	cv[2].y = cv[3].y = Obj.y + Obj.scale;

	for (int i = 0; i < 4; i++)
	{
		cv[i].z = 1.f;
		cv[i].rhw = 1.f;
		cv[i].color = 0xFFFFFFFF;
	}

	cv[0].tu = cv[0].tv = cv[1].tv = cv[3].tu = 0.f;
	cv[1].tu = cv[2].tu = cv[2].tv = cv[3].tv = 1.f;

	Rotation(cv, Obj.ang);

	g_pD3Device->SetTexture(0, g_pTexture[texture_ID]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cv, sizeof(CUSTOMVERTEX));
}

//画像切り替えのなんちゃってアニメーション用
void DrawSwitching(CHARCTER_STATE Obj, TEXTURE texture_ID1,TEXTURE ID2,int Dcount)
{
	CUSTOMVERTEX cv[4];

	cv[0].x = cv[3].x = Obj.x - Obj.scale;
	cv[1].x = cv[2].x = Obj.x + Obj.scale;

	cv[0].y = cv[1].y = Obj.y - Obj.scale;
	cv[2].y = cv[3].y = Obj.y + Obj.scale;

	for (int i = 0; i < 4; i++)
	{
		cv[i].z = 1.f;
		cv[i].rhw = 1.f;
		cv[i].color = 0xFFFFFFFF;
	}

	cv[0].tu = cv[0].tv = cv[1].tv = cv[3].tu = 0.f;
	cv[1].tu = cv[2].tu = cv[2].tv = cv[3].tv = 1.f;

	Rotation(cv, Obj.ang);

	if (Dcount > 60)
	{
		g_pD3Device->SetTexture(0, g_pTexture[texture_ID1]);
	}
	else
	{
		g_pD3Device->SetTexture(0, g_pTexture[ID2]);
	}

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cv, sizeof(CUSTOMVERTEX));
}

//複数表示させる時用
void Draws(int s, CHARCTER_STATE* n, TEXTURE m)
{
	for (int i = 0; i < s; i++)
	{
		if (n[i].activflg == true)
		{
			DrawVertex(n[i], m);
		}
	}
}

void DrawsSwitch(int s, CHARCTER_STATE* n, TEXTURE m, TEXTURE m2)
{
	static int Dcount;
	Dcount++;

	for (int i = 0; i < s; i++)
	{
		if (n[i].activflg == true)
		{
			DrawSwitching(n[i], m, m2, Dcount);
		}
	}

	if (Dcount > 120)
	{
		Dcount = 0;
	}

}

/*　ここは使うべき　*/
void TexSet(IDirect3DDevice9* pD3Device, LPDIRECT3DTEXTURE9 pTexture)
{
	g_pD3Device->SetTexture(0, pTexture);
}

void TexDraw(IDirect3DDevice9* pD3Device, LPCUSTOMVRTEX pVertex)
{
	g_pD3Device->DrawPrimitiveUP(
		D3DPT_TRIANGLEFAN,
		2, 
		pVertex, 
		sizeof(CUSTOMVERTEX));
}

void TexSetDraw(IDirect3DDevice9* pD3Device, LPDIRECT3DTEXTURE9 pTexture, LPCUSTOMVRTEX pVertex)
{
	TexSet(pD3Device, pTexture);

	g_pD3Device->DrawPrimitiveUP(
		D3DPT_TRIANGLEFAN,
		2,
		pVertex,
		sizeof(CUSTOMVERTEX));
}