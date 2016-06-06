#include "InputManager.h"

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::resolveGameEvent(sf::RenderWindow* t_window, GameObject* t_player, sf::Event t_event)
{
	switch (t_event.type)
	{
	case sf::Event::Closed:
		t_window->close();
		break;

		// key pressed
	case sf::Event::KeyPressed:
		if (t_event.key.code == sf::Keyboard::Up)
		{
			t_player->setAnim(0);
		}
		if (t_event.key.code == sf::Keyboard::Left)
		{
			t_player->setAnim(1);
		}
		if (t_event.key.code == sf::Keyboard::Down)
		{
			t_player->setAnim(2);
		}
		if (t_event.key.code == sf::Keyboard::Right)
		{
			t_player->setAnim(3);
		}
		break;

		// we don't process other types of events
	default:
		break;
	}
}
void InputManager::resolveMenuEvent(sf::RenderWindow * t_window, Menu t_menu, sf::Event t_event)
{
	switch (t_event.type)
	{
	case sf::Event::MouseButtonPressed:
		t_menu.clickEvent({ t_event.mouseButton.x, t_event.mouseButton.y, 10, 10 });
		break;
	default:
		break;
	}
}
bool InputManager::init()
{
	return true;
}
