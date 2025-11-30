#include "UIItem.h"

// UIItemƒNƒ‰ƒX
UIItem::UIItem() 
{
	cgKey = 0;
	cgKnife = 0;
}
UIItem::~UIItem() 
{
}

// •`‰æ
void	UIItem::Draw(int cgKey, int cgKnife)
{
	DrawGraph(0, 0,cgKey,TRUE);
	DrawGraph(150, 0, cgKnife, TRUE);
}