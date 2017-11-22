#include<Windows.h>
#include<d3dx9.h>
#include"main.h"

void Settexture()
{
	/*‚±‚±‚ð“O’ê“I‚É•×‹­‚·‚éŽ–*/
	g_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}

/*createtexture*/
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

void Loadtexture()
{
	//’¸“_‚É“ü‚ê‚éƒf[ƒ^‚ðÝ’è
	g_pD3Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	CreateTexture("Test.jpg", BACKGROUND_TEX);
	CreateTexture("Test.jpg", BACKGROUND_TEX2);
	CreateTexture("•—‘D2.png", BALLOON_TEX);
	CreateTexture("–I2.png", HORNET_TEX);
	CreateTexture("—‹‰_2.png", CLOUD_TEX);
	CreateTexture("—‹2.png", RAIN_TEX);
}