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

	sf::RenderWindow& getWindow() const;
	
	void renderFrame();
	void genObj(std::string name);
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

