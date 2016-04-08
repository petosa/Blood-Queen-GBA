//Draw background
drawImage3(0, 0, CASTLE_WIDTH, CASTLE_HEIGHT, castle);

//Draw Health
drawHealth(life);

//String at bottom
labelMessage = "Castle - Festival";
labelWidth = 109;
labelColor = STONE;

//Set spawn
spawnX = 2;
spawnY = 73;

//Move player
teleport(&me, &oldMe, spawnX, spawnY);

//Create path
pathColor = ROYAL;
numPaths = 1;
paths[0].x = 0;
paths[0].y = 50;
paths[0].w = 240;
paths[0].h = 60;

//Create Bounds
numBounds = 3;
bounds[0].x = 0;
bounds[0].y = 0;
bounds[0].w = 240;
bounds[0].h = 50;
bounds[0].vis = 0;

bounds[1].x = 0;
bounds[1].y = 0;
bounds[1].w = 1;
bounds[1].h = 160;
bounds[1].vis = 0;

bounds[2].x = 0;
bounds[2].y = 110;
bounds[2].w = 240;
bounds[2].h = 30;
bounds[2].vis = 0;

//Enemy creation
numEnemies = 5;

enemies[0].x = 55;
enemies[0].y = 75;
enemies[0].size = 3;
enemies[0].type = 'h';
enemies[0].color = CYAN;
enemies[0].meta[0] = -1;
enemies[0].meta[1] = 70;
enemies[0].meta[2] = enemies[0].meta[1];
enemies[0].meta[3] = 1;
enemies[0].meta[4] = 3;

enemies[1].x = 75;
enemies[1].y = 95;
enemies[1].size = 3;
enemies[1].type = 'h';
enemies[1].color = MAGENTA;
enemies[1].meta[0] = -1;
enemies[1].meta[1] = 150;
enemies[1].meta[2] = enemies[1].meta[1];
enemies[1].meta[3] = 2;

enemies[2].x = 65;
enemies[2].y = 55;
enemies[2].size = 3;
enemies[2].type = 'h';
enemies[2].color = FLASH;
enemies[2].meta[0] = -1;
enemies[2].meta[1] = 100;
enemies[2].meta[2] = enemies[2].meta[1];
enemies[2].meta[3] = 3;

enemies[3].x = 105;
enemies[3].y = 55;
enemies[3].size = 3;
enemies[3].type = 'v';
enemies[3].color = GREEN;
enemies[3].meta[0] = -1;
enemies[3].meta[1] = 50;
enemies[3].meta[2] = enemies[3].meta[1];
enemies[3].meta[3] = 2;

enemies[4].x = 145;
enemies[4].y = 100;
enemies[4].size = 3;
enemies[4].type = 'v';
enemies[4].color = WHITE;
enemies[4].meta[0] = 1;
enemies[4].meta[1] = 50;
enemies[4].meta[2] = enemies[4].meta[1];
enemies[4].meta[3] = 1;

drawPaths(paths, numPaths, pathColor);
drawBounds(bounds, numBounds);

//Draw text
drawRect(146,0,14,labelWidth,BLACK);
drawString(150, 3, labelMessage, labelColor);

//Change state
state = STAGE7_IDLE;