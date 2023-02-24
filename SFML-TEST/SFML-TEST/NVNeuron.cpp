#include "NVNeuron.h"

// TODO: separate neuron curve and neuron circle and make them into decoupled drawables

NVNeuron::NVNeuron(float seglen, float nsize, std::vector<float> w):
	m_seglen(seglen), m_nsize(nsize), m_wx(w), m_wy(w) { }

NVNeuron::NVNeuron(float seglen, float nsize, std::vector<float> wx, std::vector<float> wy):
	m_seglen(seglen), m_nsize(nsize), m_wx(wx), m_wy(wy) { }

NVNeuron::~NVNeuron() { }

void NVNeuron::Step()
{
	// Update weights of the curves
	// ...

	// Breathe
	if (m_breatheInterval != 0) {
		float time = GetElapsedTime().asSeconds();
		m_breatheSize = m_breatheAmp * sin(time / m_breatheInterval);
	}

	// Finally determine the shape
	SetNeuronCircle();
	SetNeuronCurve();
}

sf::Time NVNeuron::GetElapsedTime() { return m_clock->getElapsedTime(); }

void NVNeuron::SetWindow(Window* l_window) { m_window = l_window; }
Window* NVNeuron::GetWindow() { return m_window; }

void NVNeuron::SetOrigin(sf::Vector2f l_origin) { m_origin = l_origin; }
sf::Vector2f NVNeuron::GetOrigin() { return m_origin; }

void NVNeuron::SetClock(sf::Clock* l_clock) { m_clock = l_clock; }

void NVNeuron::SetBreatheAmp(float l_breatheAmp){ m_breatheAmp = l_breatheAmp; }
void NVNeuron::SetBreatheInterval(float l_breatheInterval) { m_breatheInterval = l_breatheInterval; }

void NVNeuron::SetWeights(std::vector<float> l_w) { m_wx = l_w; m_wy = l_w; }
void NVNeuron::SetWeights(std::vector<float> l_wx, std::vector<float> l_wy) { m_wx = l_wx; m_wy = l_wy; }

void NVNeuron::SetNeuronCircleSize(float l_circlesize) { m_circleSize = l_circlesize; }
void NVNeuron::SetNeuronCurveSize(float l_curvesize) { m_curveSize = l_curvesize; }

void NVNeuron::SetNeuronCircle()
{
	int size = (int)(6.28 / m_seglen);
	float shapeSize = m_circleSize + m_breatheSize;
	m_neuroncircle = sf::VertexArray(sf::PrimitiveType::LinesStrip, size);
	for (int x = 0; x < size; x++)
	{
		double seg = x * m_seglen;
		m_neuroncircle[x].position.x = shapeSize * cos(seg) + m_origin.x;
		m_neuroncircle[x].position.y = shapeSize * sin(seg) + m_origin.y;
	}
	// close the curve
	m_neuroncircle[size - 1].position.x = m_neuroncircle[0].position.x;
	m_neuroncircle[size - 1].position.y = m_neuroncircle[0].position.y;
}

void NVNeuron::DrawNeuronCircle() { m_window->Draw(m_neuroncircle); }

// Assume that the weight vector is always normalized...
void NVNeuron::SetNeuronCurve()
{
	int size = (int)(6.28 / m_seglen);
	float shapeSize = m_breatheSize + m_curveSize;
	m_neuroncurve = sf::VertexArray(sf::PrimitiveType::LinesStrip, size);
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
		m_neuroncurve[i].position.x = shapeSize * x + m_origin.x;
		m_neuroncurve[i].position.y = shapeSize * y + m_origin.y;
	}
	//Close the curve
	m_neuroncurve[size - 1].position.x = m_neuroncurve[0].position.x;
	m_neuroncurve[size - 1].position.y = m_neuroncurve[0].position.y;
}

void NVNeuron::DrawNeuronCurve() { m_window->Draw(m_neuroncurve); }

