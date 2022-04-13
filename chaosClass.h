#pragma once
#include "Ball.h"
#include "Random.h"

class ChaosBall : public Ball
{
public:
	ChaosBall(Region map, Coordinate position);
	char getSymbol() override;
	void bounceHorizontally() override;
	void bounceVertically() override;
};

