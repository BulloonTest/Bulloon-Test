#ifndef MAIN_H
#define MAIN_H

#define SAFE_RELEASE(p){if(p){(p)->Release();(p)=NULL;}}

#include<windows.h>
#include<d3dx9.h>
#include<dsound.h>

/* ���_�\���� */
typedef struct _CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
}CUSTOMVERTEX, *LPCUSTOMVRTEX;

enum TEXTURE
{
	/*�@�w�i�@*/
	BACKGROUND_TEX,
	BACKGROUND_TEX2,
	BALLOON_TEX,//���D
	HORNET_TEX,//�I
	CLOUD_TEX,//�_
	GOAL_TEX,//�S�[��
	THUNDER_TEX,//��
	HP_TEX,//�̗�
	SCORE_TEX,//�X�R�A
	/*�@�J�E���g�_�E���@*/
	COUNT3_TEX,
	COUNT2_TEX,
	COUNT1_TEX,
	COUNTGO_TEX,
	BIRD_TEX,//��
	CUMULONIMBUS_TEX,//�����_
	BONUS_SMAIL_TEX,//���{�[�i�X
	BONUS_M_TEX,//���{�[�i�X
	BONUS_BIG_TEX,//��{�[�i�X
	HP1_TEX,
	HP2_TEX,//�̗�
	TITLE_TEX,//�^�C�g��
	CHANGE_TEX,//�I�����
	CLEAR_TEX,//�Q�[���N���A
	GAMEOVER_TEX,//�Q�[���I�[�o�[
	RECOVERY_TEX,//�񕜃A�C�e��
	TEXMAX
};

typedef struct _CHARCTER_STATE
{
	float x, y, scale, ang;
	bool activflg;
}CHARCTER_STATE, *LPCHARCTER_STATE;

extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	�摜�̏������Ă����ׂ̔z��
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3D�̃f�o�C�X
extern D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	�p�����[�^
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		//	Direct3D�̃C���^�[�t�F�C�X

extern int Scenemanagement;

#endif