
#include "GameObject.h"
#include "GameManager.h"

std::shared_ptr<GameObject> GameObject::create(const int& x, const int& y, const int& w, const int& h)
{
    GameObject* gameObject = new GameObject(x, y, w, h);
    std::shared_ptr<GameObject> goSPtr = std::make_shared<GameObject>(gameObject);

    return goSPtr;
    //GameManager::getInstance().addGameObject(gameObject);
    //return gameObject;
}

std::shared_ptr<GameObject> GameObject::create(const std::pair<int, int>& _position, const std::pair<int, int>& _size)
{
    GameObject* gameObject = new GameObject(_position, _size);
    std::shared_ptr<GameObject> goSPtr = std::make_shared<GameObject>(gameObject);

    return goSPtr;
}

std::shared_ptr<GameObject> GameObject::create(const GameObject& go)
{
    GameObject* gameObject = new GameObject(go);
    std::shared_ptr<GameObject> goSPtr = std::make_shared<GameObject>(gameObject);

    return goSPtr;
}

GameObject::GameObject(const int& x, const int& y, const int& w, const int& h)
    : position(std::make_pair(x, y)), size(std::make_pair(w, h)) {}

GameObject::GameObject(const std::pair<int, int>& _position, const std::pair<int, int>& _size)
    : position(std::make_pair(_position.first, _position.second)), size(std::make_pair(_size.first, _size.second)) {}

GameObject::GameObject(const GameObject& go)
    : position(std::make_pair(go.position.first, go.position.second)), size(go.size.first, go.size.second) {}
