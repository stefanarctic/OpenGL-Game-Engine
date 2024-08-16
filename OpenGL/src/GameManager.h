#pragma once

#include <vector>
#include <memory>

#include "GameObject.h"
#include "Window.h"

class GameManager
{
private:
	static std::vector<std::shared_ptr<GameObject>> m_GameObjects;
public:
	static GameManager& getInstance();
	static void init();
	static void addGameObject(std::shared_ptr<GameObject> goSPtr);
	static void removeGameObject(std::shared_ptr<GameObject> goSPtr);
private:
	GameManager() {}
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
};