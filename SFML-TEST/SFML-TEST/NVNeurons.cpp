#include "NVNeurons.h"
#include "NVNeuronCircle.h"
#include "NVNeuronCurve.h"
//#include "Window.h"
#include <iostream>

// TODO: Properlly set up size so that it finds the max size of all
// NOTE: It will affect places where m_dy being used in the loop
NVNeurons::NVNeurons(Window* window, sf::Clock* clock, std::vector<std::vector<std::vector<float>>> weights, sf::Vector2f origin) :
	m_dx(weights.size()), m_dy(weights[0].size()),
	m_origin(origin), m_window(window), m_clock(clock),
	m_weights(weights){ 
	// TO USE:
	// 1. Manually set up margin
	// 2. invoke SetupNeurons()
	// 3. run() in NV
}

NVNeurons::~NVNeurons() { }

void NVNeurons::Render() {
	for (int i = 0; i < m_neurons.size(); i++) {
		m_neurons[i].circle.Render();
		m_neurons[i].curve.Render();
	}
}

void NVNeurons::Step() {
	for (int i = 0; i < m_neurons.size(); i++) {
		// TODO: update weights... also in NVNeuron

		// Step all neurons
		m_neurons[i].circle.Step();
		m_neurons[i].curve.Step();
	}
}

void NVNeurons::Update()
{
	//m_window.Update(); //???
	srand(time(NULL));
	Step();
}

void NVNeurons::Init()
{
	// TODO: Organize the Neurons well.
	// Make each layer of neurons being well aligned horizontally in the center
	for (int i = 0; i < m_dx; i++) {
		for (int j = 0; j < m_dy; j++) {
			std::vector<float> w = m_weights[i][j];
			// can be also changed into full zeros
			float x = i * m_marginx + m_origin.x;
			float y = ( -(float) m_dy / 2.0f + j) * m_marginy + m_origin.y;
			sf::Vector2f origin(x, y);

			NVNeuronShape shape{ 
				NVNeuronCircle(0.01, 40, w, 0.5, 3, origin),
				NVNeuronCurve(0.01, 40, w, 0.5, 3, origin)
			};

			shape.circle.SetClock(m_clock);
			shape.circle.SetWindow(m_window);
			shape.curve.SetClock(m_clock);
			shape.curve.SetWindow(m_window);
			m_neurons.push_back(shape);
		}
	}
}

void NVNeurons::SetNeuronsClock(sf::Clock* l_clock) {
	for (int i = 0; i < m_neurons.size(); i++) {
		m_neurons[i].circle.SetClock(l_clock);
		m_neurons[i].curve.SetClock(l_clock);
	}
}

void NVNeurons::SetNeuronsWindow(Window* l_window) {
	for (int i = 0; i < m_neurons.size(); i++) {
		m_neurons[i].circle.SetWindow(l_window);
		m_neurons[i].curve.SetWindow(l_window);
	}
}

void NVNeurons::SetBreatheAmp(float l_breatheAmp)
{
	for (int i = 0; i < m_neurons.size(); i++) {
		m_neurons[i].circle.SetBreatheAmp(l_breatheAmp);
		m_neurons[i].curve.SetBreatheAmp(l_breatheAmp);
	}
}

void NVNeurons::SetBreatheInterval(float l_breatheInterval)
{
	for (int i = 0; i < m_neurons.size(); i++) {
		m_neurons[i].circle.SetBreatheInterval(l_breatheInterval);
		m_neurons[i].curve.SetBreatheInterval(l_breatheInterval);
	}
}

void NVNeurons::SetWeights(int dx, int dy, std::vector<float> w) { 
	m_neurons[(dx + 1) * (dy + 1) - 1].circle.SetWeights(w); 
	m_neurons[(dx + 1) * (dy + 1) - 1].curve.SetWeights(w);
}

void NVNeurons::SetMargin(float l_m){ m_marginx = l_m; m_marginy = l_m; }
void NVNeurons::SetMargin(float l_mx, float l_my) { m_marginx = l_mx; m_marginy = l_my; }
