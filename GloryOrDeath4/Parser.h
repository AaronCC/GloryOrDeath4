#pragma once
#include <SFML\Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "vec2.h"
#include "Animation.h"
#include "SpriteManager.h"
#include "Menu.h"
#include "MenuButton.h"
class Parser
{
public:
	Parser();
	~Parser();

	std::map<std::string, std::vector<Animation>> parseAnims(SpriteManager* t_sm);
	std::map<std::string, Menu> parseMenus(SpriteManager * t_sm);
	std::map<std::string, std::pair <std::string, std::vector<std::string>>> parseMenuData(SpriteManager *t_sm);
	std::map<std::string, std::string> parseButtonData(SpriteManager *t_sm);
	std::map<std::string, MenuButton> parseButtons(SpriteManager * t_sm);
};

