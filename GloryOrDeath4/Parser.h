#pragma once
#include <SFML\Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "vec2.h"
#include "Animation.h"
#include "SpriteManager.h"
class Parser
{
public:
	Parser();
	~Parser();

	std::map <std::string, std::vector<Animation>> parseAnims(SpriteManager* t_sm);
};

