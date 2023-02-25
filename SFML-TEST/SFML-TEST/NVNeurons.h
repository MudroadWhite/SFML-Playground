#pragma once
#include "NVNeuron.h"
#include "NVNeuronCircle.h"
#include "NVNeuronCurve.h"

// IMPORTANT TODO: change neurons weights to 3D vector

struct NVNeuronShape {
	NVNeuronCircle circle;
	NVNeuronCurve curve;
};

class NVNeurons
{
public:
	NVNeurons(Window* window, sf::Clock* clock, std::vector<std::vector<std::vector<float>>> weights, sf::Vector2f origin);
	~NVNeurons();
	void Render();
	void Step();
	//void Update(); // receive events for window?
	void Init();
	void SetBreatheAmp(float l_breatheAmp);
	void SetBreatheInterval(float l_breatheInterval);
	void SetWeights(int dx, int dy, std::vector<float> w);
	void SetMargin(float l_m);
	void SetMargin(float l_mx, float l_my);
private:
	void SetClock(sf::Clock* l_clock);
	void SetWindow(Window* l_window);

	int m_layers;
	float m_marginx;
	float m_marginy;
	sf::Vector2f m_origin;

	std::vector<std::vector<std::vector<float>>> m_weights;
	std::vector<NVNeuronShape> m_neurons;

	sf::Clock* m_clock;
	Window* m_window;

	// TODO: Draw connections between the neurons
};

