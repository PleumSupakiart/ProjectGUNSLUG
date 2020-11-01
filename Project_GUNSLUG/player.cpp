#include "player.h"
using namespace sf;
player::player(Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed * 2;
	row = 0;

	body.setSize(sf::Vector2f(80.0f, 100.0f));
	body.setPosition(0, 0);
	body.setTexture(texture);
}
player::~player()
{
}

void player::Update(float deltatime)
{
	Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		movement.x -= speed * deltatime * 0.5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		movement.x += speed * deltatime * 0.5;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		movement.x += speed * deltatime;
		row = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		movement.x -= speed * deltatime;
		row = 1;
	}

	if (movement.x == 0)
	{
		row = 0;
	}
	else
	{
		

		if (movement.x > 0.0f)
			faceright = true;
		else
			faceright = false;
	}
	
	animation.Update(row, deltatime,faceright);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void player::Draw(RenderWindow& window)
{
	window.draw(body);
}
