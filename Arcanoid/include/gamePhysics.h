#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   

#include "struct.h"

#ifndef _GAMEPHYSICS_H_
#define _GAMEPHYSICS_H_

void updatePlayerPos(int input, struct Player* player);
void updateBallPos(struct Ball* ball, struct Player* player);
void checkWallCollision(struct Ball* ball, struct Level* level, struct Player* player);
void checkPlayerCollision(struct Ball* ball, struct Player* player);
void checkBlockCollision(struct Ball* ball, struct Level* level, struct Player* player);
void updatePositions(int input, struct Player* player, struct Ball* ball);
void testForCollisions(struct Player* player, struct Ball* ball, struct Level* level);

#endif /*_GAMEPHYSICS_H_*/
