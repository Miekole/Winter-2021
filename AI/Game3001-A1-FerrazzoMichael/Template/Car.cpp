#include "Car.h"


#include "../src/Game.h"
#include "../src/TextureManager.h"
#include "../src/Util.h"

Car::Car()
{
	TextureManager::Instance()->load("../Assets/textures/Octain.png", "Octain");

	auto size = TextureManager::Instance()->getTextureSize("Octain");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(SPACE_SHIP);
	setMaxSpeed(10.0f);
	setOrientation(glm::vec2(0.0f, -1.0f));
	setRotation(0.0f);
	setAccelerationRate(10.0f);
	setTurnRate(10.0f);
}

Car::~Car()
= default;

void Car::draw()
{
	TextureManager::Instance()->draw("Octain",
		getTransform()->position.x, getTransform()->position.y, m_rotationAngle, 255, true);

	/*Util::DrawLine(getTransform()->position, (getTransform()->position + getOrientation() * 60.0f));*/
	Util::DrawLine(m_leftWhisker.Start(), m_leftWhisker.End());
	Util::DrawLine(m_rightWhisker.Start(), m_rightWhisker.End());
}

void Car::update()
{
	m_leftWhisker.Setine(getTransform()->position,
		(getTransform()->position + Util::getOrientation(m_rotationAngle - 45) * 100.0f));
	m_rightWhisker.Setine(getTransform()->position,
		(getTransform()->position + Util::getOrientation(m_rotationAngle + 45) * 100.0f));
	if (m_state == 1)
	{
		m_Move();
	}
	else if(m_state == 2)
	{
		m_Flee();
	}
	else if (m_state == 3)
	{
		m_Avoid();
	}
}

void Car::clean()
{
}

void Car::setDestination(glm::vec2 destination)
{
	m_destination = destination;
}

void Car::setMaxSpeed(float speed)
{
	m_maxSpeed = speed;
}

glm::vec2 Car::getOrientation() const
{
	return m_orientation;
}

void Car::setOrientation(glm::vec2 orientation)
{
	m_orientation = orientation;
}

float Car::getRotation() const
{
	return m_rotationAngle;
}

void Car::setRotation(float angle)
{
	m_rotationAngle = angle;

	const auto offset = -90.0f;
	const auto angle_in_radius = (angle + offset) * Util::Deg2Rad;

	const auto x = cos(angle_in_radius);
	const auto y = sin(angle_in_radius);

	// convert angle to normalized vector and store in orientation
	setOrientation((glm::vec2(x, y)));
}

float Car::getTurnRate() const
{
	return m_turnrate;
}

void Car::setTurnRate(const float rate)
{
	m_turnrate = rate;
}

float Car::getAccelerationRate() const
{
	return m_accelerationRate;
}

void Car::setAccelerationRate(const float rate)
{
	m_accelerationRate = rate;
}

float Car::getState() const
{
	return m_state;
}

void Car::setState(const float state)
{
	m_state = state;
}

void Car::setWhisker(glm::vec2 start, glm::vec2 end)
{
	m_leftWhisker.Setine(start, end);
	m_rightWhisker.Setine(start, end);
}

void Car::setCollision(bool hit)
{
	m_collision = hit;
}

bool Car::getCollision()
{
	return m_collision;
}

void Car::m_Move()
{
	auto deltaTime = TheGame::Instance()->getDeltaTime();

	// direction with magnitude
	m_targetDirection = m_destination - getTransform()->position;

	// normalized direction
	m_targetDirection = Util::normalize(m_targetDirection);

	auto target_rotation = Util::signedAngle(getOrientation(), m_targetDirection);

	auto turn_sensitivity = 5.0f;

	if (abs(target_rotation) > turn_sensitivity)// <-- will only turn when outside of turn sensitivity
	{
		if (target_rotation > 0.0f)
		{
			setRotation((getRotation() + getTurnRate()));
		}
		else if (target_rotation < 0.0f)
		{
			setRotation(getRotation() - getTurnRate());
		}
	}

	getRigidBody()->acceleration = getOrientation() * getAccelerationRate();

	getRigidBody()->velocity += getOrientation() * (deltaTime)+
		0.5f * getRigidBody()->acceleration * (deltaTime * deltaTime); // <-- pf = pi + vi*t + 0.5ai*t^2

	getRigidBody()->velocity = Util::clamp(getRigidBody()->velocity, m_maxSpeed);

	getTransform()->position += getRigidBody()->velocity;
}

void Car::m_Flee()
{
	auto deltaTime = TheGame::Instance()->getDeltaTime();

	// direction with magnitude
	m_targetDirection = m_destination - getTransform()->position;

	// normalized direction
	m_targetDirection = Util::normalize(m_targetDirection);

	const auto target_rotation = Util::signedAngle(getOrientation(), m_targetDirection);

	const auto turn_sensitivity = 165.0f;

	if (abs(target_rotation) < turn_sensitivity)// <-- will only turn when outside of turn sensitivity
	{
		if (target_rotation < 0.0f)
		{
			setRotation((getRotation() + getTurnRate()));
		}
		else if (target_rotation > 0.0f)
		{
			setRotation(getRotation() - getTurnRate());
		}
	}

	getRigidBody()->acceleration = getOrientation() * getAccelerationRate();

	getRigidBody()->velocity += getOrientation() * (deltaTime)+
		0.5f * getRigidBody()->acceleration * (deltaTime * deltaTime); // <-- pf = pi + vi*t + 0.5ai*t^2

	getRigidBody()->velocity = Util::clamp(getRigidBody()->velocity, m_maxSpeed);

	getTransform()->position += getRigidBody()->velocity;
}

void Car::m_Arrive()
{
	auto deltaTime = TheGame::Instance()->getDeltaTime();

	// direction with magnitude
	m_targetDirection = m_destination - getTransform()->position;

	// normalized direction
	m_targetDirection = Util::normalize(m_targetDirection);

	auto target_rotation = Util::signedAngle(getOrientation(), m_targetDirection);

	auto turn_sensitivity = 5.0f;
}

void Car::m_Avoid()
{
	auto deltaTime = TheGame::Instance()->getDeltaTime();
	
	// direction with magnitude
	m_targetDirection = m_destination - getTransform()->position;

	// normalized direction
	m_targetDirection = Util::normalize(m_targetDirection);

	auto target_rotation = Util::signedAngle(getOrientation(), m_targetDirection);

	auto turn_sensitivity = 5.0f;

	if (abs(target_rotation) > turn_sensitivity)// <-- will only turn when outside of turn sensitivity
	{
		if (target_rotation > 0.0f)
		{
			setRotation((getRotation() + getTurnRate()));
		}
		else if (target_rotation < 0.0f)
		{
			setRotation(getRotation() - getTurnRate());
		}
	}

	getRigidBody()->acceleration = getOrientation() * getAccelerationRate();

	getRigidBody()->velocity += getOrientation() * (deltaTime)+
		0.5f * getRigidBody()->acceleration * (deltaTime * deltaTime); // <-- pf = pi + vi*t + 0.5ai*t^2

	getRigidBody()->velocity = Util::clamp(getRigidBody()->velocity, m_maxSpeed);

	getTransform()->position += getRigidBody()->velocity;
}