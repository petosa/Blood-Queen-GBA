//Draw background
drawImage3(0, 0, CASTLE_WIDTH, CASTLE_HEIGHT, castle);

//Draw Health
drawHealth(life);

//String at bottom
labelMessage = "Castle - Corridor";
labelWidth = 109;
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
numBounds = 16;
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

bounds[7].x = 76;
bounds[7].y = 76;
bounds[7].w = 10;
bounds[7].h = 10;
bounds[7].vis = 1;

bounds[8].x = 76;
bounds[8].y = 48;
bounds[8].w = 10;
bounds[8].h = 10;
bounds[8].vis = 1;

bounds[9].x = 76;
bounds[9].y = 104;
bounds[9].w = 10;
bounds[9].h = 10;
bounds[9].vis = 1;

bounds[10].x = 120;
bounds[10].y = 76;
bounds[10].w = 10;
bounds[10].h = 10;
bounds[10].vis = 1;

bounds[11].x = 120;
bounds[11].y = 48;
bounds[11].w = 10;
bounds[11].h = 10;
bounds[11].vis = 1;

bounds[12].x = 120;
bounds[12].y = 104;
bounds[12].w = 10;
bounds[12].h = 10;
bounds[12].vis = 1;

bounds[13].x = 164;
bounds[13].y = 76;
bounds[13].w = 10;
bounds[13].h = 10;
bounds[13].vis = 1;

bounds[14].x = 164;
bounds[14].y = 48;
bounds[14].w = 10;
bounds[14].h = 10;
bounds[14].vis = 1;

bounds[15].x = 164;
bounds[15].y = 104;
bounds[15].w = 10;
bounds[15].h = 10;
bounds[15].vis = 1;

//Enemy creation
numEnemies = 6;

enemies[0].x = 60;
enemies[0].y = 32;
enemies[0].size = 16;
enemies[0].type = 'v';
enemies[0].color = STONE;
enemies[0].meta[0] = -1;
enemies[0].meta[1] = 82;
enemies[0].meta[2] = enemies[0].meta[1];
enemies[0].meta[3] = 1;
enemies[0].meta[4] = 1;

enemies[1].x = 95;
enemies[1].y = 112;
enemies[1].size = 16;
enemies[1].type = 'v';
enemies[1].color = STONE;
enemies[1].meta[0] = 1;
enemies[1].meta[1] = 82;
enemies[1].meta[2] = enemies[1].meta[1];
enemies[1].meta[3] = 1;
enemies[1].meta[4] = 1;

enemies[2].x = 140;
enemies[2].y = 112;
enemies[2].size = 16;
enemies[2].type = 'v';
enemies[2].color = STONE;
enemies[2].meta[0] = 1;
enemies[2].meta[1] = 82;
enemies[2].meta[2] = enemies[2].meta[1];
enemies[2].meta[3] = 1;
enemies[2].meta[4] = 1;

enemies[3].x = 175;
enemies[3].y = 32;
enemies[3].size = 16;
enemies[3].type = 'v';
enemies[3].color = STONE;
enemies[3].meta[0] = -1;
enemies[3].meta[1] = 82;
enemies[3].meta[2] = enemies[3].meta[1];
enemies[3].meta[3] = 1;
enemies[3].meta[4] = 1;

enemies[4].x = 80;
enemies[4].y = 32;
enemies[4].size = 16;
enemies[4].type = 'h';
enemies[4].color = STONE;
enemies[4].meta[0] = -1;
enemies[4].meta[1] = 82;
enemies[4].meta[2] = enemies[4].meta[1];
enemies[4].meta[3] = 1;
enemies[4].meta[4] = 1;

enemies[5].x = 80;
enemies[5].y = 114;
enemies[5].size = 16;
enemies[5].type = 'h';
enemies[5].color = STONE;
enemies[5].meta[0] = -1;
enemies[5].meta[1] = 82;
enemies[5].meta[2] = enemies[5].meta[1];
enemies[5].meta[3] = 1;
enemies[5].meta[4] = 1;


drawPaths(paths, numPaths, pathColor);
drawBounds(bounds, numBounds);

//Draw text
drawRect(146,0,14,labelWidth,BLACK);
drawString(150, 3, labelMessage, labelColor);

//Change state
state = STAGE9_IDLE;