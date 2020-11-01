#pragma once
#include <SFML/Graphics.hpp>
#include "Animetion.h"

using namespace std;
using namespace sf;
class player
{
public:
	player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~player();

	void Update(float deltaTime);
	void Draw(RenderWindow& window);
private:
	RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceright;

};

