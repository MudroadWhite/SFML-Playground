#include "NVNeuron.h"

// NOTE: To use NVNeuron:
// 1. SetClock(); *
// 2. SetWindow(); *
// 3. SetSize();
// 4. SetSegmentLength();
// 4. SetOrigin();
// 5. SetBreatheAmp();
// 6. SetBreatheInterval();
NVNeuron::NVNeuron(std::vector<float> w):
	m_seglen(1.0f), m_size(0), m_wx(w), m_wy(w), m_breatheInterval(0), m_breatheAmp(0), m_origin(sf::Vector2f(0, 0)) { }

NVNeuron::NVNeuron(std::vector<float> wx, std::vector<float> wy):
	m_seglen(1.0f), m_size(0), m_wx(wx), m_wy(wy), m_breatheInterval(0), m_breatheAmp(0), m_origin(sf::Vector2f(0, 0)) { }

NVNeuron::NVNeuron(float l_seglen, float l_size, std::vector<float> w,
	float l_breatheInterval, float l_breatheAmp, sf::Vector2f l_origin) :
	m_seglen(l_seglen), m_size(l_size), m_wx(w), m_wy(w), m_breatheInterval(l_breatheInterval), 
	m_breatheAmp(l_breatheAmp), m_origin(l_origin) { }

NVNeuron::~NVNeuron() { }

void NVNeuron::Step()
{
	// TODO: Update weights of the curves
	
	// Breathe
	if (m_breatheInterval != 0) {
		float time = GetElapsedTime().asSeconds();
		m_breatheSize = m_breatheAmp * sin(time / m_breatheInterval);
	}
}

void NVNeuron::Render() { m_window->Draw(m_neuron); }

void NVNeuron::SetWindow(Window* l_window) { m_window = l_window; }
Window* NVNeuron::GetWindow() { return m_window; }

void NVNeuron::SetOrigin(sf::Vector2f l_origin) { m_origin = l_origin; }
sf::Vector2f NVNeuron::GetOrigin() { return m_origin; }

void NVNeuron::SetClock(sf::Clock* l_clock) { m_clock = l_clock; }
sf::Time NVNeuron::GetElapsedTime() { return m_clock->getElapsedTime(); }

void NVNeuron::SetBreatheAmp(float l_breatheAmp){ m_breatheAmp = l_breatheAmp; }
void NVNeuron::SetBreatheInterval(float l_breatheInterval) { m_breatheInterval = l_breatheInterval; }

void NVNeuron::SetWeights(std::vector<float> l_w) { m_wx = l_w; m_wy = l_w; }
void NVNeuron::SetWeights(std::vector<float> l_wx, std::vector<float> l_wy) { m_wx = l_wx; m_wy = l_wy; }

void NVNeuron::SetSize(float l_size) { m_size = l_size; }

void NVNeuron::SetSegmentLength(float l_seglen) { m_seglen = l_seglen; }
