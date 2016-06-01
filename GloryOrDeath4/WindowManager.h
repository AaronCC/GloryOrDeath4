#pragma once
#include <SFML/Graphics.hpp>
#include "vec2.h"
#include "SpriteManager.h"
#include "GameObject.h"
#include "InputManager.h"
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
	
	void renderFrame();
	GameObject* genObj(std::string name);
	void setPlayer(GameObject * t_player);
	bool setWindow(sf::RenderWindow* t_window, SpriteManager* t_sm);
private:
	GameObject* m_player;
	std::vector<GameObject> m_objects;
	vec2f m_resolution;
	sf::RenderWindow* m_mainWindow;
	SpriteManager* m_spriteManager;
	InputManager m_inputManager;
	sf::Clock m_mainClock;
	float m_prevTime, m_deltaTime;
};

