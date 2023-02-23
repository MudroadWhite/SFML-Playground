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
	//RunSingleCurve();
	//RunSingleCircle();
	RunSimpleFourierCircle();
	//while (!GetWindow()->IsDone()) {
	//	Update();
	//	Render();
	//}
}

void IrregularCircle::Render() {
}

void IrregularCircle::Update() {
	m_window.Update();
	srand(time(NULL));
}

void IrregularCircle::RestartClock() { m_elapsed = m_clock.restart(); }
sf::Time IrregularCircle::GetElapsedTime() { return m_clock.getElapsedTime(); }
Window* IrregularCircle::GetWindow() { return &m_window; }

void IrregularCircle::SetSeglen(float l_seglen) { m_seglen = l_seglen; }

void IrregularCircle::SetSingleCurve() {
	m_curve = sf::VertexArray(sf::PrimitiveType::LinesStrip , 100);
	for (int x = 0; x < 100; x++)
	{
		m_curve[x].position = sf::Vector2f(10 * x + 50, 10 * -sin(x) + 400);
	}
}

void IrregularCircle::RunSingleCurve(){
	SetSingleCurve();
	DrawSingleCurve();
	while (!GetWindow()->IsDone()) {
		Update();
		Render();
	}
}

void IrregularCircle::DrawSingleCurve(){
	m_window.BeginDraw();
	m_window.Draw(m_curve);
	m_window.EndDraw();
}

void IrregularCircle::RunSingleCircle(){
	SetSingleCircle();
	DrawSigleCircle();
	while (!GetWindow()->IsDone()) {
		Update();
		Render();
	}
}

void IrregularCircle::SetSingleCircle()
{
	m_curve = sf::VertexArray(sf::PrimitiveType::LinesStrip, (int)(6.28/0.02));
	for (int x = 0; x < (int)(6.28 / 0.02); x++)
	{
		double xx = x * 0.02;
		m_curve[x].position.x = 100 * cos(xx) + 400;
		m_curve[x].position.y = 100 * sin(xx) + 400;
	}
}

void IrregularCircle::RunSimpleFourierCircle() {
	SetSimpleFourierCircle();
	DrawSimpleFourierCircle();
	while (!GetWindow()->IsDone()) {
		Update();
		Render();
	}
}


void IrregularCircle::SetSimpleFourierCircle() {
	m_curve = sf::VertexArray(sf::PrimitiveType::LinesStrip, (int)(6.28 / 0.02));
	for (int x = 0; x < (int)(6.29 / 0.02); x++)
	{
		double xx = x * 0.02;
		m_curve[x].position.x = 400 + 100 * cos(xx) + 50 * cos(2 * xx) + 70 * cos(4 * xx) + 20 * cos(8 * xx);
		m_curve[x].position.y = 400 + 100 * sin(xx) + 30 * sin(4 * xx) + 15 * sin(16 * xx);
	}
	// close the curve
	m_curve[(6.29 / 0.02)-1].position.x = m_curve[0].position.x;
	m_curve[(6.29 / 0.02)-1].position.y = m_curve[0].position.y;
}
void IrregularCircle::DrawSimpleFourierCircle() {
	m_window.BeginDraw();
	m_window.Draw(m_curve);
	m_window.EndDraw();
}


void IrregularCircle::RunFourierCircle()
{
}

void IrregularCircle::SetFourierCircle()
{
}

void IrregularCircle::DrawSigleCircle(){
	m_window.BeginDraw();
	m_window.Draw(m_curve);
	m_window.EndDraw();
}

void IrregularCircle::DrawFourierCircle()
{
}
