#pragma once
#include <SFML/Graphics.hpp>
#include "vec2.h"
#include "SpriteManager.h"
#include "GameObject.h"
#include "InputManager.h"
#include <stack>
class WindowManager
{
public:
	WindowManager();
	~WindowManager();

	enum GAME_STATE
	{
		LOADING = 0,
		MENU = 1,
		GAME = 2
	};
	GAME_STATE state;

	sf::RenderWindow& getWindow() const;
	
	int renderFrame();
	int renderMenu();
	GameObject* genObj(std::string name);
	Menu* genMenu(std::string t_name);
	MenuButton genButton(std::string t_name);
	void setPlayer(GameObject * t_player);
	void pushMenu(std::string t_name);
	bool setWindow(sf::RenderWindow* t_window, SpriteManager* t_sm);
private:
	int pollGameEvents();
	int pollMenuEvents();
	std::stack<Menu> m_menuStack;
	std::vector<Menu> m_menus;
	GameObject* m_player;
	std::vector<GameObject> m_objects;
	vec2f m_resolution;
	sf::RenderWindow* m_mainWindow;
	SpriteManager* m_spriteManager;
	InputManager m_inputManager;
	sf::Clock m_mainClock;
	float m_prevTime, m_deltaTime;
};

