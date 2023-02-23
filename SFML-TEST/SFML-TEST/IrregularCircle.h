#pragma once
#include"Window.h"

class IrregularCircle
{
public:
	IrregularCircle(float l_seglen, std::vector<float> l_amps);
	IrregularCircle(float l_seglen, std::vector<float> l_ampsx, std::vector<float> l_ampsy);
	~IrregularCircle();
	void Render();
	void Update();
	void RestartClock();
	void Step();
	void Run();
	sf::Time GetElapsedTime();
	Window* GetWindow();

	void RunSingleCurve();
	void SetSingleCurve();
	void DrawSingleCurve();
	void RunSingleCircle();
	void SetSingleCircle();
	void DrawSigleCircle();
	void RunSimpleFourierCircle();
	void SetSimpleFourierCircle();
	void DrawSimpleFourierCircle();
	void RunFourierCircle();
	void SetFourierCircle();
	void DrawFourierCircle();

	//void RunNVNeuron();

private:
	Window m_window;
	sf::Time m_elapsed;
	sf::Clock m_clock;

	std::vector<float> m_ampsx;
	std::vector<float> m_ampsy;
	float m_seglen;

	sf::VertexArray m_curve;
	sf::VertexArray m_circle;
};

