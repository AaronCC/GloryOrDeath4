#include "Parser.h"

Parser::Parser()
{
}


Parser::~Parser()
{
}

std::map<std::string, std::vector<Animation>> Parser::parseAnims(SpriteManager * t_sm)
{
	std::map<std::string, std::vector<Animation>> anims;
	std::stringstream stream;
	unsigned int numAnims;
	std::string name, animName;
	sf::IntRect sourceRect;
	sf::Sprite *spriteSheet = nullptr;
	float mpf;
	std::ifstream fileStream("Animations/Animations.txt");
	for (std::string line; std::getline(fileStream, line);)
	{
		stream << line;
		stream >> name >> numAnims;
		for (int i = 0; i < numAnims; i++)
		{
			stream.clear();
			std::getline(fileStream, line);
			vec2uint frames;
			stream << line;
			stream >> animName >> sourceRect.width >> sourceRect.height
				>> mpf >> frames.x >> frames.y;
			if (t_sm->loadSprite(name + ".png"))
				spriteSheet = t_sm->getSprite(name + ".png");
			anims[name].push_back({ animName, spriteSheet, sourceRect, mpf, frames, i });
			}
		}
		return anims;
	}

