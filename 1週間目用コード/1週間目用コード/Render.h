#ifndef  RENDER_H
#define	 RENDER_H

#include<d3d9.h>
#include"Main.h"

void SetTexture();
void LoadTexture();
// MakeVertexだけだと機能として分かりづらい
// Objeとtexture_IDの名前の規則が異なる nkt
void MakeVertex(CHARCTER_STATE Obj, CUSTOMVERTEX cv[]);

/*　未説明　*/
void TexSetDraw(IDirect3DDevice9* pD3Device, LPDIRECT3DTEXTURE9 pTexture, LPCUSTOMVRTEX pVertex);
void TexDraw(IDirect3DDevice9* pD3Device, LPCUSTOMVRTEX pVertex);
void TexSet(IDirect3DDevice9* pD3Device, LPDIRECT3DTEXTURE9 pTexture);

#endif