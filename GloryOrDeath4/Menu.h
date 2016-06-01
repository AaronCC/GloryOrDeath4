#pragma once
#include <SFML/Graphics.hpp>
#include "MenuButton.h"
#include "vec2.h"
class Menu
{
public:
	Menu();
	Menu(std::string t_name, vec2ui t_size, std::vector<MenuButton> t_buttons) :
		m_name(t_name), m_size(t_size), m_buttons(t_buttons) {}
	~Menu();
	 
	std::string m_name;
	vec2ui m_size;
	std::vector<MenuButton> m_buttons;
};

