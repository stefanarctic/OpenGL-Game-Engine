#include "GameManager.h"

GameManager& GameManager::getInstance()
{
	static GameManager m_Instance;
	return m_Instance;
}

void GameManager::init()
{
	GameManager& gm = getInstance();
	gm.m_GameObjects = std::vector<std::shared_ptr<GameObject>>();
}

void GameManager::addGameObject(std::shared_ptr<GameObject> goSPtr)
{
	GameManager& gm = getInstance();
	gm.m_GameObjects.push_back(goSPtr);
}

void GameManager::removeGameObject(std::shared_ptr<GameObject> goSPtr)
{
	GameManager& gm = getInstance();
	auto it = std::find(gm.m_GameObjects.begin(), gm.m_GameObjects.end(), goSPtr);
	
	// It should always find the shared pointer, so no need to check
	gm.m_GameObjects.erase(it);

	//auto it = std::find(getInstance().m_GameObjects.begin(),)
	//std::shared_ptr<GameObject> s_ptr = std::make_shared())
	//GameObject* newGameObject = GameObject::create(123, 142, 512, 617);
	//std::shared_ptr<GameObject> s_ptr = std::make_shared<GameObject>(newGameObject);
}