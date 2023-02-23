#pragma once
#include "Window.h"

class Game {
public:
	Game();
	~Game();
	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
	sf::Time GetElapsed();
	sf::Vector2f m_increment;
	sf::RectangleShape m_gameObject;
	sf::Clock m_clock;
	sf::Time m_elapsed;
	void RestartClock();
private:
	void Move(); // MoveRectangle
	Window m_window;
};
