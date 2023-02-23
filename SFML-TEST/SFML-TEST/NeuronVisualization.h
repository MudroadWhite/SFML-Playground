#pragma once
#include "Window.h"
class NeuronVisualization
{
public:
	NeuronVisualization();
	~NeuronVisualization();
	void Render();
	void Update();
	void RestartClock();
	void Step();
	void Run();
	sf::Time GetElapsedTime();
	Window* GetWindow();

private:
	Window m_window;
	sf::Vector2f m_dimensionSize;
	sf::Time m_elapsed;
	sf::Clock m_clock;
};

