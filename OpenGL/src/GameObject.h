#pragma once

#include <utility>
#include <memory>

class GameObject
{
public:
    std::pair<int, int> position;
    std::pair<int, int> size;

    static std::shared_ptr<GameObject> create(const int& x, const int& y, const int& w, const int& h);
    static std::shared_ptr<GameObject> create(const std::pair<int, int>& _position, const std::pair<int, int>& _size);
    static std::shared_ptr<GameObject> create(const GameObject& go);
private:
    GameObject() = delete;
    GameObject(const int& x, const int& y, const int& w, const int& h);
    GameObject(const std::pair<int, int>& _position, const std::pair<int, int>& _size);
};