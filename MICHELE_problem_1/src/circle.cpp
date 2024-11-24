#include "../include/circle.h"
#include "GL/glut.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include <cstdlib>
#include <cmath>

Circle::Circle() : Shape()
{
	this->radius = 20;
}

Circle::Circle(int value) : Shape()
{
	this->radius = value;
}

void Circle::draw()
{
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f(x + sin(angle) * radius, y + cos(angle) * radius);
	}
	glEnd();
}
