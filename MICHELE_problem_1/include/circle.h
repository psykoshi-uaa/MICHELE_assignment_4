#pragma once
#include "../include/shape.h"
#include "../include/circle.h"

class Circle : public Shape
{
public:
	Circle();
	Circle(int value);
	~Circle();
	void draw();
};
