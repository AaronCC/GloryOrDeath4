#pragma once
#include <SFML/Graphics.hpp>
#include "vec2.h"
class MenuButton
{
public:
	MenuButton();
	MenuButton(std::string t_name, sf::IntRect t_region, bool t_active) :
		m_name(t_name), m_region(t_region), m_active(t_active) {}
	~MenuButton();
	 
	void setPosition(vec2ui t_pos);

	sf::IntRect m_region;
private:
	std::string m_name;
	bool m_active;
};

