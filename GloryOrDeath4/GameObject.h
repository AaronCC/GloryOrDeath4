#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "vec2.h"
#include "Animation.h"
struct Transform {
	vec2f scale;
	vec2f rotation;
	vec2f location;
};
struct Body {
	vec2f force;
	vec2f velocity;
	float mass;
};
class GameObject
{
public:
	GameObject();
	GameObject(std::string t_name, std::vector<Animation> t_anim);
	~GameObject();
	
	void update(float t_dt);
	void draw(sf::RenderWindow* t_window, float t_dt);
	void setAnim(int index);
	std::string m_name;
private:
	float m_locTime;
	sf::Sprite m_sprite;
	std::vector<Animation> m_animations;
	Animation m_animation;
	Body m_body;
	Transform m_transform;
};

