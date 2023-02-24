#pragma once
#include "NVNeuron.h"

// IMPORTANT TODO: change neurons weights to 3D vector

class NVNeurons
{
public:
	NVNeurons(Window* window, sf::Clock* clock, std::vector<std::vector<float>> weights, sf::Vector2f origin);
	~NVNeurons();
	void Render();
	void Step();
	void Update(); // receive events for window?
	void SetupNeurons();
	void SetNeuronsClock(sf::Clock* l_clock);
	void SetNeuronsWindow(Window* l_window);
	void SetBreatheAmp(float l_breatheAmp);
	void SetBreatheInterval(float l_breatheInterval);
	void SetWeights(int dx, int dy, std::vector<float> w);
	void SetMargin(float l_m);
	void SetMargin(float l_mx, float l_my);
private:
	int m_dx; // dimension size at x axis
	int m_dy; // dimension size at y axis

	float m_marginx;
	float m_marginy;
	sf::Vector2f m_origin;

	std::vector<std::vector<float>> m_weights;
	std::vector<NVNeuron> m_neurons;

	// TODO: window and clock should be put here?

	sf::Clock* m_clock;
	Window* m_window;

	// TODO: Draw connections between the neurons
};

