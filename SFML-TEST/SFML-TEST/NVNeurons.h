#pragma once
#include "NVNeuron.h"


class NVNeurons
{
public:
	NVNeurons();
	~NVNeurons();
	void Render();
	void Step();
	void SetClock(sf::Clock* l_clock);
	void SetWindow(Window* l_window);
	void SetBreatheAmp(float l_breatheAmp);
	void SetBreatheInterval(float l_breatheInterval);
	void SetWeight(int dx, int dy, std::vector<float> w);
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

	// TODO: Draw connections between the neurons
};

