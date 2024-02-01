#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>


class RectVAO {
public:
	GLuint VAO, VBO;

	RectVAO();

	void Delete();
};
