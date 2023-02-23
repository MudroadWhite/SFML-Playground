#include "IrregularCircle.h"

//parameters:
// seglen(segment length), series number, 
// 
IrregularCircle::IrregularCircle(){ }

IrregularCircle::~IrregularCircle(){ }

void DrawSingleCircle() {
	sf::VertexArray curve(sf::PrimitiveType::LineStrip, 100);
	for (int x = -50; x < 50; x++)
	{
		curve.append(sf::Vertex(sf::Vector2f(x, -sin(x))));
	}
}

void IrregularCircle::Run() {
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