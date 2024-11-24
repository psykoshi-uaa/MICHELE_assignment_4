#include "../include/shape.h"
#include "GL/glut.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include <cstdlib>
#include <cmath>
using namespace std;


Shape::Shape()
{
	// By default, make this a circle of radius 20 pixels
	radius = 20;

	// Start at a random position and speed
	x = (float)(rand() % WIDTH);
	y = (float)(rand() % HEIGHT);
	deltaX = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
	deltaY = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
}

Shape::Shape(int value)
{
	// Start at a random position and speed
	x = (float)(rand() % WIDTH);
	y = (float)(rand() % HEIGHT);
	deltaX = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
	deltaY = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
}


Shape::~Shape()
{
}

// This function draws the shape
void Shape::draw()
{
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(x, y);
	glVertex2f(x + radius, y + radius);
	glVertex2f(x + radius, y);
	glVertex2f(x, y + radius);
	glEnd();
}

// This function updates the location of the shape, by adding in deltaX to the x coordinate
// and deltaY to the y coordinate.  Since the delta's can be negative this allows for moving
// up or down.
// If the center of the ball goes off the edge of the screen, reverse the direction.
void Shape::updateCoordinates()
{
	x += deltaX;
	y += deltaY;

	// Check if we hit the edge of the screen and if we did
	// move it back so it fits and then change the direction
	if (x >= WIDTH)
	{
		x -= deltaX;
		// deltaX is positive, so make it negative
		deltaX *= -1;
	}
	else if (x < 0)
	{
		deltaX *= -1;    // deltaX is negative, so make it positive
		x += deltaX;    // add it in so we are not off the edge
	}
	if (y >= HEIGHT)
	{
		y -= deltaY;  // Same for the Y directions
		deltaY *= -1;
	}
	else if (y < 0)
	{
		deltaY *= -1;
		y += deltaY;
	}
}
