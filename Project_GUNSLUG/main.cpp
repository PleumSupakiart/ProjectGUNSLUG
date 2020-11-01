#include<SFML/Graphics.hpp>
#include<iostream>
#include "player.h"

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(1080, 720), "GUN SLUG", Style::Close | Style::Resize);
	
	Texture playertexture;
	playertexture.loadFromFile("sprite/player/standrunjump.png");


	player player(&playertexture, Vector2u(8,3),0.1f, 100.0f);
	

	

	float deltatime = 0.0f;
	Clock clock;

	while (window.isOpen())
	{

		deltatime = clock.restart().asSeconds();
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				break;
			}
		}

		player.Update(deltatime);
		window.clear(Color(150, 150, 150));
		player.Draw(window);
		window.display();
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}
	}
	
	return 0;
}