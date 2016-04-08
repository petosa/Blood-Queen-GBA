//Draw background
drawImage3(0, 0, GRASS_WIDTH, GRASS_HEIGHT, grass);

//Draw Health
drawHealth(life);

//String at bottom
labelMessage = "Forest - Clearing";
labelWidth = 110;
labelColor = GREEN;

//Set spawn
spawnX = 23;
spawnY = 73;

//Move player
teleport(&me, &oldMe, spawnX, spawnY);

//Create path
pathColor = DAMP;
numPaths = 1;
paths[0].x = 20;
paths[0].y = 45;
paths[0].w = 220;
paths[0].h = 70;

//Create Bounds
numBounds = 3;
bounds[0].x = 0;
bounds[0].y = 0;
bounds[0].w = 240;
bounds[0].h = 45;
bounds[0].vis = 0;

bounds[1].x = 0;
bounds[1].y = 0;
bounds[1].w = 20;
bounds[1].h = 160;
bounds[1].vis = 0;

bounds[2].x = 0;
bounds[2].y = 115;
bounds[2].w = 240;
bounds[2].h = 45;
bounds[2].vis = 0;

//Enemy creation
numEnemies = 2;

enemies[0].x = 85;
enemies[0].y = 46;
enemies[0].size = 10;
enemies[0].type = 'v';
enemies[0].color = LEAF;
enemies[0].meta[0] = -1;
enemies[0].meta[1] = 60;
enemies[0].meta[2] = enemies[0].meta[1];
enemies[0].meta[3] = 1;

enemies[1].x = 155;
enemies[1].y = 104;
enemies[1].size = 10;
enemies[1].type = 'v';
enemies[1].color = LEAF;
enemies[1].meta[0] = 1;
enemies[1].meta[1] = 60;
enemies[1].meta[2] = enemies[0].meta[1];
enemies[1].meta[3] = 1;


drawPaths(paths, numPaths, pathColor);
drawBounds(bounds, numBounds);

//Draw text
drawRect(146,0,14,labelWidth,BLACK);
drawString(150, 3, labelMessage, labelColor);

//Change state
state = STAGE1_IDLE;
