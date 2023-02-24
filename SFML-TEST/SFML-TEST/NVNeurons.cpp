#include "NVNeurons.h"
//#include "Window.h"

NVNeurons::NVNeurons(Window* window, sf::Clock* clock, std::vector<std::vector<float>> weights, sf::Vector2f origin) :
	m_dx(weights.size()), m_dy(weights[0].size()),
	m_origin(origin), m_window(window), m_clock(clock),
	m_weights(weights){ 
	// TO USE:
	// 1. Manually set up margin
	// 2. invoke SetupNeurons()
	// 3. run() in NV
}

NVNeurons::~NVNeurons() { }

void NVNeurons::Render()
{
	for (int i = 0; i < m_neurons.size(); i++) {
		m_neurons[i].DrawNeuronCircle();
		m_neurons[i].DrawNeuronCurve();
	}
}

void NVNeurons::Step()
{
	for (int i = 0; i < m_neurons.size(); i++) {
		// TODO: update weights...

		// Step all neurons
		m_neurons[i].Step();
	}
}

void NVNeurons::Update()
{
	//m_window.Update();
	srand(time(NULL));
	Step();
}

void NVNeurons::SetupNeurons()
{
	for (int i = 0; i < m_dx; i++) {
		for (int j = 0; j < m_dy; j++) {
			std::vector<float> w = m_weights[m_dx * i + j];
			// can be also changed into full zeros
			NVNeuron neuron(0.01, 10, w);
			float x = i * m_marginx + m_origin.x;
			float y = j * m_marginy + m_origin.y;
			neuron.SetOrigin(sf::Vector2f(x, y));
			neuron.SetClock(m_clock);
			neuron.SetWindow(m_window);
			neuron.SetBreatheAmp(3);
			neuron.SetBreatheInterval(0.5);
			neuron.SetNeuronCircleSize(40);
			neuron.SetNeuronCurveSize(40);
		}
	}
}

void NVNeurons::SetNeuronsClock(sf::Clock* l_clock) {
	for (int i = 0; i < m_neurons.size(); i++) {
		m_neurons[i].SetClock(l_clock);
	}
}

void NVNeurons::SetNeuronsWindow(Window* l_window) {
	for (int i = 0; i < m_neurons.size(); i++) {
		m_neurons[i].SetWindow(l_window);
	}
}

void NVNeurons::SetBreatheAmp(float l_breatheAmp)
{
	for (int i = 0; i < m_neurons.size(); i++) {
		m_neurons[i].SetBreatheAmp(l_breatheAmp);
	}
}

void NVNeurons::SetBreatheInterval(float l_breatheInterval)
{
	for (int i = 0; i < m_neurons.size(); i++) {
		m_neurons[i].SetBreatheInterval(l_breatheInterval);
	}
}

void NVNeurons::SetWeights(int dx, int dy, std::vector<float> w) { m_neurons[(dx + 1) * (dy + 1) - 1].SetWeights(w); }

void NVNeurons::SetMargin(float l_m){ m_marginx = l_m; m_marginy = l_m; }
void NVNeurons::SetMargin(float l_mx, float l_my) { m_marginx = l_mx; m_marginy = l_my; }
