#include "Game.h"
#include <iostream>

Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 600)) {
	RestartClock();

	sf::Vector2f size = sf::Vector2f(128.0f, 128.0f);
	m_gameObject.setSize(size);
	//m_gameObject.setOrigin(size.x / 2, size.y / 2);
	m_increment = sf::Vector2f(0.4f, 0.4f);
}

Game::~Game() {}

void Game::HandleInput() {

}

void Game::Update() {
	m_window.Update();
	Move();
	srand(time(NULL));
}

void Game::Render() {
	m_window.BeginDraw();
	m_window.Draw(m_gameObject); // Extend to a list of objects to be drawn in window
	m_window.EndDraw(); 
}
Window* Game::GetWindow() {
	return &m_window;
}

sf::Time Game::GetElapsed() { return m_elapsed; }

sf::Vector2u FromSFVector2f(sf::Vector2f v) {
	return sf::Vector2u(static_cast<unsigned int>(v.x),
		static_cast<unsigned int>(v.y));
}

void Game::Move() {
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_objSize = FromSFVector2f(m_gameObject.getSize());

	if ((m_gameObject.getPosition().x >
		l_windSize.x - l_objSize.x && m_increment.x > 0) ||
		(m_gameObject.getPosition().x < 0 && m_increment.x < 0)) {
		m_increment.x = -m_increment.x;
	}
	if ((m_gameObject.getPosition().y >
		l_windSize.y - l_objSize.y && m_increment.y > 0) ||
		(m_gameObject.getPosition().y < 0 && m_increment.y < 0)) {
		m_increment.y = -m_increment.y;
	}

	float fElapsed = m_elapsed.asSeconds();
	std::cout << fElapsed << std::endl;

	m_gameObject.setPosition(
		m_gameObject.getPosition().x + m_increment.x * fElapsed,
		m_gameObject.getPosition().y + m_increment.y * fElapsed
	);
}

void Game::RestartClock() {
	m_elapsed = m_clock.restart();
}