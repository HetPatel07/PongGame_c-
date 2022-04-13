#include "Paddle.h"

Paddle::Paddle(int height, Coordinate position, Region map)
	: height(height), position(position), map(map)
{
	if(getTop() < map.getTop()){
		setPosition(map.getTop());
	}
	if (getBottom() > map.getBottom()) {
		setPosition(map.getBottom());
	}
}

Coordinate Paddle::getPosition()
{
	return position;
}

int Paddle::getHeight()
{
	return height;
}

int Paddle::getTop()
{
	
	return position.Y - getHeight();
}

int Paddle::getBottom()
{
	return position.Y;
}

void Paddle::setPosition(int y)
{
	if (y - getHeight() >= map.getTop() && y <= map.getBottom()) {
		position = Coordinate(position.X, y);
		//position = Coordinate(position.X, map.getTop());
	}
	/*else if (getBottom() > map.getBottom()) {
		position = Coordinate(position.X, map.getBottom());
	}*/
	
}
