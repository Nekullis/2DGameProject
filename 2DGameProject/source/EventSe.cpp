#include"s_gamemain.h"

void SceneGameMain::EventSe()
{
	switch (_StageNo)
	{
	case 1:
		if (SceneEv == 5)
		{
			PlaySoundMem(_se[SE_ENEMY1_EVENT1], DX_PLAYTYPE_BACK, TRUE);
		}
	}
}