#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Scene.h"
#include "Button.h"
#include "Label.h"
#include "Obstacle.h"
#include "SpaceShip.h"
#include "Target.h"
#include "../Template/Car.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	
private:
	// IMGUI Function
	void GUI_Function() const;
	std::string m_guiTitle;
	
	glm::vec2 m_mousePosition;

	Car* m_pCar;
	SpaceShip* m_pSpaceShip;
	Target* m_pTarget;
	Obstacle* m_pObstacle;
	
	// UI Items
	Label* m_label1;
	Label* m_label2;
	Label* m_label3;
};

#endif /* defined (__PLAY_SCENE__) */