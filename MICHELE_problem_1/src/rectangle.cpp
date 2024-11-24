#include "../include/rectangle.h"
#include "GL/glut.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include <cstdlib>
#include <cmath>

Rectangle::Rectangle() : Shape()
{
	this->diameter = 20;
}

Rectangle::Rectangle(int value) : Shape()
{
	this->diameter = value;
}

void Rectangle::draw(){	
	glColor3f(1, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(x - (diameter / 2), y - (diameter / 2));
	glVertex2f(x + (diameter / 2), y - (diameter / 2));
	glVertex2f(x + (diameter / 2), y + (diameter / 2));
	glVertex2f(x - (diameter / 2), y + (diameter / 2));
	glEnd();
}


