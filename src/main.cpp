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

	GLuint VertexArrayID;  					// VertexArrayID will store ID OpenGL gives us for the VAO
	glGenVertexArrays(1, &VertexArrayID);   // Tells OpenGL to generate 1 VAO and store it in the ID 
	glBindVertexArray(VertexArrayID);       // Binds the VAO, so all subsuquent vertex commands are stored inside it.
	
	static const GLfloat g_vertex_buffer_data[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer); // Binds generated VBO as current array buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW); 
	// sizeof(f_vertex_buffer_data) gets the size in bytes
	// g_vertex_buffer_data This is a pointer to the actual vertex data you want to upload into the buffer
	// GL_STATIC_DRAW This tells OpenGL how I intend to handle the data

	glEnableVertexAttribArray(0);    								// Vertex attributes are inputs to my vertex shader like - positions, colors, ect
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer); 					// It rebinds the same VBO to make sure the follow glEnableVertexAttribArray uses the correct buffer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);  
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);

	
    GLuint core_program;
	 


	}
	glfwTerminate();
	return 0;
}
