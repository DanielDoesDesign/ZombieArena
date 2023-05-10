#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet
{
private:
	//Where is the bullet?
	Vector2f m_Position;

	//What each bullet looks like 
	RectangleShape m_BulletShape;

	//Is this bullet current whizzing through the air
	bool m_InFlight = false; 

	//How fast does a bullet travel?
	float m_BulletSpeed = 1000;

	//What fraction of 1 pixel does the bullet travel, h and v each frame?
	//These values will be devied from m_BulletSpeed

	float m_BulletDistanceX;
	float m_BulletDistanceY;

	//Sound boundaries so the bullet doesnt fly forever
	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;

public:

	//The constructor
	Bullet();

	//Stop the bullet
	void stop();

	// Returns the value of m_InFlight
	bool isInFlight();

	//Launch a new bullet
	void shoot(float startX, float startY, float xTarget, float yTarget);

	//Tell the calling code where the bullet is in the world
	FloatRect getPosition();

	//Return the actual shape (from drawing)
	RectangleShape getShape();

	//Update the bullet each frame
	void update(float elapsedTime);
};