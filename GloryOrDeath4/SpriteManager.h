#pragma once
#include <map>
#include <string>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"
class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	bool init(std::map<std::string, std::vector<Animation>> t_anims);
	sf::Sprite* getSprite(std::string t_name);
	std::vector<Animation>* getAnims(std::string t_name);
	bool loadSprite(std::string t_name);
	bool unloadSprite(std::string t_name);

private:
	std::map<std::string, std::vector<Animation>> m_animations;
	std::map<std::string, sf::Sprite> m_sprites;
	std::map<std::string, sf::Texture> m_textures;
};

