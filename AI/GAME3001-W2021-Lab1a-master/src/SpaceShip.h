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
	
private:
	glm::vec2 m_destination;

	glm::vec2 m_direction;
};



#endif /* defined (__SPACE_SHIP__) */