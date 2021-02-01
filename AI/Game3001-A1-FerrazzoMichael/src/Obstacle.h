#pragma once
#ifndef __OBSTACLE__
#define __OBStACLE__
#include "DisplayObject.h"

class Obstacle : public DisplayObject
{
public:
	// constructors
	Obstacle();
	
	// destructor
	~Obstacle();

	// life cycle functions
	void draw() override;
	void update() override;
	void clean() override;

private:
	
};

#endif

