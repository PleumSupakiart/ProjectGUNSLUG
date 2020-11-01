#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Animation
{
public:
	Animation(Texture* texture, Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime,bool faceright);

public:
	IntRect uvRect;
private:
	Vector2u imageCount;
	Vector2u currentImage;

	float totalTime;
	float switchTime;

};

