#pragma once

#include <memory>

#include <GLFW/glfw3.h>

#include "GameManager.h"

class Window
{
private:
	GLFWwindow* glfwWindow;
	int width;
	int height;
private:
	Window() = delete;
	Window(const Window&) = delete;
	Window(const Window&&) = delete;
	Window(int& width, int& height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
public:
	static std::unique_ptr<Window> create(int width, int height, const char* title, GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);

	GLFWwindow* getGLFWwindow() const;
};