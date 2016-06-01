#include "MenuButton.h"



MenuButton::MenuButton()
{
}


MenuButton::~MenuButton()
{
}

void MenuButton::setPosition(vec2ui t_pos)
{
	m_region.left = t_pos.x;
	m_region.top = t_pos.y;
}
