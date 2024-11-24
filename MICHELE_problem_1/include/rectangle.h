#pragma once
#include "../include/shape.h"
#include "../include/rectangle.h"

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(int value);
	~Rectangle();
	void draw();
};
