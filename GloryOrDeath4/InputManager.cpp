#include "InputManager.h"

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::resolveEvent(sf::RenderWindow* t_window, GameObject* t_player, sf::Event t_Event)
{
	while (t_window->pollEvent(t_Event))
	{
		switch (t_Event.type)
		{
		case sf::Event::Closed:
			t_window->close();
			break;

			// key pressed
		case sf::Event::KeyPressed:
			if (t_Event.key.code == sf::Keyboard::Right)
			{

			}
				break;

			// we don't process other types of events
		default:
			break;
		}
	}
}
bool InputManager::init()
{
	return true;
}
