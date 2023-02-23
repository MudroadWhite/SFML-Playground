#pragma once
#include "Window.h"

class NVNeuron
{
public:
	NVNeuron(float seglen, float nsize, std::vector<float> amps);
	NVNeuron(float seglen, float nsize, std::vector<float> ampsx, std::vector<float> ampsy);
	~NVNeuron();
	void Step();
	sf::Time GetElapsedTime();
	void SetWindow(Window* l_window);
	Window* GetWindow();
	void SetOrigin(sf::Vector2f l_origin);
	sf::Vector2f GetOrigin();
	void SetClock(sf::Clock* l_clock);
	void SetBreatheAmp(float l_breatheAmp);
	void SetBreatheInterval(float l_breatheInterval);

	void Resize();
	void SetNeuronCurve();
	void DrawNeuronCurve();
	void SetNeuronCircle();
	void DrawNeuronCircle();
	
private:
	Window* m_window;
	sf::Time* m_elapsed;
	sf::Clock* m_clock;

	float m_seglen;
	float m_nsize; // neuron size. The curve will be amplified by the size of the neuron
	float m_breatheAmp;
	float m_breatheInterval;
	std::vector<float> m_ampsx;
	std::vector<float> m_ampsy;
	sf::Vector2f m_origin;

	sf::VertexArray m_neuroncurve;
	sf::VertexArray m_neuroncircle;
};

