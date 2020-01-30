#include "Level.h"

float speed = 300.f, speed2 = 300.f, speed3X = 300.f, speed3Y = 300.f;
float movement = 0, movementX = 0, movementY = 0;
float movementX3 = 0, movementY3 = 0;


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	circle.setRadius(10);
	circle.setPosition(550, 287.5);
	circle.setFillColor(sf::Color::Cyan);
	circle.setOutlineColor(sf::Color::Green);
	circle.setOutlineThickness(2.f);

	circle2.setRadius(20);
	circle2.setPosition(550, 287.5);
	circle2.setFillColor(sf::Color::Magenta);
	circle2.setOutlineColor(sf::Color::Black);
	circle2.setOutlineThickness(1.f);

	circle3.setRadius(30);
	circle3.setPosition(100, 200);
	circle3.setFillColor(sf::Color::Yellow);
	circle3.setOutlineColor(sf::Color::White);
	circle3.setOutlineThickness(3.f);

}

Level::~Level()
{

}


// handle user input
void Level::handleInput(float dt)
{
	sf::Vector2u pos = window->getSize();
	movementY = 0;
	movementX = 0;

	if (circle2.getPosition().y > 0)
	{
		if (input->isKeyDown(sf::Keyboard::Up))
		{
			speed2 = -300.f;
			movementY = speed2 * dt;

		}
	}

	if (circle2.getPosition().y+40 < pos.y)
	{
		if (input->isKeyDown(sf::Keyboard::Down) && circle2.getPosition().y < pos.y)
		{

			speed2 = 300.f;
			movementY = speed2 * dt;

		}
	}

	if (circle2.getPosition().x > 0)
	{
		if (input->isKeyDown(sf::Keyboard::Left) && circle2.getPosition().x > 0)
		{
			speed2 = -300.f;
			movementX = speed2 * dt;

		}
	}

	if (circle2.getPosition().x+40 < pos.x)
	{
		if (input->isKeyDown(sf::Keyboard::Right) && circle2.getPosition().x < pos.x)
		{
			speed2 = 300.f;
			movementX = speed2 * dt;

		}
	}
}

// Update game objects
void Level::update(float dt)
{
	
	sf::Vector2u pos = window->getSize();
	if (circle.getPosition().x+20 > pos.x)
	{
		movement = 0;
		speed = -300.f;
	}

	if (circle.getPosition().x < 0)
	{
		movement = 0;
			speed = 300.f;
	}

	if (circle3.getPosition().x + 60 > pos.x)
	{
		movementX3 = 0;
		speed3X = -300.f;
		
	}

	if (circle3.getPosition().x < 0)
	{
		movementX3 = 0;
		speed3X = 300.f;
		
	}

	if (circle3.getPosition().y + 60 > pos.y)
	{
		movementY3 = 0;
		speed3Y = -300.f;
		
	}

	if (circle3.getPosition().y < 0)
	{
		movementY3 = 0;
		speed3Y = 300.f;
		
	}

	movement = speed * dt;
	movementY3 = speed3Y * dt;
	movementX3 = speed3X * dt;
	
	circle.move(movement, 0);
	circle2.move(movementX, movementY);
	circle3.move(movementX3, movementY3);
		
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);
	window->draw(circle2);
	window->draw(circle3);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}