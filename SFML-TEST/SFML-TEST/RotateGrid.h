#pragma once
#include "Window.h"
class RotateGrid{
public:
    RotateGrid(int dx, int dy, float gridSize, float rotateSpeed, float rotateOffset);
    ~RotateGrid();
    void Render();
    void Update();
    void RestartClock();
    void Step();
    void Run();
    sf::Time GetElapsedTime();
    Window* GetWindow();
    void SetRotateOffset(float l_RotateOffset);
    void SetRotateSpeed(float l_RotateSpeed);
    void InitGrid(sf::Vector2f l_dimensionSize, float gridSize);
private:
    Window m_window;
    sf::Vector2f m_dimensionSize;
    sf::Time m_elapsed;
    sf::Clock m_clock;
    std::vector<std::vector<sf::RectangleShape>> m_grid;
    float m_gridSize;
    float m_RotateOffset;
    float m_RotateSpeed;
};

