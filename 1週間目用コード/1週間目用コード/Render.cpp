/*�@�摜�̐ݒ�F�쐬�F�\��t�����s���Ă��܂��@*/

#include<Windows.h>
#include<d3dx9.h>
#include"main.h"
#include"Rotation.h"

void SetTexture()
{
	/*������O��I�ɕ׋����鎖*/
	g_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}


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
	//���_�ɓ����f�[�^��ݒ�
	g_pD3Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	CreateTexture("test.jpg", BACKGROUND_TEX);
	CreateTexture("Test.jpg", BACKGROUND_TEX2);
	CreateTexture("�v���C���[.png", BALLOON_TEX);
	CreateTexture("�I2.png", HORNET_TEX);
	CreateTexture("��.png", BIRD_TEX);
	CreateTexture("���_2.png", CLOUD_TEX);
	CreateTexture("��2.png", THUNDER_TEX);
	CreateTexture("�J�E���g�_�E��3.png", COUNT3_TEX);
	CreateTexture("�J�E���g�_�E��2.png", COUNT2_TEX);
	CreateTexture("�J�E���g�_�E��1.png", COUNT1_TEX);
	CreateTexture("�J�E���g�_�E��0.png", COUNTGO_TEX);
	CreateTexture("�{�[�i�X�A�C�e����.png", BONUS_SMAIL_TEX);
	CreateTexture("�{�[�i�X�A�C�e����.png", BONUS_M_TEX);
	CreateTexture("�{�[�i�X�A�C�e����.png", BONUS_BIG_TEX);
	CreateTexture("���D�A�C�R���P.png", HP1_TEX);
	CreateTexture("���D�A�C�R���Q.png", HP2_TEX);
	CreateTexture("Score.png", SCORE_TEX);
	CreateTexture("�^�C�g��.png", TITLE_TEX);
	CreateTexture("�I�����.png", CHANGE_TEX);
	CreateTexture("�Q�[���N���A.png", CLEAR_TEX);
	CreateTexture("�Q�[���I�[�o�[.png", GAMEOVER_TEX);
	CreateTexture("���D2.png", RECOVERY_TEX);
}

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