#include "Application.h"
#include "WindowManager.h"


Application::~Application()	
{
}

bool Application::init()
{
	reloadWindow();
	if (!m_spriteManager.init(m_parser.parseAnims(&m_spriteManager)))
		return false;
	if (!m_windowManager.setWindow(&m_mainWindow, &m_spriteManager))
		return false;
	m_windowManager.genObj("Player");
	return true;
}

void Application::mainLoop()
{
	while (m_mainWindow.isOpen())
	{
		m_windowManager.renderFrame();
	}
}

void Application::reloadWindow()
{
	m_mainWindow.create(sf::VideoMode(800, 800), "Reloaded");
}
