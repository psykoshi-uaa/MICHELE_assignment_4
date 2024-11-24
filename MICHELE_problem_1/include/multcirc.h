#pragma once
#include "../include/shape.h"
#include "../include/multcirc.h"

class MultCirc : public Shape
{
public:
	MultCirc();
	MultCirc(int value);
	~MultCirc();
	void draw();
};
