#include "NVNeuronCurve.h"

NVNeuronCurve::NVNeuronCurve(std::vector<float> w) :
	NVNeuron(w) { }

NVNeuronCurve::NVNeuronCurve(std::vector<float> wx, std::vector<float> wy) :
	NVNeuron(wx, wy) { }

NVNeuronCurve::NVNeuronCurve(float l_seglen, float l_size, std::vector<float> w, float l_breatheInterval, float l_breatheAmp, sf::Vector2f l_origin) :
	NVNeuron(l_seglen, l_size, w, l_breatheInterval, l_breatheAmp, l_origin) { }

NVNeuronCurve::~NVNeuronCurve() { }

// Assume that the weight vector is always normalized...
void NVNeuronCurve::Step()
{
	NVNeuron::Step();
	int size = (int)(6.28 / m_seglen);
	float shapeSize = m_breatheSize + m_size;
	m_neuron = sf::VertexArray(sf::PrimitiveType::LinesStrip, size);
	int nterm = m_wx.size(); // TODO: make the max size and fill the small ones with 0s
	for (int i = 0; i < size; i++) {
		float x = 0.0f;
		float y = 0.0f;
		float seg = (float)i * m_seglen;
		for (int j = 0; j < nterm; j++) {
			float phase = pow(2.0, (float)j);
			x += m_wx[j] * cos(phase * seg);
			y += m_wy[j] * sin(phase * seg);
		}
		m_neuron[i].position.x = shapeSize * x + m_origin.x;
		m_neuron[i].position.y = shapeSize * y + m_origin.y;
	}
	//Close the curve
	m_neuron[size - 1].position.x = m_neuron[0].position.x;
	m_neuron[size - 1].position.y = m_neuron[0].position.y;
}
