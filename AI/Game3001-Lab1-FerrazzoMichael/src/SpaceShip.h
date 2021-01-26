#pragma once
#ifndef __SPACE_SHIP__
#define __SPACE_SHIP__

#include "DisplayObject.h"
#include "TextureManager.h"

class SpaceShip final : public DisplayObject
{
public:
	// Constructor(s)
	SpaceShip();

	// Destructor
	~SpaceShip();
	
	// Inherited via DisplayObject
	void draw() override;
	void update() override;
	void clean() override;

	// getters and setters
	void setDestination(glm::vec2 destination);
	void setMaxSpeed(float speed);
	void setOrientation(glm::vec2 orientation);
	void setRotation(float angle);
	
private:
	glm::vec2 m_destination;
	glm::vec2 m_direction;
	glm::vec2 m_orientation;
	float m_rotationAngle;
	float m_maxSpeed;

	void m_Move();
};



#endif /* defined (__SPACE_SHIP__) */