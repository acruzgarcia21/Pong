#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Bat {
private:
	// Holds x and y position of our bat
	Vector2f m_Position;
	// A rectangle shape object
	RectangleShape m_Shape;

	float m_Speed{ 1000.0f };
	bool m_MovingRight{ false };
	bool m_MovingLeft{ false };

public:
	// Constructors
	Bat () {}
	Bat(float& , float&);

	// Getters
	FloatRect getPosition();
	RectangleShape getShape();

	// Bool updates
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();

	// Update positon
	void updatePosition(const Time&);
};
