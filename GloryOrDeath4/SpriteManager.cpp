#include "SpriteManager.h"



SpriteManager::SpriteManager()
{
}


SpriteManager::~SpriteManager()
{
}

bool SpriteManager::init(std::map<std::string, std::vector<Animation>> t_anims)
{
	m_animations = t_anims;
	/*for (std::map < std::string, std::vector<Animation>>::iterator it = t_anims.begin(); it != t_anims.end(); ++it)
	{
		m_animations.insert(std::pair<std::string,std::vector<Animation>>(it-first, it->second));
	}*/
	return true;
}	

sf::Sprite* SpriteManager::getSprite(std::string t_name)
{
	return &m_sprites[t_name];
}
std::vector<Animation>* SpriteManager::getAnims(std::string t_name)
{
	return &m_animations[t_name];
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
