#include "IrregularCircle.h"

//parameters:
// seglen(segment length), number of term, 
// 


//TODO:
// 1. Draw the regular irregular line
// 2. Draw Fourier series generated irregular circle

//NOTE:
// Fourier transform in its exponential form:
// S(N, x) = Sum(-N, N, c[n] * e^i^((2 * pi * n * x) / P))
// a * sin(theta) / pi + a * sin(2 * theta) / (2 * pi) + a * sin(3 * theta) / (3 * pi)...
IrregularCircle::IrregularCircle() :
	m_window("Irregular Circle", sf::Vector2u(800, 600))
{ }

IrregularCircle::~IrregularCircle(){ }

void IrregularCircle::Run() {
	SetSingleCurve();
	DrawSingleCurve();
	while (!GetWindow()->IsDone()) {
		Update();
		Render();
	}
}

void IrregularCircle::Render() {
}

void IrregularCircle::Update() {

}

void IrregularCircle::RestartClock() { m_elapsed = m_clock.restart(); }
sf::Time IrregularCircle::GetElapsedTime() { return m_clock.getElapsedTime(); }
Window* IrregularCircle::GetWindow() { return &m_window; }

void IrregularCircle::SetSeglen(float l_seglen) { m_seglen = l_seglen; }

void DrawFourierCircle() {

}

void IrregularCircle::SetSingleCurve() {
	m_curve = sf::VertexArray(sf::PrimitiveType::LinesStrip , 100);
	for (int x = 0; x < 100; x++)
	{
		m_curve.append(sf::Vertex(sf::Vector2f(10 * x, 10 * -sin(x) + 400)));
	}
}

void IrregularCircle::DrawSingleCurve(){
	m_window.BeginDraw();
	m_window.Draw(m_curve);
	m_window.EndDraw();
}
