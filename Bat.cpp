#include "Bat.h"


// Constructor
Bat::Bat(float& startX, float& startY) : m_Position(startX, startY) 
{
	this->m_Shape.setSize(Vector2f(50.0f, 5.0f));
	this->m_Shape.setPosition(Vector2f(m_Position));
}

// Getters
FloatRect Bat::getPosition() 
{
	return this->m_Shape.getLocalBounds();
}
RectangleShape Bat::getShape()
{
	return this->m_Shape;
}

// Bool updates
void Bat::moveLeft()
{
	this->m_MovingLeft = true;
}
void Bat::moveRight()
{
	this->m_MovingRight = true;
}
void Bat::stopLeft()
{
	this->m_MovingLeft = false;
}
void Bat::stopRight()
{
	this->m_MovingRight = false;
}

// Position update
void Bat::updatePosition(const Time& dt)
{
	if (m_MovingLeft) 
	{
		m_Position.x -= m_Speed * dt.asSeconds();
	}
	if (m_MovingRight)
	{
		m_Position.x += m_Speed * dt.asSeconds();
	}

	m_Shape.setPosition(m_Position);
}
