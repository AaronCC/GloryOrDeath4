#pragma once
#include "WindowManager.h"
#include "SpriteManager.h"
#include "InputManager.h"
#include "Parser.h"
#include "GameObject.h"
class Application
{
public:
	Application()
		: m_windowManager() {}
	~Application();

	bool init();
	void mainLoop();
	void reloadWindow();
private:
	sf::Sprite(*get)(std::string);
	WindowManager m_windowManager;
	SpriteManager m_spriteManager;
	Parser m_parser;
	sf::RenderWindow m_mainWindow;
};

