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
	std::cout << "\tSpritesheet data..." << std::endl;
	for (std::string line; std::getline(fileStream, line);)
	{
		stream.clear();
		stream << line;
		stream >> name >> numAnims;
		std::cout << "\t\tanims for: " << name << "..." << std::endl;
		if (t_sm->loadSprite(name + ".png"))
			spriteSheet = t_sm->getSprite(name + ".png");
		else
		{
			std::cout << "\t\t\tError loading sprite: " << name << std::endl;
			break;
		}
		for (int i = 0; i < numAnims; i++)
		{
			stream.clear();
			std::getline(fileStream, line);
			vec2ui frames;
			stream << line;
			stream >> animName >> sourceRect.width >> sourceRect.height
				>> mpf >> frames.x >> frames.y;
			try
			{
				anims[name].push_back({ animName, spriteSheet, sourceRect, mpf, frames, i });
			}
			catch (std::bad_alloc& ba)
			{
				std::cerr << "bad_alloc caught: " << ba.what() << '\n';
			}
			std::cout << "\t\t\t" << line << std::endl;
		}
		std::cout << "\t\tspritesheet created: " << name << std::endl;
	}
	fileStream.close();
	std::cout << std::endl;
	return anims;
}

std::map<std::string, Menu> Parser::parseMenus(SpriteManager * t_sm)
{
	//std::map<std::string, Menu> menus;
	//std::vector<MenuButton> buttons;
	//std::ifstream menuStream("MenuData/Menus.txt");
	//std::stringstream stream;
	//std::string menuName, buttonName;
	//int numButtons;
	//vec2ui position;
	//vec2ui size;
	//std::cout << "\tmenu data..." << std::endl;
	//for (std::string line; std::getline(menuStream, line);)
	//{
	//	stream << line;
	//	stream >> menuName >> size.x >> size.y >> numButtons;
	//	std::cout << "\t\t" << line << std::endl;
	//	for (int i = 0; i < numButtons; i++)
	//	{
	//		stream.clear();
	//		std::getline(menuStream, line);
	//		stream << line;
	//		stream >> buttonName >> position.x >> position.y;
	//		MenuButton btn = t_sm->getButton(buttonName);
	//		btn.setPosition({ (size.x * (position.x / 100)) + (btn.m_region.width / 2),
	//						(size.y * (position.y / 100)) + (btn.m_region.height / 2) });
	//		buttons.push_back(btn);
	//		std::cout << "\t\t\t" << line << std::endl;
	//	}
	//	menus[menuName] = { menuName, size, buttons };
	//	std::cout << "\t\tMenu created: " << menuName << std::endl;
	//	buttons.clear();
	//}
	//menuStream.close();
	//std::cout << std::endl;
	//return menus;
	return std::map<std::string, Menu>();
}

std::map<std::string, std::pair<std::string, std::vector<std::string>>> Parser::parseMenuData(SpriteManager * t_sm)
{
	std::map<std::string, std::pair<std::string, std::vector<std::string>>> menus;
	std::vector<std::string> buttons;
	std::ifstream menuStream("MenuData/Menus.txt");
	std::stringstream stream;
	std::string menuName, buttonName, menuData;
	int numButtons;
	vec2ui position;
	vec2ui size;
	std::cout << "\tmenu data..." << std::endl;
	for (std::string line; std::getline(menuStream, line);)
	{
		menuData = line;
		stream << menuData;
		stream >> menuName >> size.x >> size.y >> numButtons;
		std::cout << "\t\t" << line << std::endl;
		for (int i = 0; i < numButtons; i++)
		{
			std::getline(menuStream, line);
			buttons.push_back(line);
			std::cout << "\t\t\t" << line << std::endl;
		}
		menus[menuName] = { menuData, buttons };
		std::cout << "\t\tMenu created: " << menuName << std::endl;
		buttons.clear();
	}
	menuStream.close();
	std::cout << std::endl;
	return menus;
}

std::map<std::string, std::string> Parser::parseButtonData(SpriteManager * t_sm)
{
	std::map<std::string, std::string> buttons;
	sf::IntRect region;
	bool active;
	std::stringstream stream;
	std::string name;
	std::ifstream buttonStream("MenuData/Buttons.txt");
	std::cout << "\tbutton data..." << std::endl;
	for (std::string line; std::getline(buttonStream, line);)
	{
		stream << line;
		stream >> name >> region.width >> region.height >> active;
		buttons[name] = line;
		std::cout << "\t\t" << line << std::endl;
	}
	buttonStream.close();
	std::cout << std::endl;
	return buttons;
}

std::map<std::string, MenuButton> Parser::parseButtons(SpriteManager * t_sm)
{
	std::map<std::string, MenuButton> buttons;
	/*sf::IntRect region;
	bool active;
	std::stringstream stream;
	std::string name;
	std::ifstream buttonStream("MenuData/Buttons.txt");
	std::cout << "\tbutton data..." << std::endl;
	for (std::string line; std::getline(buttonStream, line);)
	{
		stream << line;
		stream >> name >> region.width >> region.height >> active;
		buttons[name] = { name, region, active };
		std::cout << "\t\t" << line << std::endl;
	}
	buttonStream.close();
	std::cout << std::endl;*/
	return buttons;
}
