
#ifndef _STRUCT_H_
#define _STRUCT_H_

struct Ball(){
long x;
long y;
long vx;
long vy;
}

struct Player(){
long x;
long y;
int points;
char lifes;
}

struct Block(){
char lifes;
char x;
char y;
}

struct Level(){
struct block blocks[128];
int lifes;
char lvl;
char wall[4];
}
#endif /*_STRUCT_H_*/