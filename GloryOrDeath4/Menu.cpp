#include "Menu.h"
#include "MenuButton.h"

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::update(float t_dt)
{
}

void Menu::draw(sf::RenderWindow * t_window, float t_dt)
{
	m_locTime += t_dt;
	if (m_locTime > m_animation.mpf)
	{
		m_animation.spriteSheet->setTextureRect(m_animation.nextSource());
		m_locTime = 0;
	}
	t_window->draw(*m_animation.spriteSheet);
}

void Menu::init(std::vector<std::vector<Animation>>t_buttonAnims)
{
	m_animation = m_animations[0];
	m_locTime = 0.f;
	for (int i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].init(t_buttonAnims[i]);
	}
}

void Menu::clickEvent(sf::IntRect t_mouseBox)
{
	for (int i = 0; i < m_buttons.size(); i++)
	{
		if (m_buttons[i].m_region.intersects(t_mouseBox))
			stateFunc(m_buttons[i].clickEvent());
	}
}

