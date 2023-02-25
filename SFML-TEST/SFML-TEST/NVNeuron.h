#pragma once
#include "Window.h"

class NVNeuron
{
public:
	NVNeuron(std::vector<float> w);
	NVNeuron(std::vector<float> wx, std::vector<float> wy);
	NVNeuron(float l_seglen, float l_size, std::vector<float> w, float l_breatheInterval, float l_breatheAmp, sf::Vector2f l_origin);
	~NVNeuron();

	void Step();
	void Render();
	void SetWindow(Window* l_window);
	Window* GetWindow();
	void SetOrigin(sf::Vector2f l_origin);
	sf::Vector2f GetOrigin();
	void SetClock(sf::Clock* l_clock);
	sf::Time GetElapsedTime();
	void SetBreatheAmp(float l_breatheAmp);
	void SetBreatheInterval(float l_breatheInterval);
	void SetWeights(std::vector<float> l_w);
	void SetWeights(std::vector<float> l_wx, std::vector<float> l_wy);
	void SetSize(float l_size);
	void SetSegmentLength(float l_seglen);
	
protected:
	Window* m_window;
	sf::Time* m_elapsed;
	sf::Clock* m_clock;

	float m_seglen;
	float m_size;
	float m_breatheAmp = 0.f;
	float m_breatheInterval = 0.f;
	float m_breatheSize = 0;

	std::vector<float> m_wx; // weights
	std::vector<float> m_wy;
	sf::Vector2f m_origin = sf::Vector2f(0.f, 0.f);

	sf::VertexArray m_neuron;
};

