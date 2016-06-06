#include "SpriteManager.h"



SpriteManager::SpriteManager()
{
}


SpriteManager::~SpriteManager()
{
}

MenuButton SpriteManager::getButton(std::string t_name)
{
	if (m_buttons.count(t_name))
		return m_buttons[t_name];
	return MenuButton();
}

Menu SpriteManager::getMenu(std::string t_name)
{
	if (m_menus.count(t_name))
		return m_menus[t_name];
	return Menu();
}

std::pair < std::string, std::vector<std::string>> SpriteManager::getMenuData(std::string t_name)
{
	if (m_menuData.count(t_name))
		return m_menuData[t_name];
}

std::string SpriteManager::getButtonData(std::string t_name)
{
	if (m_buttonData.count(t_name))
		return m_buttonData[t_name];
}

bool SpriteManager::init(std::map<std::string, std::string> t_buttons,
	std::map<std::string, std::vector<Animation>> t_anims,
	std::map<std::string, std::pair<std::string, std::vector<std::string>>> t_menus)
{
	m_animations = t_anims;
	m_buttonData = t_buttons;
	m_menuData = t_menus;
	return true;
}


sf::Sprite* SpriteManager::getSprite(std::string t_name)
{
	if (m_sprites.count(t_name))
		return &m_sprites[t_name];
}
std::vector<Animation> SpriteManager::getAnims(std::string t_name)
{
	if (m_animations.count(t_name))
		return m_animations[t_name];
}
bool SpriteManager::loadSprite(std::string t_name)
{
	m_textures.insert(std::pair<std::string, sf::Texture>(t_name, sf::Texture()));
	if (!m_textures[t_name].loadFromFile(t_name))
		return false;
	m_textures[t_name].setSmooth(false);
	m_textures[t_name].setRepeated(false);
	sf::Sprite sprite;
	sprite.setTexture(m_textures[t_name]);
	m_sprites.insert(std::pair<std::string, sf::Sprite>(t_name, sprite));

	if (m_sprites.count(t_name))
		return true;
	return false;
}

bool SpriteManager::unloadSprite(std::string t_name)
{
	return false;
}

