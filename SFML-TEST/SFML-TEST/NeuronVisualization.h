#pragma once
#include "Window.h"
#include "NVNeurons.h"
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
	sf::Time m_elapsed;
	sf::Clock m_clock;

	NVNeurons neurons;
};

