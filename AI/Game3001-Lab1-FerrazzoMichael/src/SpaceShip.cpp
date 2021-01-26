#include "SpaceShip.h"

#include "Util.h"

SpaceShip::SpaceShip()
{
	TextureManager::Instance()->load("../Assets/textures/spaceship.png", "spaceship");

	auto size = TextureManager::Instance()->getTextureSize("spaceship");
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
}

SpaceShip::~SpaceShip()
= default;

void SpaceShip::draw()
{
	// draw the ship using vector position
	TextureManager::Instance()->draw("spaceship",
		getTransform()->position.x, getTransform()->position.y, m_rotationAngle, 255, true);

	

	Util::DrawLine(getTransform()->position, (getTransform()->position + m_orientation * 60.0f));

	// older method below
	
	// alias for x and y
	//const auto x = getTransform()->position.x;
	//const auto y = getTransform()->position.y;

	// draw the ship
	//TextureManager::Instance()->draw("spaceship", x, y, 0, 255, true);
}

void SpaceShip::update()
{
	m_Move();
}

void SpaceShip::clean()
{
}

void SpaceShip::setDestination(const glm::vec2 destination)
{
	m_destination = destination;
}

void SpaceShip::setMaxSpeed(float speed)
{
	m_maxSpeed = speed;
}

void SpaceShip::setOrientation(glm::vec2 orientation)
{
	m_orientation = orientation;
}

void SpaceShip::setRotation(float angle)
{
	m_rotationAngle = angle;
}

void SpaceShip::m_Move()
{
	// direction with magnitude
	m_direction = m_destination - getTransform()->position;

	// normalized direction
	m_direction = Util::normalize(m_direction);

	getRigidBody()->velocity = m_direction * m_maxSpeed;

	getTransform()->position += getRigidBody()->velocity;
}
