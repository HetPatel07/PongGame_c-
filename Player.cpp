#include "Player.h"

Player::Player(int score)
	:score(score)
{

}
void Player::updateScore() {
	score++;
}

int Player::getScore() {
	return score;
}