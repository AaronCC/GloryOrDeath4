#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::GameObject(std::string t_name, std::vector<Animation> t_anim)
{
	m_name = t_name;
	m_animations = t_anim;
	setAnim(0);
	m_locTime = 0;
}

GameObject::~GameObject()
{
}

void GameObject::update(float t_dt)
{

}

void GameObject::draw(sf::RenderWindow * t_window, float t_dt)
{
	m_locTime += t_dt;
	if (m_locTime > m_animation.mpf)
	{
		m_animation.spriteSheet->setTextureRect(m_animation.nextSource());
		m_locTime = 0;
	}
	t_window->draw(*m_animation.spriteSheet);
}

void GameObject::setAnim(int index)
{
	if (index < m_animations.size())
		m_animation = m_animations[index];
}