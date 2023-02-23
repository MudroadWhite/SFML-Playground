#include "RotateGrid.h"

RotateGrid::RotateGrid(int dx, int dy, float gridSize, float rotateSpeed, float rotateOffset) : m_dimensionSize(sf::Vector2f(dx, dy)),
	m_window("Rotate Grid", 
		sf::Vector2u((unsigned int)(gridSize * dx), 
			(unsigned int)(gridSize * dy))),
	m_gridSize(gridSize), 
	m_RotateSpeed(rotateSpeed),
	m_RotateOffset(rotateOffset)
{ 
	RestartClock();
	InitGrid(m_dimensionSize, gridSize);
}

RotateGrid::~RotateGrid(){}

void RotateGrid::Run() {
	while (!GetWindow()->IsDone()) {
		Update();
		Render();
	}
}

void RotateGrid::RestartClock() { m_elapsed = m_clock.restart(); }
sf::Time RotateGrid::GetElapsedTime() { return m_clock.getElapsedTime(); }
Window* RotateGrid::GetWindow() { return &m_window; }

void RotateGrid::Update() {
	m_window.Update();
	srand(time(NULL));
	Step();
}

void RotateGrid::Step() {
	float fElapsed = GetElapsedTime().asSeconds();
	for (int i = 0; i < (int)m_dimensionSize.x; i++) {
		for (int j = 0; j < (int)m_dimensionSize.y; j++) {
			m_grid[i][j].setRotation(fElapsed * m_RotateSpeed + (i + j) * m_RotateOffset);
		}
	}
}

void RotateGrid::Render() {
	m_window.BeginDraw();

	// things that should show on the window?
	for (int i = 0; i < (int)m_dimensionSize.x; i++) {
		for (int j = 0; j < (int)m_dimensionSize.y; j++) {
			m_window.Draw(m_grid[i][j]);
		}
	}

	m_window.EndDraw();
}

void RotateGrid::SetRotateOffset(float l_RotateOffset) { m_RotateOffset = l_RotateOffset; }
void RotateGrid::SetRotateSpeed(float l_RotateSpeed) { m_RotateOffset = l_RotateSpeed; }

void RotateGrid::InitGrid(sf::Vector2f l_dimensionSize, float gridSize) {
	int n = (int)l_dimensionSize.x;
	int m = (int)l_dimensionSize.y;
	float half_size = gridSize / 2;
	m_grid.reserve(n);
	for (int i = 0; i < n; i++) {
		std::vector<sf::RectangleShape> line;
		line.reserve(m);
		for (int j = 0; j < m; j++) {
			sf::RectangleShape r(sf::Vector2f(gridSize, gridSize));
			r.setFillColor(sf::Color::White);
			r.setPosition(sf::Vector2f((float)i * gridSize + half_size, (float)j * gridSize + half_size));
			r.setRotation(m_RotateOffset);
			r.setOrigin(sf::Vector2f(half_size, half_size));
			line.push_back(r);
		}
		m_grid.push_back(line);
	}
}