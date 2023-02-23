#include "Snake.h"

Snake::Snake(int l_blockSize) {
	m_size = l_blockSize;
	m_bodyRect.setSize(sf::Vector2f(m_size - 1, m_size - 1));
	Reset();
}
Snake::~Snake() {}

void Snake::Reset() {

}