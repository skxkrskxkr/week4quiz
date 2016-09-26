#include "glfw3.h"
#include <algorithm>
#include <stdbool.h>
#include <math.h>

const int width = 1800;
const int height = 1000;
double xPos, yPos;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		int lines = abs(i - i0);
		int lines2 = abs(j1 - j0);
		int lines3 = abs(i1 - i0);
		const int j = (j1 - j0)*lines / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawcircle(const int x, const int y, const int r, const float& red, const float& green, const float& blue, double xPos, double yPos)
{
	int x_c = x;
	int y_c = y;


	for (int a = 0; a <= 2 * r; a++)
	{
		for (int b = 0; b <= 2 * r; b++)
		{
			int f = (r - b)*(r - b) + (r - a)*(r - a) - r*r;
			double f2 = (x_c - xPos)*(x_c - xPos) + (y_c - (height - yPos))*(y_c - (height - yPos)) - r*r;
			if (f < 0 && -1000 < f)
			{
				if (f2 < 0)
				{
					drawPixel(x - r + b, y - r + a, 0, 0, 255);
				}
				else drawPixel(x - r + b, y - r + a, 255, 0, 0);

			}


		}
	}
}

void emptylect(const int x, const int y, const int width, const int height, const float& red, const float& green, const float& blue)
{
	for (int a = 0; a <= width; a++)
	{
		drawPixel(x + a, y, 255, 0, 0);
		drawPixel(x + a, y - height, 255, 0, 0);

	}
	for (int a = 0; a <= height; a++)
	{
		drawPixel(x, y - a, 255, 0, 0);
		drawPixel(x + width, y - a, 255, 0, 0);
	}
}
void lect(const int x, const int y, const int width, const int height, const float& red, const float& green, const float& blue)
{
	for (int a = 0; a <= height; a++)
	{
		for (int b = 0; b <= width; b++)
		{
			drawPixel(x + b, y + a, red, green, blue);
		}
	}
}
int main(void)
{

	GLFWwindow* window;
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "2016112129 Taegun", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glfwGetCursorPos(window, &xPos, &yPos);
	

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		std::fill_n(pixels, width*height * 3, 1.0f);




		drawcircle(180, 750, 150, 255, 0, 0, xPos, yPos);
		drawcircle(540, 750, 150, 255, 0, 0, xPos, yPos);
		drawcircle(900, 750, 150, 255, 0, 0, xPos, yPos);
		drawcircle(1260, 750, 150, 255, 0, 0, xPos, yPos);
		drawcircle(1600, 750, 150, 255, 0, 0, xPos, yPos);
		drawcircle(180, 250, 150, 255, 0, 0, xPos, yPos);
		drawcircle(540, 250, 150, 255, 0, 0, xPos, yPos);
		drawcircle(900, 250, 150, 255, 0, 0, xPos, yPos);
		drawcircle(1260, 250, 150, 255, 0, 0, xPos, yPos);
		drawcircle(1600, 250, 150, 255, 0, 0, xPos, yPos);
		//
		for (int a = 0; a < 5; a++)  // thick line
		{
			drawLine(100, 670 - a, 260, 830 - a, 255, 0, 0);
		}
		//
		drawcircle(540, 750, 50, 255, 0, 0, 0, 0); // small circle
												   //
		drawLine(830, 820, 970, 820, 255, 0, 0); // square
		drawLine(830, 680, 970, 680, 255, 0, 0);
		for (int a = 0; a < 141; a++)
		{
			drawPixel(830, 680 + a, 255, 0, 0);
			drawPixel(970, 680 + a, 255, 0, 0);
		}
		//
		drawLine(1190, 820, 1330, 680, 255, 0, 0);   //x figure
		drawLine(1190, 680, 1330, 820, 255, 0, 0);
		//
		for (int a = 0; a < 151; a++)  // down figure
		{
			drawPixel(1600, 680 + a, 255, 0, 0);
		}
		drawLine(1550, 730, 1600, 680, 255, 0, 0);
		drawLine(1600, 680, 1650, 730, 255, 0, 0);
		//
		for (int a = 0; a < 151; a++)  // 180 , 250
		{
			drawPixel(100 + a, 250, 255, 0, 0);
		}
		drawLine(200, 300, 250, 250, 255, 0, 0);
		drawLine(200, 200, 250, 250, 255, 0, 0);
		// 540 . 250
		for (int a = 0; a < 5; a++)  // A figure
		{
			drawLine(490, 200 + a, 540, 300 + a, 255, 0, 0);
		}

		for (int a = 0; a < 5; a++)
		{
			drawLine(540, 300 + a, 590, 200 + a, 255, 0, 0);
		}
		for (int a = 0; a < 51; a++)
		{
			drawPixel(515 + a, 250, 255, 0, 0);
			drawPixel(515 + a, 249, 255, 0, 0);
		}
		// 900, 250
		for (int a = 0; a < 151; a++)  // l figure
		{
			drawPixel(900, 170 + a, 255, 0, 0);
		}
		// 1260, 250
		for (int a = 0; a < 151; a++)  // left figure
		{
			drawPixel(1190 + a, 250, 255, 0, 0);
		}
		drawLine(1190, 250, 1240, 300, 255, 0, 0);
		drawLine(1190, 250, 1240, 200, 255, 0, 0);
		//
		for (int a = 0; a < 151; a++)  // up figure
		{
			drawPixel(1600, 170 + a, 255, 0, 0);
		}
		drawLine(1550, 270, 1600, 320, 255, 0, 0);
		drawLine(1600, 320, 1650, 270, 255, 0, 0);

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete[] pixels;

	
	glfwTerminate();
	return 0;
}