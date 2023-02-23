#include "SimpleGrid.h"
// DONE!!

SimpleGrid::SimpleGrid(int bx, int by, int dx, int dy) : 
	m_blockSize(sf::Vector2u(bx, by)),
	m_dimensionSize(sf::Vector2u(dx, dy)),
	m_window("SimpleGrid", sf::Vector2u(bx * dx, by * dy)) {
	//RestartClock();
	sf::Vector2f size = sf::Vector2f(128.0f, 128.0f);
}

void SimpleGrid::Update() {
	m_window.Update();
	//srand(time(NULL));
}

void SimpleGrid::Render() {
	sf::Vector2f blockSize_f = sf::Vector2f(
		(float)(m_blockSize.x-1), (float)(m_blockSize.y-1)
	);

	m_window.BeginDraw();
	for (int i = 0; i < m_dimensionSize.x; i++) {
		for (int j = 0; j < m_dimensionSize.y; j++) {
			// Creaete an rectangle
			sf::RectangleShape r;
			// Set its position and color and size
			r.setSize(blockSize_f);
			r.setFillColor(sf::Color::Green);
			sf::Vector2f pos((i * (blockSize_f.x+1)), (j * (blockSize_f.y+1)));
			r.setPosition(pos);
			// Draw it
			m_window.Draw(r);
		}
	}
	m_window.EndDraw();
}

Window* SimpleGrid::GetWindow() {
	return &m_window;
}