#pragma once
#include <map>
#include <string>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"
#include "Menu.h"
#include "MenuButton.h"
class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();
	
	MenuButton getButton(std::string t_name);
	bool init(std::map<std::string, std::vector<Animation>> t_anims,std::map<std::string,Menu>t_menus, std::map<std::string, MenuButton> t_buttons);
	sf::Sprite* getSprite(std::string t_name);
	std::vector<Animation>* getAnims(std::string t_name);
	bool loadSprite(std::string t_name);
	bool unloadSprite(std::string t_name);

private:
	
	std::map<std::string, std::vector<Animation>> m_animations;
	std::map<std::string, MenuButton> m_buttons;
	std::map<std::string, Menu> m_menus;
	std::map<std::string, sf::Sprite> m_sprites;
	std::map<std::string, sf::Texture> m_textures;
};

