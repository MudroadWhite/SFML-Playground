#include "NVNeurons.h"

NVNeurons::NVNeurons()
{
}

NVNeurons::~NVNeurons()
{
}

void NVNeurons::Render()
{
	// begindraw?
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

void NVNeurons::SetClock(sf::Clock* l_clock) {
	for (int i = 0; i < m_neurons.size(); i++) {
		m_neurons[i].SetClock(l_clock);
	}
}

void NVNeurons::SetWindow(Window* l_window) {
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
