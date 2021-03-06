#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"
#include "graphics.h"
#include "gamephysics.h"
#include "game.h"
#include "ansi.h"
#include "sinLUT.h"

// update player position using input from slider.
void updatePlayerPos(int input, struct Player* player) {
	char old_x, new_x; // holds positions for the redraw function
	int slider = (input >> 5) / 13 + 2; // Converts input to player positions
	old_x = (char) (player->x >> 16); // old position as a char

	if (slider > 3 && slider < 78)
		player->x = (long) slider << 16; //The new position of player
	else if (slider <= 3)
		player->x = 4 << 16; // prevents player from straying to the left
	else if (slider >= 78)
		player->x = 77 << 16; // prevents player from straying to the right

	new_x = (char) (player->x >> 16);

	if (new_x != old_x) // only use print if position has changed
		redrawPlayer(old_x, (char) (player->x >> 16));

}

// update ball position using ball->angle and ball->speed
// NOT using vectorRotate, but rather a polar coordinates solution
void updateBallPos(struct Ball* ball, struct Player* player) {
	char old_x;
	char old_y;
	char new_x;
	char new_y;

	old_x = (char) (ball->x >> 16);
	old_y = (char) (ball->y >> 16);

	//change in x:
	ball->x = ball->x + (((long) (cos(ball->angle)) * ball->speed) >> 14);
	//change in y:
	ball->y = ball->y + (((long) (sin(ball->angle)) * ball->speed) >> 14);

	new_x = (char) (ball->x >> 16);
	new_y = (char) (ball->y >> 16);

	if (old_x != new_x || old_y != new_y) { // only printing when there is a change
		redrawBall(old_x, old_y, new_x, new_y);
	}

}

// checking for ball collision with wall and ceiling
void checkWallCollision(struct Ball* ball, struct Level* level,
		struct Player* player) {

	// Check for Left Wall collisions
	if (ball->x < (2 << 16) + 16383) {

		ball->angle = 256 - ball->angle;
	}
	// Check for Right Wall collisions
	else if (ball->x > (80 << 16) - 16383) {
		ball->angle = 256 - ball->angle;
	}

	// Check for Top Wall collisions
	if (ball->y < (3 << 16) + 16383) {
		ball->angle = -ball->angle;
	}

	else if (ball->y > ((24 << 16))) { // Death criterium.. @ 24
		// Player Looses a Life,
		player->lifes = player->lifes - 1;
		resetLevel(player, ball, level);
		drawLevel(*ball, *player, level->blocks);
		drawTopBar(*player);
	}

}

// Player characteristics defined here!
// Player has five parts, each changes the ball->angle in a different way
void checkPlayerCollision(struct Ball* ball, struct Player* player) {

	if (ball->y > (23 << 16) - 16383) {

		// If hit section 1, change direction
		if ((ball->x >> 16) >= (player->x >> 16) - 2
				&& (ball->x >> 16) < (player->x >> 16) - 1)
			ball->angle = -ball->angle - 2 * 32;

		// If hit section 2, change direction
		if ((ball->x >> 16) >= (player->x >> 16) - 1
				&& (ball->x >> 16) < (player->x >> 16))
			ball->angle = -ball->angle - 2 * 16;

		// If hit section 3, change direction
		if ((ball->x >> 16) >= (player->x >> 16)
				&& (ball->x >> 16) < (player->x >> 16) + 1)
			ball->angle = -ball->angle;

		// If hit section 4, change direction
		if ((ball->x >> 16) >= (player->x >> 16) + 1
				&& (ball->x >> 16) < (player->x >> 16) + 2)
			ball->angle = -ball->angle + 2 * 16;

		// If hit section 5, change direction
		if ((ball->x >> 16) >= (player->x >> 16) + 2
				&& (ball->x >> 16) < (player->x >> 16) + 3)
			ball->angle = -ball->angle + 2 * 32;

		// Makes the the angle positive.
		ball->angle &= 0x1FF;

		// If hit, move ball a bit up.
		if ((ball->x >> 16) >= (player->x >> 16) - 2
				&& (ball->x >> 16) < (player->x >> 16) + 3) {

			if (ball->angle < 288 && ball->angle > 128)
				ball->angle = 288; // Corrects balls with wrong angle to the left
			else if (ball->angle > 480 || ball->angle < 128)
				ball->angle = 480; // Corrects ball with wrong angle to the right.

			updateBallPos(ball, player);
		}
	}
}

void checkBlockCollision(struct Ball* ball, struct Level* level,
		struct Player* player) {
	int i;
	char hit;
	struct Block* blocks = level->blocks;

	for (i = 0; i < 64; i++) {
		if (blocks[i].lifes > 0) {
			hit = 0;

			// Check if ball hits from either side
			if ((ball->x > ((long) blocks[i].x << 16) - 16383)
					&& (ball->y > ((long) blocks[i].y << 16))
					&& (ball->x < (((long) blocks[i].x + 3) << 16) + 16383)
					&& (ball->y < (((long) blocks[i].y + 1) << 16))) {

				ball->angle = -ball->angle + 256;
				hit = 1;
			}

			// Check if ball hits from top or bottom
			if ((ball->x > ((long) blocks[i].x << 16))
					&& (ball->y > ((long) blocks[i].y << 16) - 16383)
					&& (ball->x < (((long) blocks[i].x + 3) << 16))
					&& (ball->y < (((long) blocks[i].y + 1) << 16) + 16383)) {
				ball->angle = -ball->angle;
				hit = 1;
			}

			if (hit == 1) {
				updateBallPos(ball, player);

				blocks[i].lifes--;
				drawBlock(blocks[i]);
				level->lifes--;

				player->points++;
				drawTopBar(*player);
			}

		}
	} // end of for  loop
}

void updatePositions(int input, struct Player* player, struct Ball* ball) {
	updatePlayerPos(input, player);
	updateBallPos(ball, player);
}

void testForCollisions(struct Player* player, struct Ball* ball,
		struct Level* level) {
	checkWallCollision(ball, level, player);
	checkPlayerCollision(ball, player);
	checkBlockCollision(ball, level, player);
}

