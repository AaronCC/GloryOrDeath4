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

int WindowManager::renderFrame()
{
	for (int i = 0; i < m_objects.size(); i++)
	{
		m_deltaTime = m_mainClock.getElapsedTime().asMilliseconds() - m_prevTime;
		m_objects[i].update(m_deltaTime);
		m_objects[i].draw(m_mainWindow, m_deltaTime);
	}
	m_mainWindow->display();
	m_prevTime = m_mainClock.getElapsedTime().asMilliseconds();
	return pollGameEvents();
}
int WindowManager::renderMenu()
{
	if (m_menuStack.size() > 0)
	{
		m_deltaTime = m_mainClock.getElapsedTime().asMilliseconds() - m_prevTime;
		m_menuStack.top().update(m_deltaTime);
		m_menuStack.top().draw(m_mainWindow, m_deltaTime);
		for (int i = 0; i < m_menuStack.top().m_buttons.size(); i++)
			m_menuStack.top().m_buttons[i].draw(m_mainWindow, m_deltaTime);
	}
	m_mainWindow->display();
	m_prevTime = m_mainClock.getElapsedTime().asMilliseconds();

	return pollMenuEvents();
}
int WindowManager::pollGameEvents()
{
	int state = 2;
	m_mainWindow->clear();
	sf::Event event;
	while (getWindow().pollEvent(event))
	{
		state = m_inputManager.resolveGameEvent(m_mainWindow, m_player, event);
	}
	return state;
}
int WindowManager::pollMenuEvents()
{
	int state = 1;
	m_mainWindow->clear();
	sf::Event event;
	while (getWindow().pollEvent(event))
	{
		state = m_inputManager.resolveMenuEvent(m_mainWindow, m_menuStack.top(), event);
	}
	return state;
}
GameObject* WindowManager::genObj(std::string name)
{
	m_objects.push_back({ name, m_spriteManager->getAnims(name) });
	return &m_objects[m_objects.size() - 1];
}
Menu* WindowManager::genMenu(std::string t_name)
{
	std::stringstream stream;
	std::string menuName, menuData, buttonName;
	std::vector<std::string> buttonData;
	std::vector<MenuButton> buttons;
	std::pair <std::string, std::vector < std::string>> data;
	data = m_spriteManager->getMenuData(t_name);
	menuData = data.first;
	buttonData = data.second;
	vec2ui menuSize;
	vec2ui position;
	int numButtons;
	bool active;
	stream << menuData;
	stream >> menuName >> menuSize.x >> menuSize.y >> numButtons;
	std::cout << "\t\t" << menuData << std::endl;
	for (int i = 0; i < numButtons; i++)
	{
		stream.clear();
		stream << buttonData[i];
		stream >> buttonName >> position.x >> position.y;
		buttons.push_back(genButton(buttonName));
		buttons[buttons.size() - 1];
		buttons[buttons.size() - 1].setPosition({
			(menuSize.x * (position.x / 100.f)) - (buttons[buttons.size() - 1 ].m_region.width / 2),
			(menuSize.y * (position.y / 100.f)) - (buttons[buttons.size() - 1].m_region.height / 2) });
		std::cout << "\t\t\t" << buttonData[i] << std::endl;
	}
	m_menuStack.push({ menuName, menuSize, buttons, m_spriteManager->getAnims(t_name) });
	return &m_menuStack.top();
}
MenuButton WindowManager::genButton(std::string t_name)
{
	std::string buttonData, name;
	std::stringstream stream;
	sf::IntRect region;
	bool active;
	buttonData = m_spriteManager->getButtonData(t_name);
	stream << buttonData;
	stream >> name >> region.width >> region.height >> active;
	MenuButton btn(name, region, active);
	return btn;
}
void WindowManager::setPlayer(GameObject* t_player)
{
	m_player = t_player;
}
void WindowManager::pushMenu(std::string t_name)
{
	std::vector<std::vector<Animation>> btnanims;
	genMenu("mainmenu");
	for (int i = 0; i < m_menuStack.top().m_buttons.size(); i++)
	{
		std::string bname = m_menuStack.top().m_buttons[i].m_name;
		std::vector<Animation> anims = m_spriteManager->getAnims(bname);
		btnanims.push_back(anims);
	}
	m_menuStack.top().init(btnanims);
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

