#include "myLib.h"
#include <stdio.h>
#include "text.h"
#include "heart.h"

//Draw all paths in the passed in array
void drawPaths(PATH *paths, int numPaths, short pathColor) {
	for(int i = 0; i < numPaths; i++) {
		drawRect(paths[i].y,paths[i].x,paths[i].h,paths[i].w,pathColor);
	}
}

//Establish all bounds in the passed in array
void drawBounds(BOUND *bounds, int numBounds) {
	for(int i = 0; i < numBounds; i++) {
		if (bounds[i].vis == 1)
		drawRect(bounds[i].y,bounds[i].x,bounds[i].h,bounds[i].w,BOAR);
	}
}

//Returns a char representing which direction movement is allowed based off of collision.
unsigned char getMovementData(int x, int y, int size, BOUND bounds[], int numBounds) {
	//Numbers necessary to turn on 1st, 2nd, 3rd, and 4th bit of a byte
	short u = 1;
	short d = 2;
	short r = 4;
	short l = 8;
	//Check all bounds for edge collisions, and turn of a bit if there is such a violation
	for(int i = 0; i < numBounds; i++) {
		BOUND b = bounds[i];
		if(y == b.y + b.h && x + size >= b.x && x <= b.x + b.w)
		u = 0;
		if(y + size == b.y && x + size >= b.x && x <= b.x + b.w) 
		d = 0;
		if(x + size == b.x && y + size >= b.y && y <= b.y + b.h) 
		r = 0;
		if(x == b.x + b.w && y + size >= b.y && y <= b.y + b.h)  
		l = 0;
	}
	//Return result char
	unsigned char ret = u | d | r | l;
	return ret;
}

//Updates health
void drawHealth(int l) {
	drawRect(146,210,14,30, BLACK);
	drawImage3(149, 228, 10, 10, heart);
	char liveString[10];
	sprintf(liveString, "%d", l);
	drawString(150, 213, liveString, RED);
}

int enemyLogic(ENEMY enemies[], int numEnemies, PLAYER p, u16 pathColor) {

//////Enemy logic//////
//
// Return 1 if player is hit.
//
// ~~~ v - VERTICAL PATROLLER ~~~
// Moves up and down the screen
// METADATA
// [0]: Initial direction
// [1]: Pixels per direction
// [2]: Used to count down, must = [1] to start
// [3]: Speed
//
// ~~~ h - HORIZONTAL PATROLLER ~~~
// Moves up and down the screen
// METADATA
// [0]: Initial direction
// [1]: Pixels per direction
// [2]: Used to count down, must = [1] to start
// [3]: Speed
//
// ~~~ g - GROWER ~~~
// Moves up and down the screen
// METADATA
// [0]: Initial direction
// [1]: Pixels to expand
// [2]: Used to count down, must = [1] to start
// [3]: Speed out of 10
// [4]: Flip-flop, used to slow down motion - don't touch

int ret = 0;
for(int i = 0; i < numEnemies; i++) {
	//Alias
	ENEMY e = enemies[i];

	//Vertical patroller type
	if (e.type == 'v') {
		e.meta[2]-=e.meta[3]; //count down
		if(e.meta[2] <= 0) { //reached 0
			e.meta[2] = e.meta[1]; //reset timer
			e.meta[0] = -e.meta[0]; //change direction
		}
		//Draw old rectangle to cover trail
		drawRect(e.y,e.x,e.size,e.size,pathColor);
		//Decide which direction to go and move
		if(e.meta[0] > 0) {
			e.y-=e.meta[3];
		} else {
			e.y+=e.meta[3];
		}
		//Draw enemy
		drawRect(e.y,e.x,e.size,e.size,e.color);

	//Horizontal patroller type
	} else if (e.type == 'h') {
		e.meta[2]-=e.meta[3];
		if(e.meta[2] <= 0) {
			e.meta[2] = e.meta[1];
			e.meta[0] = -e.meta[0];
		}
		//Draw old rectangle to cover trail
		drawRect(e.y,e.x,e.size,e.size,pathColor);
		//Decide which direction to go and move
		if(e.meta[0] > 0) {
			e.x-=e.meta[3];
		} else {
			e.x+=e.meta[3];
		}
		//Draw enemy
		drawRect(e.y,e.x,e.size,e.size,e.color);		

	//Grower type
	} else if (e.type == 'g') {
		//Frames to pause between growth
		int buffer = 10 - e.meta[3];
		if(e.meta[4] == buffer)
		e.meta[2]-=1;
		if(e.meta[2] <= 0) {
			e.meta[2] = e.meta[1];
			e.meta[0] = -e.meta[0];
		}
		//Draw old rectangle to cover trail
		drawRect(e.y,e.x,e.size,e.size,pathColor);
		//Decide which direction to go and move
		if(e.meta[0] > 0 && e.meta[4] == buffer) {
			e.size-=2;
			e.x+=1;
			e.y+=1;
			e.meta[4] = 0;
		} else if (e.meta[0] < 0 && e.meta[4] == buffer) {
			e.size+=2;
			e.x-=1;
			e.y-=1;
			e.meta[4] = 0;
		} else {
			e.meta[4]++;
		}
		//Draw enemy
		drawRect(e.y,e.x,e.size,e.size,e.color);		
	}

	//Insert updated enemy
	enemies[i] = e;

	//Check for collision
	if(p.x <= e.x && p.x + p.size >= e.x && p.y <= e.y + e.size && p.y + p.size >= e.y) {
		ret = 1;
	}
	if(p.x + p.size >= e.x && p.x <= e.x + e.size && p.y <= e.y + e.size && p.y + p.size >= e.y) {
		ret = 1;
	}

	} 
	return ret;
}


//Teleports player p to a location and updates the old player to prevent improper residue
void teleport(PLAYER* p, PLAYER* op, int x, int y) {
	p->x = x;
	p->y = y;
	op->x = x;
	op->y = y;
}
