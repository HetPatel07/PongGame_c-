#include "PongGame.h"

PongGame::PongGame()
	: reader(),
	writer(),
	map(Coordinate(1, 1), Coordinate(50, 20)),
	leftPaddle(Paddle(4, Coordinate(4, 6), map)),
	// TODO: Initialize leftPaddle
	rightPaddle(Paddle(4, Coordinate(46, 6), map)),
	ball(map, Coordinate(25 , 10)),
	chaosBall(map, Coordinate(5, 1)),
	leftPlayer(0),
	rightPlayer(0),
	temp(true)
{
	//writer.fillRegion('/', map.getLeft(), map.getTop(), map.getRight(), map.getBottom());
}

void PongGame::start()
{
	// Initialize  
	writer.drawRectangle(map.getTopLeft() - Coordinate(1, 1), map.getBottomRight() + Coordinate(1, 1));
	int c = 0;
	while (temp)
	{
		c++;
		eraseObjects();
		handleInput();
		updateObjects();
		displayObjects();
		Sleep(100);
		if (c == 30) {
			temp = false;
		}
	}
	writer.clearRegion(Coordinate(0, 0), Coordinate(50, 20));
	writer.write("you have won game");
	writer.write(leftPlayer.getScore());

}

void PongGame::eraseObjects()
{
	// Use writer to erase previous right paddle from console
	writer.clearRegion(map.getLeft() + 4, leftPaddle.getTop(), map.getLeft() + 4, leftPaddle.getBottom());
	writer.clearRegion(map.getRight() - 4, rightPaddle.getTop(), map.getRight() - 4, rightPaddle.getBottom());
	writer.clearRegion(ball.getPosition(), ball.getPosition());

	writer.clearRegion(chaosBall.getPosition(), chaosBall.getPosition());
}

void PongGame::handleInput()
{
	
	// Use reader to check up/down arrow keys
	if (reader.isUpArrowPressed()) {
		/*leftPaddle = Paddle(4, Position(4 , leftPaddle.getBottom() - 1), map);*/
		rightPaddle.setPosition(rightPaddle.getBottom() - 1);
	}
	else if (reader.isDownArrowPressed()) {
		rightPaddle.setPosition(rightPaddle.getBottom() + 1);
	}
	// If up/down is pressed, then set right paddle position

	if (reader.isKeyPressed('W')) {
		/*leftPaddle = Paddle(4, Position(4 , leftPaddle.getBottom() - 1), map);*/
		leftPaddle.setPosition(leftPaddle.getBottom() - 1);
	}
	else if (reader.isKeyPressed('S')) {
		leftPaddle.setPosition(leftPaddle.getBottom() + 1);
	}
}

void PongGame::updateObjects()
{
	// Normal Ball
	if ((ball.getTargetPosition().X == rightPaddle.getPosition().X) &&
		(ball.getTargetPosition().Y >= rightPaddle.getTop() && ball.getTargetPosition().Y <= rightPaddle.getBottom()) &&
		(ball.getPosition().X < rightPaddle.getPosition().X))
	{
		temp = false;
		start();
		ball.bounceHorizontally();
	}

	if ((ball.getTargetPosition().X == leftPaddle.getPosition().X) &&
		(ball.getTargetPosition().Y >= leftPaddle.getTop() && ball.getTargetPosition().Y <= leftPaddle.getBottom()) &&
		(ball.getPosition().X > leftPaddle.getPosition().X))
	{
		temp = false;
		start();
		ball.bounceHorizontally();
	}
	ball.move();
	

	if (ball.getPosition().X == map.getRight()) {
		leftPlayer.updateScore();
	}
	if (ball.getPosition().X == map.getLeft()) {
		rightPlayer.updateScore();
	}

	// Chaos Ball

	if ((chaosBall.getTargetPosition().X == rightPaddle.getPosition().X) &&
		(chaosBall.getTargetPosition().Y >= rightPaddle.getTop() && chaosBall.getTargetPosition().Y <= rightPaddle.getBottom()) &&
		(chaosBall.getPosition().X < rightPaddle.getPosition().X))
	{
		chaosBall.bounceHorizontally();
	}

	if ((chaosBall.getTargetPosition().X == leftPaddle.getPosition().X) &&
		(chaosBall.getTargetPosition().Y >= leftPaddle.getTop() && chaosBall.getTargetPosition().Y <= leftPaddle.getBottom()) &&
		(chaosBall.getPosition().X > leftPaddle.getPosition().X))
	{
		chaosBall.bounceHorizontally();
	}
	chaosBall.move();


	if (chaosBall.getPosition().X == map.getRight()) {
		temp = false;
		leftPlayer.updateScore();
	}
	if (chaosBall.getPosition().X == map.getLeft()) {
		temp = false;
		rightPlayer.updateScore();
	}
		
}

void PongGame::displayObjects()
{	
	writer.fillRegion('L', map.getLeft() + 4, leftPaddle.getTop(), map.getLeft() + 4, leftPaddle.getBottom());
	writer.fillRegion('R', map.getRight() - 4, rightPaddle.getTop(), map.getRight() - 4, rightPaddle.getBottom());
	writer.fillRegion(ball.getSymbol(), ball.getPosition(), ball.getPosition());
	writer.fillRegion(chaosBall.getSymbol(), chaosBall.getPosition(), chaosBall.getPosition());
	// Use writer to draw right paddle in the console

	writer.setCursorPosition(0, 22);
	writer.writeLine("Left player score : ");
	writer.setCursorPosition(0, 24);
	writer.writeLine(leftPlayer.getScore());

	writer.setCursorPosition(28, 22);
	writer.writeLine("Right player score : ");
	writer.setCursorPosition(28, 24);
	writer.writeLine(rightPlayer.getScore());

	
}
