#pragma once#include <map>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
class InputManager
{
public:
	InputManager();
	~InputManager();

	void resolveEvent(sf::RenderWindow* t_window, GameObject* t_player, sf::Event t_Event);
	bool init();

private:
};

