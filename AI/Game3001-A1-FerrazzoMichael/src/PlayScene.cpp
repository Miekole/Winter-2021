#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"

// required for IMGUI
#include "imgui.h"
#include "imgui_sdl.h"
#include "Renderer.h"
#include "Util.h"

PlayScene::PlayScene()
{
	PlayScene::start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	if(EventManager::Instance().isIMGUIActive())
	{
		GUI_Function();
	}

	drawDisplayList();
	SDL_SetRenderDrawColor(Renderer::Instance()->getRenderer(), 255, 255, 255, 255);
}

void PlayScene::update()
{
	updateDisplayList();

	CollisionManager::AABBCheck(m_pCar, m_pObstacle);
	if (m_pCar->getState() == 3)
	{
		if (CollisionManager::lineRectCheck(m_pCar->m_leftWhisker.Start(), m_pCar->m_leftWhisker.End(),
			m_pObstacle->getTransform()->position - glm::vec2(100.0f, 50.0f), 200.0f, 100.0f))
		{
			std::cout << "touched left" << std::endl;
			m_pCar->setCollision(1.0f);
		}
		else if (CollisionManager::lineRectCheck(m_pCar->m_rightWhisker.Start(), m_pCar->m_rightWhisker.End(),
			m_pObstacle->getTransform()->position - glm::vec2(100.0f, 50.0f), 200.0f, 100.0f))
		{
			std::cout << "touched right" << std::endl;
			m_pCar->setCollision(0.0f);
		}
		else
		{
			m_pCar->setCollision(-1.0f);
		}
	}
}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	EventManager::Instance().update();

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		m_pCar->getRigidBody()->velocity = glm::vec2(0.0f);
		m_pObstacle->setEnabled(false);
		m_pCar->setEnabled(true);
		m_pCar->setState(1);
		m_pCar->getTransform()->position = glm::vec2(100.0f, 300.0f);
		m_pTarget->getTransform()->position = glm::vec2(700.0f, 300.0f);
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_2))
	{
		m_pCar->getRigidBody()->velocity = glm::vec2(0.0f);
		m_pObstacle->setEnabled(false);
		m_pCar->setEnabled(true);
		m_pCar->setState(2);
		m_pCar->getTransform()->position = glm::vec2(400.0f, 300.0f);
		m_pTarget->getTransform()->position = glm::vec2(500.0f, 300.0f);
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_3))
	{
		m_pCar->getRigidBody()->velocity = glm::vec2(0.0f);
		m_pObstacle->setEnabled(true);
		m_pCar->setEnabled(true);
		m_pCar->setState(3);
		m_pCar->getTransform()->position = glm::vec2(100.0f, 300.0f);
		m_pTarget->getTransform()->position = glm::vec2(700.0f, 300.0f);
	}
	else
	{
		//m_pCar->getTransform()->position = glm::vec2(100.0f, 100.0f);
		//m_pCar->setEnabled(false);
		//m_pCar->getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
		//m_pCar->setRotation(0.0f); // set angle to 0 degrees
	}
}

void PlayScene::start()
{
	// Set GUI Title
	m_guiTitle = "Play Scene";

	

	const SDL_Color blue = { 0, 0, 255, 255 };
	const SDL_Color red = { 255, 0, 0, 255 };
	const SDL_Color green = { 0, 255, 0, 255 };
	
	m_label1 = new Label("Press 1 for seek", "Consolas", 50, green, glm::vec2(235.0f, 100.0f));
	m_label1->setParent(this);
	addChild(m_label1);
	
	m_label2 = new Label("Press 2 for flee", "Consolas", 50, green, glm::vec2(235.0f, 150.0f));
	m_label2->setParent(this);
	addChild(m_label2);

	m_label3 = new Label("Press 3 for something", "Consolas", 50, green, glm::vec2(300.0f, 200.0f));
	m_label3->setParent(this);
	addChild(m_label3);
	
	m_pTarget = new Target();
	m_pTarget->getTransform()->position = glm::vec2(700.0f, 300.0f);
	addChild(m_pTarget);

	m_pObstacle = new Obstacle();
	m_pObstacle->getTransform()->position = glm::vec2(500.0f, 300.0f);
	m_pObstacle->setEnabled(false);
	addChild(m_pObstacle);
	
	// instantiating spaceship
	m_pCar = new Car();
	m_pCar->getTransform()->position = glm::vec2(100.0f, 300.0f);
	m_pCar->setEnabled(false);
	m_pCar->setDestination(m_pTarget->getTransform()->position);
	m_pCar->m_leftWhisker.Setine(m_pCar->getTransform()->position,
		(m_pCar->getTransform()->position + m_pCar->getOrientation() * 100.0f));
	m_pCar->m_rightWhisker.Setine(m_pCar->getTransform()->position,
		(m_pCar->getTransform()->position + m_pCar->getOrientation() * -100.0f));
	addChild(m_pCar);
}

void PlayScene::GUI_Function() const
{
	// Always open with a NewFrame
	ImGui::NewFrame();

	// See examples by uncommenting the following - also look at imgui_demo.cpp in the IMGUI filter
	//ImGui::ShowDemoWindow();
	
	ImGui::Begin("Hidden Controls", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_MenuBar);

	static float speed = 10.0f;
	if(ImGui::SliderFloat("MaxSpeed", &speed, 0.0f, 100.0f))
	{
		m_pCar->setMaxSpeed(speed);
	}

	static float acceleration_rate = 2.0f;
	if(ImGui::SliderFloat("Acceleration Rate", &acceleration_rate, 0.0f, 50.0f))
	{
		m_pCar->setAccelerationRate(acceleration_rate);
	}

	static float angleInRadians = m_pCar->getRotation();
	if(ImGui::SliderAngle("Orientation Angle", &angleInRadians))
	{
		m_pCar->setRotation(angleInRadians * Util::Rad2Deg);
	}
	
	static float turn_rate = 5.0f;
	if(ImGui::SliderFloat("Turn Rate", &turn_rate, 0.0f, 20.0f))
	{
		m_pCar->setTurnRate(turn_rate);
	}
	
	if(ImGui::Button("Start"))
	{
		m_pCar->setEnabled(true);
	}

	ImGui::SameLine();
	
	if (ImGui::Button("Reset"))
	{
		m_pCar->getTransform()->position = glm::vec2(100.0f, 100.0f);
		m_pCar->setEnabled(false);
		m_pCar->getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
		m_pCar->setRotation(0.0f); // set angle to 0 degrees
		turn_rate = 5.0f;
		acceleration_rate = 2.0f;
		speed = 10.0f;
	}

	ImGui::Separator();

	static float targetPosition[2] = { m_pTarget->getTransform()->position.x, m_pTarget->getTransform()->position.y};
	if(ImGui::SliderFloat2("Target", targetPosition, 0.0f, 800.0f))
	{
		m_pTarget->getTransform()->position = glm::vec2(targetPosition[0], targetPosition[1]);
		m_pCar->setDestination(m_pTarget->getTransform()->position);
	}

	ImGui::End();

	// Don't Remove this
	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());
	ImGui::StyleColorsDark();
}
