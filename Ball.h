#pragma once
#include "Region.h"
#include "Coordinate.h"
class Ball
{
private:
	Region map;
	Coordinate position;
	Coordinate velocity;
public:
	Ball(Region, Coordinate, Coordinate);
	Ball(Region, Coordinate);
	Coordinate getPosition();
	Coordinate getVelocity();
	Coordinate getTargetPosition();
	void move();
	virtual void bounceHorizontally();
	virtual void bounceVertically();
	virtual char getSymbol();
private:
	void setPosition(Coordinate);
};

