#pragma once#include <map>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Menu.h"
class InputManager
{
public:
	InputManager();
	~InputManager();

	int resolveGameEvent(sf::RenderWindow* t_window, GameObject* t_player, sf::Event t_event);
	int resolveMenuEvent(sf::RenderWindow* t_window, Menu t_menu, sf::Event t_event);
	bool init();

private:
};

