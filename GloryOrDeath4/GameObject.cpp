#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::GameObject(std::string t_name, std::vector<Animation> t_anim)
{
	m_name = t_name;
	m_animations = t_anim;
	m_animation = m_animations[0];
	m_locTime = 0;
}

GameObject::~GameObject()
{
}

void GameObject::Update(float t_dt)
{

}

void GameObject::Draw(sf::RenderWindow * t_window, float t_dt)
{
	m_locTime += t_dt;
	if (m_locTime > m_animation.mpf)
	{
		m_animation.spriteSheet->setTextureRect(m_animation.nextSource());
		m_locTime = 0;
	}
	t_window->draw(*m_animation.spriteSheet);
}
