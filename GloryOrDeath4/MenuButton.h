#pragma once
#include <SFML/Graphics.hpp>
#include "vec2.h"
#include "Animation.h"
#include <iostream>
class MenuButton
{
public:
	MenuButton();
	MenuButton(std::string t_name, sf::IntRect t_region, bool t_active) :
		m_name(t_name), m_region(t_region), m_active(t_active) {}
	~MenuButton();
	 
	void update(float t_dt);
	void draw(sf::RenderWindow * t_window, float t_dt);
	void init(std::vector<Animation> t_anims);
	void setPosition(vec2f t_pos);
	int clickEvent();
	sf::IntRect m_region;
	vec2f m_position;
	std::string m_name;
private:
	bool m_active;
	float m_locTime;
	std::vector<Animation> m_animations;
	Animation m_animation;
};

