#include "../include/multcirc.h"
#include "GL/glut.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include <cstdlib>
#include <cmath>

MultCirc::MultCirc() : Shape()
{
	this->radius = 20;
}

MultCirc::MultCirc(int value) : Shape()
{
	this->radius = value;
}

void MultCirc::draw()
{
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f(x + sin(angle) * radius, y + cos(angle) * radius);
	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f(x + sin(angle) * radius*2.0 / 3, y + cos(angle) * radius*2.0 / 3);
	}
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f(x + sin(angle) * radius*1.0 / 3, y + cos(angle) * radius*1.0 / 3);
	}
	glEnd();
}
