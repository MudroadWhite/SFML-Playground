#include "RotateRectangle.h"
#include <cmath>

RotateRectangle::RotateRectangle() :
	m_window("Rotate Rectangle", sf::Vector2u(800, 800)),
	m_rectangle(sf::Vector2f(50.f, 50.f)){
	RestartClock();
	m_rectangle.setFillColor(sf::Color::White);
	m_rectangle.setOrigin(sf::Vector2f(5.f, 5.f));
	m_rectangle.setPosition(sf::Vector2f(400.f, 400.f));

	SetRotateSpeed(200.0f);
	SetAngleSpeed(2.0f);
	SetRadius(240.0f);
}

RotateRectangle::~RotateRectangle(){}

void RotateRectangle::Update() {
	m_window.Update();
	// Move();
	srand(time(NULL));
}

void RotateRectangle::Render() {
	m_window.BeginDraw();

	// things that should show on the window?
	m_window.Draw(m_rectangle);
	
	m_window.EndDraw();
}

void RotateRectangle::ChangeRectLocation() {
	// game logic here... spinning around the center at a given radius
	float fElapsed = GetElapsedTime().asSeconds();
	sf::Vector2u windowSize = GetWindow()->GetWindowSize();
	m_rectangle.setRotation(fElapsed * GetRotateSpeed());
	float x = std::cos(fElapsed * GetAngleSpeed()) * GetRadius() + (float)windowSize.x / 2.f;
	float y = std::sin(fElapsed * GetAngleSpeed()) * GetRadius() + (float)windowSize.y / 2.f;
	m_rectangle.setPosition(sf::Vector2f(x, y));
}

void RotateRectangle::RestartClock() { m_elapsed = m_clock.restart(); }
sf::Time RotateRectangle::GetElapsedTime() { return m_clock.getElapsedTime(); }

Window* RotateRectangle::GetWindow() { return &m_window; }

float RotateRectangle::GetAngleSpeed() { return m_angleSpeed; }
void RotateRectangle::SetAngleSpeed(float l_angleSpeed) { m_angleSpeed = l_angleSpeed;  }
float RotateRectangle::GetRotateSpeed() { return m_rotateSpeed; }
void RotateRectangle::SetRotateSpeed(float l_rotateSpeed) { m_rotateSpeed = l_rotateSpeed; }
float RotateRectangle::GetRadius() { return m_radius; }
void RotateRectangle::SetRadius(float l_radius) { m_radius = l_radius; }