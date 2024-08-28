#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <thread>

#include "GameObject.h"
#include "Window.h"

class GameManager
{
private:
	bool initialized = true;
	std::shared_ptr<Window> m_Window;
	std::vector<std::shared_ptr<GameObject>> m_GameObjects;
	int tickrate = 1;
private:
	void mainLoop();
	void tick();
	void render();
public:
	static GameManager* getInstance();
	void init();

	void addGameObject(std::shared_ptr<GameObject> goSPtr);
	std::shared_ptr<GameObject> copyGameObject(std::shared_ptr<GameObject> goSPtr);
	void removeGameObject(std::shared_ptr<GameObject> goSPtr);

	void setPrimaryWindow(std::shared_ptr<Window> windowUPtr);
	std::shared_ptr<Window> getCurrentWindow() const;

	void terminate();
private:
	GameManager() {}
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
};