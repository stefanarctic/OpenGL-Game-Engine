#include "GameManager.h"

void GameManager::mainLoop()
{
	while (!glfwWindowShouldClose(this->m_Window.get()->getGLFWwindow()))
	{
		this->tick();
		std::this_thread::sleep_for(std::chrono::milliseconds(tickrate));
	}
	this->terminate();
}

void GameManager::tick()
{
	std::cout << "Every tick" << '\n';
}

void GameManager::render()
{
	// Nothing yet
}

GameManager* GameManager::getInstance()
{
	static GameManager m_Instance;
	return &m_Instance;
}

void GameManager::init()
{
	if (!glfwInit())
		exit(-1);
	this->initialized = true;
	this->m_GameObjects = std::vector<std::shared_ptr<GameObject>>();

	// Start game loop
	this->mainLoop();
}

void GameManager::addGameObject(std::shared_ptr<GameObject> goSPtr)
{
	this->m_GameObjects.push_back(goSPtr);
}

std::shared_ptr<GameObject> GameManager::copyGameObject(std::shared_ptr<GameObject> goSPtr)
{
	std::shared_ptr<GameObject> newObject = GameObject::create(*goSPtr.get());

	return newObject;
}

void GameManager::removeGameObject(std::shared_ptr<GameObject> goSPtr)
{
	auto it = std::find(this->m_GameObjects.begin(), this->m_GameObjects.end(), goSPtr);
	
	// It should always find the shared pointer, so no need to check
	this->m_GameObjects.erase(it);

	//auto it = std::find(getInstance().m_GameObjects.begin(),)
	//std::shared_ptr<GameObject> s_ptr = std::make_shared())
	//GameObject* newGameObject = GameObject::create(123, 142, 512, 617);
	//std::shared_ptr<GameObject> s_ptr = std::make_shared<GameObject>(newGameObject);
}

void GameManager::setPrimaryWindow(std::shared_ptr<Window> windowUPtr)
{
	this->m_Window = windowUPtr;
	glfwMakeContextCurrent(this->m_Window.get()->getGLFWwindow());
}

std::shared_ptr<Window> GameManager::getCurrentWindow() const
{
	return this->m_Window;
}

void GameManager::terminate()
{
	glfwTerminate();
	exit(-1);
}
