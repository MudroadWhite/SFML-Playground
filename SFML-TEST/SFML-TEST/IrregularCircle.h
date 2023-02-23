#pragma once
#include"Window.h"

class IrregularCircle
{
public:
	IrregularCircle();
	~IrregularCircle();
	void Render();
	void Update();
	void RestartClock();
	void Step();
	void Run();
	sf::Time GetElapsedTime();
	Window* GetWindow();

	void SetSeglen(float l_seglen);
	void SetNterm(float l_nterm);

	void RunSingleCurve();
	void RunSingleCircle();
	void RunFourierCircle();
	void RunSimpleFourierCircle();

	void SetSingleCurve();
	void DrawSingleCurve();
	void SetSingleCircle();
	void DrawSigleCircle();
	void SetSimpleFourierCircle();
	void DrawSimpleFourierCircle();
	void SetFourierCircle();
	void DrawFourierCircle();

private:
	Window m_window;
	sf::Vector2f m_dimensionSize;
	sf::Time m_elapsed;
	sf::Clock m_clock;

	sf::VertexArray m_curve;

	float m_seglen;
	float m_nterm;
};

