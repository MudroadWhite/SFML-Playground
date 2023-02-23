#include "NVNeuron.h"

NVNeuron::NVNeuron(float seglen, float nsize, std::vector<float> amps):
	m_seglen(seglen), m_nsize(nsize), m_ampsx(amps), m_ampsy(amps) { }

NVNeuron::NVNeuron(float seglen, float nsize, std::vector<float> ampsx, std::vector<float> ampsy):
	m_seglen(seglen), m_nsize(nsize), m_ampsx(ampsx), m_ampsy(ampsy) { }

NVNeuron::~NVNeuron() { }

void NVNeuron::Step()
{
	// Breathe
	if (m_breatheInterval != 0) {
		float time = GetElapsedTime().asSeconds();
		float size = m_breatheAmp * (sin(time / m_breatheInterval) + 2);
		// ERROR: resize should start at 0, 0
		// TODO: Try to implement the actual resize algorithm
		m_neuroncurve.resize(size);
		m_neuroncircle.resize(size);
	}
}

sf::Time NVNeuron::GetElapsedTime() { return m_clock->getElapsedTime(); }

void NVNeuron::SetWindow(Window* l_window) { m_window = l_window; }
Window* NVNeuron::GetWindow() { return m_window; }

void NVNeuron::SetOrigin(sf::Vector2f l_origin) { m_origin = l_origin; }
sf::Vector2f NVNeuron::GetOrigin() { return m_origin; }

void NVNeuron::SetClock(sf::Clock* l_clock) { m_clock = l_clock; }

void NVNeuron::SetBreatheAmp(float l_breatheAmp){ m_breatheAmp = l_breatheAmp; }
void NVNeuron::SetBreatheInterval(float l_breatheInterval) { m_breatheInterval = l_breatheInterval; }

void NVNeuron::Resize()
{
}

void NVNeuron::SetNeuronCircle()
{
	int size = (int)(6.28 / m_seglen);
	m_neuroncircle = sf::VertexArray(sf::PrimitiveType::LinesStrip, size);
	for (int x = 0; x < size; x++)
	{
		double seg = x * m_seglen;
		m_neuroncircle[x].position.x = m_nsize * cos(seg) + m_origin.x;
		m_neuroncircle[x].position.y = m_nsize * sin(seg) + m_origin.y;
	}
	// close the curve
	m_neuroncircle[size - 1].position.x = m_neuroncircle[0].position.x;
	m_neuroncircle[size - 1].position.y = m_neuroncircle[0].position.y;
}

void NVNeuron::DrawNeuronCircle() { m_window->Draw(m_neuroncircle); }


// TODO: Draw curve according to size
// Maybe in the resize function?
void NVNeuron::SetNeuronCurve()
{
	int size = (int)(6.28 / m_seglen);
	m_neuroncurve = sf::VertexArray(sf::PrimitiveType::LinesStrip, size);
	int nterm = m_ampsx.size(); // TODO: make the max size and fill the small ones with 0s
	for (int i = 0; i < size; i++) {
		float x = 0.0f;
		float y = 0.0f;
		float seg = (float)i * m_seglen;
		for (int j = 0; j < nterm; j++) {
			float phase = pow(2.0, (float)j);
			x += m_ampsx[j] * cos(phase * seg);
			y += m_ampsy[j] * sin(phase * seg);
		}
		m_neuroncurve[i].position.x = x + m_origin.x;
		m_neuroncurve[i].position.y = y + m_origin.y;
	}
	//Close the curve
	m_neuroncurve[size - 1].position.x = m_neuroncurve[0].position.x;
	m_neuroncurve[size - 1].position.y = m_neuroncurve[0].position.y;
}

void NVNeuron::DrawNeuronCurve() { m_window->Draw(m_neuroncurve); }

