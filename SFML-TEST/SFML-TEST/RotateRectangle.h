#pragma once
#include "Window.h"
class RotateRectangle
{
public:
    RotateRectangle();
    ~RotateRectangle();
    void Update();
    void ChangeRectLocation();
    void Render();
    sf::Time GetElapsedTime();
    void RestartClock();
    Window* GetWindow();
    float GetAngleSpeed();
    void SetAngleSpeed(float l_angleSpeed);
    float GetRotateSpeed();
    void SetRotateSpeed(float l_rotateSpeed);
    float GetRadius();
    void SetRadius(float l_radius);
private:
    Window m_window;
    sf::Clock m_clock;
    sf::Time m_elapsed;
    sf::RectangleShape m_rectangle;
    float m_radius;
    float m_angleSpeed;
    float m_rotateSpeed;
};

