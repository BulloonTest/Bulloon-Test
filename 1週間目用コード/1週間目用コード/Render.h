#ifndef  RENDER_H
#define	 RENDER_H

#include<d3d9.h>
#include"Main.h"

void SetTexture();
void LoadTexture();
// MakeVertex�������Ƌ@�\�Ƃ��ĕ�����Â炢
// Obje��texture_ID�̖��O�̋K�����قȂ� nkt
void MakeVertex(CHARCTER_STATE Obj, CUSTOMVERTEX cv[]);

/*�@�������@*/
void TexSetDraw(IDirect3DDevice9* pD3Device, LPDIRECT3DTEXTURE9 pTexture, LPCUSTOMVRTEX pVertex);
void TexDraw(IDirect3DDevice9* pD3Device, LPCUSTOMVRTEX pVertex);
void TexSet(IDirect3DDevice9* pD3Device, LPDIRECT3DTEXTURE9 pTexture);

#endif