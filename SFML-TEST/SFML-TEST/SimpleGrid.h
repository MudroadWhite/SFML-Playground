#pragma once
#include "Window.h"
class SimpleGrid
{
public:
	SimpleGrid(int bx, int by, int dx, int dy);
	void Render();
	void Update();
	sf::Vector2u m_blockSize;
	sf::Vector2u m_dimensionSize;
	Window* GetWindow();
	bool IsDone();
private:
	Window m_window;
};

