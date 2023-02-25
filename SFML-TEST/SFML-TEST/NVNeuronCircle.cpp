#include "NVNeuronCircle.h"

NVNeuronCircle::NVNeuronCircle(std::vector<float> w) : 
	NVNeuron(w) { }

NVNeuronCircle::NVNeuronCircle(std::vector<float> wx, std::vector<float> wy) :
	NVNeuron(wx, wy) { }

NVNeuronCircle::NVNeuronCircle(float l_seglen, float l_size, std::vector<float> w, float l_breatheInterval, float l_breatheAmp, sf::Vector2f l_origin) :
	NVNeuron(l_seglen, l_size, w, l_breatheInterval, l_breatheAmp, l_origin) {}

NVNeuronCircle::~NVNeuronCircle() { }

void NVNeuronCircle::Step()
{
	NVNeuron::Step();
	int size = (int)(6.28 / m_seglen);
	float shapeSize = m_breatheSize + m_size;
	m_neuron = sf::VertexArray(sf::PrimitiveType::LinesStrip, size);
	for (int x = 0; x < size; x++)
	{
		double seg = x * m_seglen;
		m_neuron[x].position.x = shapeSize * cos(seg) + m_origin.x;
		m_neuron[x].position.y = shapeSize * sin(seg) + m_origin.y;
	}
	// close the curve
	m_neuron[size - 1].position.x = m_neuron[0].position.x;
	m_neuron[size - 1].position.y = m_neuron[0].position.y;
}