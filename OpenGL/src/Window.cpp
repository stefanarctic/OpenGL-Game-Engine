#include "Window.h"

Window::Window(int& width, int& height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	this->width = width;
	this->height = height;
	this->glfwWindow = glfwCreateWindow(width, height, title, monitor, share);
	if (!this->glfwWindow)
	{
		GameManager::getInstance()->terminate();
	}
}

std::unique_ptr<Window> Window::create(int width, int height, const char* title, GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL)
{
	Window* window = new Window(width, height, title, monitor, share);
	std::unique_ptr<Window> windowUPtr = std::make_unique<Window>(window);

	return windowUPtr;
}

GLFWwindow* Window::getGLFWwindow() const
{
	return this->glfwWindow;
}
