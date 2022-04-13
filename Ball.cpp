#include "Ball.h"

Ball::Ball(Region map, Coordinate position)
	: Ball::Ball(map, position, Coordinate(1, 1))
{}
Ball::Ball(Region map, Coordinate position, Coordinate velocity)
	:map(map),
	position(position),
	velocity(velocity)
{
	if (position.X < map.getLeft()) {
		position.X = map.getLeft();
	}
	else if (position.X > map.getRight()) {
		position.X = map.getRight();
	}

	if (position.Y < map.getTop()) {
		position.Y = map.getTop();
	}
	else if (position.Y > map.getBottom()) {
		position.Y = map.getBottom();
	}
}

Coordinate Ball::getPosition() {
	return position;
}
Coordinate Ball::getVelocity() {
	return velocity;
}
Coordinate Ball::getTargetPosition() {
	//std::cout << (position + velocity).toString() << std::endl;
	
 	return position + velocity;
}
void Ball::bounceHorizontally() {
	if(velocity.X > 0)
		velocity.X = -1;
	else
		velocity.X = 1;
}	
void Ball::bounceVertically() {
	if (velocity.Y > 0)
		velocity.Y = -1;
	else
		velocity.Y = 1;
}
void Ball::move() {

	setPosition(getTargetPosition());
}
void Ball::setPosition(Coordinate position) {

	if (position.X == map.getLeft() || position.X == map.getRight()) {
		bounceHorizontally();
	}
	if (position.Y == map.getTop() || position.Y == map.getBottom()) {
		bounceVertically();
	} 
	
	this->position = position;
}

char Ball::getSymbol() {
	return 'o';
}