#include <SFML/Graphics.hpp>
#include "Application.h"

int main()
{
	Application application;
	if (application.init())
		application.mainLoop();
	return 0;
}