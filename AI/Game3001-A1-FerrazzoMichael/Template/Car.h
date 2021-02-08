#pragma once
#ifndef __CAR__
#define  __CAR__
#include "Line.h"
#include "../src/DisplayObject.h"
#include "../src/Obstacle.h"

class Car final : public DisplayObject
{
public:
	// constructor(s)
	Car();

	// destructor
	~Car();

	// life-cycle methods inherited from DisplayObject
	void draw() override;
	void update() override;
	void clean() override;

	// getters and setters
	void setDestination(glm::vec2 destination);
	void setMaxSpeed(float speed);
	glm::vec2 getOrientation() const;
	void setOrientation(glm::vec2 orientation);
	float getRotation() const;
	void setRotation(float angle);
	float getTurnRate() const;
	void setTurnRate(const float rate);
	float getAccelerationRate() const;
	void setAccelerationRate(const float rate);
	float getState() const;
	void setState(const float state);
	void setWhisker(glm::vec2 start, glm::vec2 end);
	void setCollision(bool hit);
	bool getCollision();
	friend class PlayScene;

private:
	glm::vec2 m_destination;
	glm::vec2 m_targetDirection;
	glm::vec2 m_orientation;
	float m_rotationAngle;
	float m_maxSpeed;
	float m_turnrate;
	float m_accelerationRate;
	float m_state = 1;
	Line m_leftWhisker, m_rightWhisker;
	float m_collision = -1.0f;

	// private function
	void m_Move();
	void m_Flee();
	void m_Arrive();
	void m_Avoid();
};


#endif