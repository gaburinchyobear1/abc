#pragma comment(lib, "OpenGL32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

static double First_X, First_Y;
static float moveFactor_X = 0.0f;
static float moveFactor_Y = 0.0f;

static bool isLeftClick;
static bool isRightClick;
static float scaleFactor = 1.0f;

void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}

int render()
{
	// 빨간색 세모
	glBegin(GL_TRIANGLES);
	// 점1
	glColor3f(1.0f, 0.0f, 0.0f); 
	glVertex2f((-0.6f * scaleFactor) + moveFactor_X, (0.4f * scaleFactor) + moveFactor_Y);
	// 점2
	glColor3f(1.0f, 0.0f, 0.0f); 
	glVertex2f((0.6f * scaleFactor) + moveFactor_X, (0.4f * scaleFactor) + moveFactor_Y);
	// 점3
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f((0.0f * scaleFactor) + moveFactor_X, (-0.4f * scaleFactor) + moveFactor_Y);
	glEnd();

	// 파란색 세모
	glBegin(GL_TRIANGLES);
	// 점1
	glColor3f(0.0f, 0.0f, 1.0f); 
	glVertex2f((-0.2f * scaleFactor) + moveFactor_X, (-0.2f * scaleFactor) + moveFactor_Y);
	// 점2
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f((0.0f * scaleFactor) + moveFactor_X, (1.0f * scaleFactor) + moveFactor_Y);
	// 점3
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f((0.4f * scaleFactor) + moveFactor_X, (-0.8f * scaleFactor) + moveFactor_Y);
	glEnd();

	// 초록색 세모
	glBegin(GL_TRIANGLES);
	// 점1
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f((-0.4f * scaleFactor) + moveFactor_X, (-0.8f * scaleFactor) + moveFactor_Y);
	// 점2
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f((0.0f * scaleFactor) + moveFactor_X, (1.0f * scaleFactor) + moveFactor_Y);
	// 점3
	glColor3f(0.0f, 1.0f, 0.0f); 
	glVertex2f((0.2f * scaleFactor) + moveFactor_X, (-0.2f * scaleFactor) + moveFactor_Y);
	glEnd();
	return 0;
	
}

//GLFW_PRESS =1   GLFW_RELEASE = 0
//int button 어디서  int action어떻게
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {

	if (button == GLFW_MOUSE_BUTTON_LEFT &&  action == GLFW_PRESS)
	{
		isLeftClick = true;
		glfwGetCursorPos(window, &First_X, &First_Y);
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		isLeftClick = false;
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		isRightClick = true;
		glfwGetCursorPos(window, &First_X, &First_Y);
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		isRightClick = false;
		
	}
	
}






int main(void)
{
	double X, Y;
	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 780, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	while (!glfwWindowShouldClose(window))
	{
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
		glfwGetCursorPos(window, &X, &Y);

		if(isLeftClick){
			moveFactor_Y = (First_Y - Y) * 0.003;
			moveFactor_X = (X - First_X ) * 0.002;
		}
		
		if (isRightClick) {
			
			scaleFactor = 1 + (X - First_X) * 0.001;
		}
		





		glfwPollEvents();
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		render();

		glfwSwapBuffers(window);
	}




	glfwTerminate();
	return 0;

}