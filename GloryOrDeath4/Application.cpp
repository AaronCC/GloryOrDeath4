#include "Application.h"
#include "WindowManager.h"


Application::~Application()
{
}

bool Application::init()
{
	m_state = LOADING;

	reloadWindow();

	std::cout << "Loading Assets..." << std::endl;
	if (!m_spriteManager.init(m_parser.parseButtonData(&m_spriteManager), m_parser.parseAnims(&m_spriteManager),m_parser.parseMenuData(&m_spriteManager)))
		return false;
	std::cout << "Initializing Window..." << std::endl;
	if (!m_windowManager.setWindow(&m_mainWindow, &m_spriteManager))
		return false;
	m_windowManager.setPlayer(m_windowManager.genObj("spritesheet"));
	m_windowManager.pushMenu("mainmenu");

	m_state = MENU;
	return true;

}

void Application::mainLoop()
{
	while (m_mainWindow.isOpen())
	{
		switch (m_state)
		{
		case LOADING:
			break;
		case MENU:
			m_state = (GAME_STATE)m_windowManager.renderMenu();
			break;
		case GAME:
			m_state = (GAME_STATE)m_windowManager.renderFrame();
			break;
		default:
			break;
		}
	}
}

void Application::reloadWindow()
{
	m_mainWindow.create(sf::VideoMode(800, 800), "Reloaded");
}
