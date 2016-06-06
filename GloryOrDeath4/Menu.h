#pragma once
#include <SFML/Graphics.hpp>
#include "MenuButton.h"
#include "vec2.h"
class Menu
{
public:
	typedef void(*changeState)(int);

	Menu();
	Menu(std::string t_name, vec2ui t_size, std::vector<MenuButton> t_buttons, std::vector<Animation> t_anims, changeState t_stateFunc) :
		m_name(t_name), m_size(t_size), m_buttons(t_buttons), m_animations(t_anims), stateFunc(t_stateFunc) {}
	~Menu();
	
	changeState stateFunc;
	void update(float t_dt);
	void draw(sf::RenderWindow * t_window, float t_dt);
	void init(std::vector<std::vector<Animation>> t_buttonAnims);
	void clickEvent(sf::IntRect t_mouseBox);
	std::string m_name;
	vec2ui m_size;
	std::vector<MenuButton> m_buttons;
private:
	float m_locTime;
	std::vector<Animation> m_animations;
	Animation m_animation;
};

