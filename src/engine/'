#include "common.h"
#include <stdio.h>

void Engine::Init()
{
	if(!glfwInit())
	{
		//print to log
		return false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "Roguelike v0.1", NULL, NULL);
	if(winfow == NULL)
	{
		//print to log
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	if(glewInit() != GLEW_OK)
	{
		//print to log
		glfwTerminate();
		return false;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(0.0f, 0.0f. 0.0f, 0.0f);
}
