#include "Application.h"
#include "WindowManager.h"


Application::~Application()	
{
}

bool Application::init()
{
	state = LOADING;
	reloadWindow();
	std::cout << "Loading Assets..." << std::endl;
	if (!m_spriteManager.init(m_parser.parseAnims(&m_spriteManager),m_parser.parseMenus(&m_spriteManager),m_parser.parseButtons(&m_spriteManager)))
		return false;
	std::cout << "Initializing Window..." << std::endl;
	if (!m_windowManager.setWindow(&m_mainWindow, &m_spriteManager))
		return false;
	m_windowManager.setPlayer(m_windowManager.genObj("spritesheet"));
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
