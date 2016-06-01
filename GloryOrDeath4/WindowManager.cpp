#include "WindowManager.h"
WindowManager::WindowManager()
{
}

WindowManager::~WindowManager()
{
}

sf::RenderWindow& WindowManager::getWindow() const
{
	return *m_mainWindow;
}

void WindowManager::renderFrame()
{
	sf::Event event;
	m_mainWindow->clear();
	while (getWindow().pollEvent(event))
	{
		m_inputManager.resolveEvent(m_mainWindow, m_player, event);
	}
	for (int i = 0; i < m_objects.size(); i++)
	{	
		m_deltaTime = m_mainClock.getElapsedTime().asMilliseconds() - m_prevTime;
		m_objects[i].update(m_deltaTime);
		m_objects[i].draw(m_mainWindow, m_deltaTime);
	}
	m_mainWindow->display();
	m_prevTime = m_mainClock.getElapsedTime().asMilliseconds();
}

GameObject* WindowManager::genObj(std::string name)
{	
	m_objects.push_back({ name, *m_spriteManager->getAnims(name) });
	return &m_objects[m_objects.size() - 1];
}
void WindowManager::setPlayer(GameObject* t_player)
{
	m_player = t_player;
}
bool WindowManager::setWindow(sf::RenderWindow * t_window, SpriteManager * t_sm)
{
	m_mainWindow = t_window;
	if (m_mainWindow == nullptr)
		return false;
	if (!m_inputManager.init())
		return false;
	m_spriteManager = t_sm;
	return true;
}

