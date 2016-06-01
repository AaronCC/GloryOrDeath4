#pragma once
#include <SFML\Graphics.hpp>
#include "vec2.h"
class Animation {

public:
	Animation() {}
	Animation(std::string t_name, sf::Sprite * t_spriteSheet, sf::IntRect t_sourceRect
		, float t_mpf, vec2uint t_frames, int t_bounds)
		: name(t_name), spriteSheet(t_spriteSheet), sourceRect(t_sourceRect), mpf(t_mpf), frames(t_frames), currentFrame(0, t_bounds), bounds(t_bounds) {}

	~Animation() {}
	std::string name;
	sf::Sprite *spriteSheet;
	float mpf;
	int bounds;
	vec2uint frames;
	vec2uint currentFrame;

	sf::IntRect nextSource()
	{
		if (currentFrame.x >= frames.x)
		{
			currentFrame.x = 0;

			if (currentFrame.y >= bounds + frames.y)
				currentFrame.y = bounds;
			else
				currentFrame.y++;
		}
		else
			currentFrame.x++;
		
		sourceRect.left = currentFrame.x * sourceRect.width;
		sourceRect.top = currentFrame.y * sourceRect.height;

		return sourceRect;
	}

private:
	sf::IntRect sourceRect;
};