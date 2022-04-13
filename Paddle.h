#pragma once
#include "Coordinate.h"
#include "Region.h"
using namespace utility;
class Paddle
{
private:

	int height;
	Coordinate position;
	Region map;

public:
	// Constructor
	Paddle(int height, Coordinate position, Region map);
	Coordinate getPosition();
	// Get position
	
	int getHeight();
	// Get height
	
	int getTop();
	// Get top
	
	int getBottom();
	// Get bottom

	void setPosition(int);
	// Set position

	int validateHeight(int);
};
