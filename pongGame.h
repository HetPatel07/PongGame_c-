#pragma once
#include "ConsoleReader.h"
#include "ConsoleWriter.h"
#include "Region.h"
#include "Paddle.h"
#include "Ball.h"
#include "Player.h"
#include "chaosClass.h"
using namespace utility;

class PongGame
{
private:
	ConsoleReader reader;
	ConsoleWriter writer;
	Region map;
	Ball ball;
	ChaosBall chaosBall;
	Paddle leftPaddle;
	Paddle rightPaddle;
	Player leftPlayer;
	Player rightPlayer;
	bool temp;
	//Region walls;


public:
	PongGame();

	void start();

private:
	void eraseObjects();
	void handleInput();
	void updateObjects();
	void  displayObjects();
};