/*@“–‚½‚è”»’è‚ÌŠÖ”‚ğ‚±‚±‚Åì‚è‚Ü‚·@*/

#include<Windows.h>
#include<d3dx9.h>
#include"Main.h"


bool CollisionBB(CHARCTER_STATE obj1, CHARCTER_STATE obj2)
{
	if ((obj1.x - obj1.scale / 2 < obj2.x + obj2.scale / 2) &&
		(obj2.x - obj2.scale / 2 < obj1.x + obj1.scale / 2) &&
		(obj1.y - obj1.scale / 2 < obj2.y + obj2.scale / 2) &&
		(obj2.y - obj2.scale / 2 < obj1.y + obj1.scale / 2))
	{
		return true;
	}
	else
	{
 		return false;
	}
}