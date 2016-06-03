#pragma once
#include "WindowManager.h"
#include "SpriteManager.h"
#include "InputManager.h"
#include "Parser.h"
#include "GameObject.h"
#include "ThreadManager.h"
#include <thread>
class Application
{
public:
	Application()
		: m_windowManager() {}
	~Application();

	enum GAME_STATE
	{
		LOADING = 0,
		MENU = 1,
		GAME = 2
	};
	GAME_STATE m_state;

	bool init();
	void mainLoop();
	void reloadWindow();
private:
	sf::Sprite(*get)(std::string);
	WindowManager m_windowManager;
	SpriteManager m_spriteManager;
	ThreadManager m_threadManager;
	Parser m_parser;
	sf::RenderWindow m_mainWindow;

};

