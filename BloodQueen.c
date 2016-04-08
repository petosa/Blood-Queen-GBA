#include <stdlib.h>
#include <stdio.h>
#include "myLib.h"
#include "text.h"
#include "title.h"
#include "grass.h"
#include "castle.h"
#include "player1.h"
#include "gameover.h"
#include "heart.h"
#include "portal.h"
#include "tree.h"
#include "palacecut.h"
#include "forestcut.h"
#include "portalcut.h"
#include "castlecut.h"
#include "castledoor.h"
#include "throne.h"
#include "bosscut.h"

int main()
{
	//Set mode and BG
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	// State enum definition
	enum GBAState {
		START,
		START_IDLE,
		STAGE1,
		STAGE1_IDLE,
		STAGE2,
		STAGE2_IDLE,
		STAGE3,
		STAGE3_IDLE,
		STAGE4,
		STAGE4_IDLE,
		STAGE5,
		STAGE5_IDLE,
		STAGE6,
		STAGE6_IDLE,
		STAGE7,
		STAGE7_IDLE,
		STAGE8,
		STAGE8_IDLE,
		STAGE9,
		STAGE9_IDLE,
		STAGE10,
		STAGE10_IDLE,
		STAGE11,
		STAGE11_IDLE,
		STAGE12,
		STAGE12_IDLE,
		STAGE13,
		STAGE13_IDLE,
		STAGE14,
		STAGE14_IDLE,
		GAMEOVER,
		GAMEOVER_IDLE,
		FOREST,
		PORTAL,
		CASTLE,
		PALACE,
		BOSS
	};

	//Current state
	enum GBAState state = START;

	//Key press boolean
	int selectPressed = 0;

	//If true, player is in a stage
	int inGame = 0;

	//Spawn data, where player starts and jumps to on death
	int spawnX = 0;
	int spawnY = 0;

	//Structs
	PLAYER me;
	PLAYER oldMe; //Needed for repainting
	PATH paths[32]; //You can have up to 32 paths per stage
	BOUND bounds[32]; //You can have up to 32 bounds per stage
	ENEMY enemies[32]; //You can have up to 32 enemies per stage

	//Struct variables
	int numPaths = 0;
	int numBounds = 0;
	int numEnemies = 0;
	u16 pathColor = BLACK;
	char* labelMessage = "";
	int labelWidth = 0;
	u16 labelColor = BLACK;
		
	//Init player objects offscreen
	me.size = 15;
	me.x = -me.size;
	me.y = -me.size;
	oldMe.x = -me.size;
	oldMe.y = -me.size;

	//Declare a local instance of the extern
	int life = 0;

	//Game loop
	while(1)
	{
		waitForVblank();

		//State machine
		switch(state) {

			//START State
			case START:
			//Reset
			inGame = 0;
			life = 99;
			//Set offscreen in the case you are coming from another state
			me.x = -me.size;
			me.y = -me.size;
			oldMe.x = -me.size;
			oldMe.y = -me.size;
			//Draw graphic
			drawImage3(0, 0, TITLE_WIDTH, TITLE_HEIGHT, title);
			//Change state
			state = START_IDLE;
			break;
			
			//Idle START state
			case START_IDLE:
			//Advance on START
			if(KEY_DOWN_NOW(BUTTON_START)) {
				state = FOREST;
			}
			break;

			//STAGE1 State
			case STAGE1:
			//Player is now inGame
			#include "stage1.h"
			break;
			
			//Idle STAGE1 state
			case STAGE1_IDLE:
			if(me.x + me.size == 240)
				state = STAGE2;
			break;

			//STAGE2 State
			case STAGE2:
			#include "stage2.h"
			break;

			//Idle STAGE2 state
			case STAGE2_IDLE:
			if(me.x + me.size == 240)
				state = STAGE3;
			break;

			//STAGE3 State
			case STAGE3:
			#include "stage3.h"
			break;

			//Idle STAGE3 state
			case STAGE3_IDLE:
			if(me.x + me.size == 240)
				state = STAGE4;
			break;

			//STAGE4 State
			case STAGE4:
			#include "stage4.h"
			break;

			//Idle STAGE4 state
			case STAGE4_IDLE:
			if(me.x + me.size == 240)
				state = STAGE5;
			break;

			//STAGE5 State
			case STAGE5:
			#include "stage5.h"
			break;

			//Idle STAGE5 state
			case STAGE5_IDLE:
			if(me.x + me.size == 200 && me.y < 80)
				state = PORTAL;
			if(me.x + me.size == 230 && me.y > 80)
				state = CASTLE;
			break;

			//STAGE6 State
			case STAGE6:
			#include "stage6.h"
			break;

			//Idle STAGE6 state
			case STAGE6_IDLE:
			if(me.x + me.size == 240)
				state = STAGE7;
			break;

			//STAGE7 State
			case STAGE7:
			#include "stage7.h"
			break;

			//Idle STAGE7 state
			case STAGE7_IDLE:
			if(me.x + me.size == 240)
				state = STAGE8;
			break;

			//STAGE8 State
			case STAGE8:
			#include "stage8.h"
			break;

			//Idle STAGE8 state
			case STAGE8_IDLE:
			if(me.x + me.size == 240)
				state = STAGE9;
			break;

			//STAGE9 State
			case STAGE9:
			#include "stage9.h"
			break;

			//Idle STAGE9 state
			case STAGE9_IDLE:
			if(me.x + me.size == 240)
				state = STAGE10;
			break;

			//STAGE10 State
			case STAGE10:
			#include "stage10.h"
			break;

			//Idle STAGE10 state
			case STAGE10_IDLE:
			if(me.x + me.size == 240)
				state = PALACE;
			break;

			//STAGE11 State
			case STAGE11:
			#include "stage11.h"
			break;

			//Idle STAGE11 state
			case STAGE11_IDLE:
			if(me.x + me.size == 240)
				state = STAGE12;
			break;

			//STAGE12 State
			case STAGE12:
			#include "stage12.h"
			break;

			//Idle STAGE12 state
			case STAGE12_IDLE:
			if(me.x + me.size == 240)
				state = STAGE13;
			break;

			//STAGE13 State
			case STAGE13:
			#include "stage13.h"
			break;

			//Idle STAGE13 state
			case STAGE13_IDLE:
			if(me.x + me.size == 240)
				state = STAGE14;
			break;

			//STAGE14 State
			case STAGE14:
			#include "stage14.h"
			break;

			//Idle STAGE14 state
			case STAGE14_IDLE:
			if(me.x + me.size == 240)
				state = BOSS;
			break;			

			//GAMEOVER State
			case GAMEOVER:
			inGame = 0;
			drawImage3(0, 0, GAMEOVER_WIDTH, GAMEOVER_HEIGHT, gameover);
			drawString(150, 3, "Press A to restart", WHITE);
			state = GAMEOVER_IDLE;
			break;

			//Idle GAMEOVER state
			case GAMEOVER_IDLE:
			if(KEY_DOWN_NOW(BUTTON_A))
				state = START;
			break;

			//Forest cutscene
			case FOREST:
			inGame = 0;
			drawImage3(0, 0, FORESTCUT_WIDTH, FORESTCUT_HEIGHT, forestcut);
			if(KEY_DOWN_NOW(BUTTON_A)) {
				state = STAGE1;
				inGame = 1;
			}
			break;

			//Castle cutscene
			case CASTLE:
			inGame = 0;
			drawImage3(0, 0, CASTLECUT_WIDTH, CASTLECUT_HEIGHT, castlecut);
			if(KEY_DOWN_NOW(BUTTON_A)) {
				state = STAGE6;
				inGame = 1;
			}
			break;

			//Palace cutscene
			case PALACE:
			inGame = 0;
			drawImage3(0, 0, PALACECUT_WIDTH, PALACECUT_HEIGHT, palacecut);
			if(KEY_DOWN_NOW(BUTTON_A)) {
				state = STAGE11;
				inGame = 1;
			}
			break;

			//Portal cutscene
			case PORTAL:
			inGame = 0;
			drawImage3(0, 0, PORTALCUT_WIDTH, PORTALCUT_HEIGHT, portalcut);
			if(KEY_DOWN_NOW(BUTTON_A)) {
				state = STAGE11;
				inGame = 1;
			}
			break;

			//Boss cutscene
			case BOSS:
			inGame = 0;
			drawImage3(0, 0, BOSSCUT_WIDTH, BOSSCUT_HEIGHT, bosscut);
			drawString(150, 3, "To be continued?", WHITE);
			if(KEY_DOWN_NOW(BUTTON_A)) {
				state = START;
				inGame = 0;
			}
			break;

		}

		//Stage painter
		if(inGame) {

			//Draw the old player
			drawRect(oldMe.y,oldMe.x,me.size,me.size,pathColor);
			//Draw the player
			drawTransparent(me.y, me.x, me.size, me.size, player1);

			//Update old player position
			oldMe.x = me.x;
			oldMe.y = me.y;

			//Collision Detection
			unsigned char mov = getMovementData(me.x, me.y, me.size, bounds, numBounds);

			//Enemy logic
			int r = enemyLogic(enemies, numEnemies, me, pathColor);
			if(r) {
				life--;
				if(life == 0)
					state = GAMEOVER;
				me.x = spawnX;
				me.y = spawnY;
				drawHealth(life);
			}

			//Key UP ARROW listener
			if(KEY_DOWN_NOW(BUTTON_UP))
			{
				if(mov & 1)
				me.y--;
			}
			//Key DOWN ARROW listener
			if(KEY_DOWN_NOW(BUTTON_DOWN))
			{
				if(mov & 2)
					me.y++;
			}
			//Key RIGHT ARROW listener
			if(KEY_DOWN_NOW(BUTTON_RIGHT))
			{
				if(mov & 4)
					me.x++;
			}
			//Key LEFT ARROW listener
			if(KEY_DOWN_NOW(BUTTON_LEFT))
			{
				if(mov & 8)
					me.x--;
			}
		}

		//Reset the game on select
		if(KEY_DOWN_NOW(BUTTON_SELECT) && !selectPressed){
			state = START;
			selectPressed = 1;
		} else {
			selectPressed = 0;
		}

	}
	
}

