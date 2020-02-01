#ifndef ENG_COMMON_H
#define ENG_COMMON_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Engine
{
	GLFWwindow *window;
public:
	void MainLoop();
	void Draw();
	bool Init();
	void CalculateCollision();
};

#endif
