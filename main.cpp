#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>

int main() 
{
	GLFWwindow* window;

	if(!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(680, 420, "window", NULL, NULL);
	if(!window)
	{
	glfwTerminate();
	return -1;
	}
	
	glfwMakeContextCurrent(window);

	while(!glfwWindowShouldClose(window))
	{
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window);

	glfwPollEvents();

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	}
	glfwTerminate();
	return 0;
}
