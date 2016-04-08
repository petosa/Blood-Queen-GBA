//Draw background
drawImage3(0, 0, CASTLE_WIDTH, CASTLE_HEIGHT, castle);

//Draw Health
drawHealth(life);

//String at bottom
labelMessage = "Castle - Drain";
labelWidth = 92;
labelColor = STONE;

//Set spawn
spawnX = 2;
spawnY = 73;

//Move player
teleport(&me, &oldMe, spawnX, spawnY);

//Create path
pathColor = ROYAL;
numPaths = 2;
paths[0].x = 0;
paths[0].y = 50;
paths[0].w = 240;
paths[0].h = 60;

paths[1].x = 60;
paths[1].y = 30;
paths[1].w = 133;
paths[1].h = 100;

//Create Bounds
numBounds = 7;
bounds[0].x = 0;
bounds[0].y = 0;
bounds[0].w = 60;
bounds[0].h = 50;
bounds[0].vis = 0;

bounds[1].x = 0;
bounds[1].y = 0;
bounds[1].w = 1;
bounds[1].h = 160;
bounds[1].vis = 0;

bounds[2].x = 0;
bounds[2].y = 130;
bounds[2].w = 240;
bounds[2].h = 30;
bounds[2].vis = 0;

bounds[3].x = 0;
bounds[3].y = 110;
bounds[3].w = 60;
bounds[3].h = 50;
bounds[3].vis = 0;

bounds[4].x = 0;
bounds[4].y = 0;
bounds[4].w = 240;
bounds[4].h = 30;
bounds[4].vis = 0;

bounds[5].x = 193;
bounds[5].y = 0;
bounds[5].w = 60;
bounds[5].h = 50;
bounds[5].vis = 0;

bounds[6].x = 193;
bounds[6].y = 110;
bounds[6].w = 60;
bounds[6].h = 50;
bounds[6].vis = 0;


//Enemy creation
numEnemies = 5;

enemies[0].x = 125;
enemies[0].y = 78;
enemies[0].size = 3;
enemies[0].type = 'g';
enemies[0].color = GOO;
enemies[0].meta[0] = -1;
enemies[0].meta[1] = 30;
enemies[0].meta[2] = enemies[0].meta[1];
enemies[0].meta[3] = 9;
enemies[0].meta[4] = 1;

enemies[1].x = 110;
enemies[1].y = 115;
enemies[1].size = 5;
enemies[1].type = 'g';
enemies[1].color = BLUE;
enemies[1].meta[0] = -1;
enemies[1].meta[1] = 10;
enemies[1].meta[2] = enemies[1].meta[1];
enemies[1].meta[3] = 6;
enemies[1].meta[4] = 1;

enemies[2].x = 80;
enemies[2].y = 55;
enemies[2].size = 35;
enemies[2].type = 'g';
enemies[2].color = FLAME;
enemies[2].meta[0] = 1;
enemies[2].meta[1] = 10;
enemies[2].meta[2] = enemies[2].meta[1];
enemies[2].meta[3] = 8;
enemies[2].meta[4] = 1;

enemies[3].x = 180;
enemies[3].y = 55;
enemies[3].size = 35;
enemies[3].type = 'g';
enemies[3].color = FLARE;
enemies[3].meta[0] = 1;
enemies[3].meta[1] = 10;
enemies[3].meta[2] = enemies[3].meta[1];
enemies[3].meta[3] = 6;
enemies[3].meta[4] = 1;

enemies[4].x = 160;
enemies[4].y = 55;
enemies[4].size = 15;
enemies[4].type = 'g';
enemies[4].color = FLASH;
enemies[4].meta[0] = -1;
enemies[4].meta[1] = 10;
enemies[4].meta[2] = enemies[4].meta[1];
enemies[4].meta[3] = 8;
enemies[4].meta[4] = 1;


drawPaths(paths, numPaths, pathColor);
drawBounds(bounds, numBounds);

//Draw text
drawRect(146,0,14,labelWidth,BLACK);
drawString(150, 3, labelMessage, labelColor);

//Change state
state = STAGE8_IDLE;