#include "MenuButton.h"



MenuButton::MenuButton()
{
}


MenuButton::~MenuButton()
{
}

void MenuButton::update(float t_dt)
{
}

void MenuButton::draw(sf::RenderWindow * t_window, float t_dt)
{
	m_locTime += t_dt;
	if (m_locTime > m_animation.mpf)
	{
		m_animation.spriteSheet->setTextureRect(m_animation.nextSource());
		m_locTime = 0;
	}
	t_window->draw(*m_animation.spriteSheet);
}

void MenuButton::init(std::vector<Animation> t_anims)
{
	m_animations = t_anims;
	m_locTime = 0.f;
	if (m_animations.size() > 2)
	{
		std::cout << "Error: button " << m_name << " has too many animations." << std::endl;
		return;
	}
	if (m_active)
		m_animation = m_animations[0];
	else
		m_animation = m_animations[1];
	m_animation.spriteSheet->move({ m_position.x, m_position.y });
}

void MenuButton::setPosition(vec2f t_pos)
{
	m_position = t_pos;
	m_region.left = t_pos.x;
	m_region.top = t_pos.y;
}

int MenuButton::clickEvent()
{
	return m_funcId;
}
