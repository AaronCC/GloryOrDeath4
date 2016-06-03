#pragma once
#include <map>
#include <string>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"
#include "Menu.h"
#include "MenuButton.h"
#include <sstream>
#include <iostream>
class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	MenuButton getButton(std::string t_name);
	Menu getMenu(std::string t_name);
	std::pair<std::string,std::vector<std::string>> getMenuData(std::string t_name);
	std::string getButtonData(std::string t_name);
	bool init(std::map<std::string, std::string>t_buttons, std::map<std::string, std::vector<Animation>> t_anims, std::map < std::string, std::pair<std::string, std::vector<std::string>>> t_menus);
	sf::Sprite* getSprite(std::string t_name);
	std::vector<Animation> getAnims(std::string t_name);
	bool loadSprite(std::string t_name);
	bool unloadSprite(std::string t_name);
private:
	std::map<std::string, std::vector<Animation>> m_animations;
	std::map<std::string, MenuButton> m_buttons;
	std::map <std::string, std::string> m_buttonData;
	// < menu_name , < menu_data, < button_location_data > > >
	std::map <std::string, std::pair<std::string,std::vector<std::string>>> m_menuData;
	std::map<std::string, Menu> m_menus;
	std::map<std::string, sf::Sprite> m_sprites;
	std::map<std::string, sf::Texture> m_textures;
};

