#include "chaosClass.h"


ChaosBall::ChaosBall(Region map, Coordinate position):Ball(map,position)
{}

char ChaosBall::getSymbol() {
	return '#';
}
void ChaosBall::bounceHorizontally() {
	/*if (ChaosBall::getVelocity().X > 0) {
		if (utility::Random::getInteger(0, 1))
			Ball::bounceHorizontally();
		else
			Ball::bounceVertically();
	}
	Ball::bounceHorizontally();*/

	
		if (utility::Random::getInteger(0, 1))
			Ball::bounceHorizontally();
		else {
			Ball::bounceHorizontally();
			Ball::bounceVertically();
		}
	
}
void ChaosBall::bounceVertically() {
	/*if (ChaosBall::getVelocity().X > 0) {
		if (utility::Random::getInteger(0, 1))
			Ball::bounceHorizontally();
		else
			Ball::bounceVertically();
	}
	Ball::bounceHorizontally();*/


	if (utility::Random::getInteger(0, 1))
		Ball::bounceVertically();
	else {
		
		Ball::bounceVertically();
		Ball::bounceHorizontally();
	}

}