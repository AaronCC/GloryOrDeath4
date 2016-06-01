#include "InputManager.h"

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::resolveEvent(sf::RenderWindow* t_window, GameObject* t_player, sf::Event t_Event)
{
		switch (t_Event.type)
		{
		case sf::Event::Closed:
			t_window->close();
			break;

			// key pressed
		case sf::Event::KeyPressed:
			if (t_Event.key.code == sf::Keyboard::Up)
			{
				t_player->setAnim(0);
			}
			if (t_Event.key.code == sf::Keyboard::Left)
			{
				t_player->setAnim(1);
			}
			if (t_Event.key.code == sf::Keyboard::Down)
			{
				t_player->setAnim(2);
			}
			if (t_Event.key.code == sf::Keyboard::Right)
			{
				t_player->setAnim(3);
			}
				break;

			// we don't process other types of events
		default:
			break;
		}
	
}
bool InputManager::init()
{
	return true;
}
