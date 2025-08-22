#include "Include.h"

int main()
{
	VideoMode vm({1920u, 1080u});
	RenderWindow window(vm, "Pong", State::Fullscreen);

	// Player info
	unsigned int score{ 0 };
	unsigned int lives{ 3 };

	// Creates a bat at the bottom center of the screen
	Bat playerBat{ 1920 / 2, 1080 - 20 };

	Font font;
	if (!font.openFromFile("fonts/Dena.ttf")) 
	{
		std::cout << "Couldn't open from file!" << std::endl;
	}
	Text hud(font);
	hud.setCharacterSize(75u);
	hud.setFillColor(Color::White);
	hud.setPosition(Vector2f(20.0f, 20.0f));

	Clock clock;

	while (window.isOpen())
	{

		while (const std::optional event = window.pollEvent()) 
		{
			if (event->is<Event::Closed>()) 
			{
				// Quit game when window is closed
				window.close();
			}
		}

		// Handle player input
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		{
			window.close();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			playerBat.moveLeft();
		} 
		else 
		{
			playerBat.stopLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			playerBat.moveRight();
		}
		else
		{
			playerBat.stopRight();
		}

		// Update the delta time
		Time dt = clock.restart();
		playerBat.updatePosition(dt);

		std::stringstream ss;
		ss << "Score = " << score << " Lives = " << lives;
		hud.setString(ss.str());

		window.clear();
		window.draw(hud);
		window.draw(playerBat.getShape());
		window.display();

	}
	return 0;
}

