//Draw background
drawImage3(0, 0, THRONE_WIDTH, THRONE_HEIGHT, throne);

//Draw Health
drawHealth(life);

//String at bottom
labelMessage = "Inner Palace - Volatile";
labelWidth = 146;
labelColor = MAGENTA;

//Set spawn
spawnX = 2;
spawnY = 73;

//Move player
teleport(&me, &oldMe, spawnX, spawnY);

//Create path
pathColor = CARPET;
numPaths = 2;

paths[1].x = 0;
paths[1].y = 30;
paths[1].w = 240;
paths[1].h = 100;

//Create Bounds
numBounds = 3;
bounds[0].x = 0;
bounds[0].y = 0;
bounds[0].w = 240;
bounds[0].h = 30;
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

//Enemy creation
numEnemies = 4;

enemies[0].x = 86;
enemies[0].y = 45;
enemies[0].size = 11;
enemies[0].type = 'v';
enemies[0].color = CYAN;
enemies[0].meta[0] = -1;
enemies[0].meta[1] = 70;
enemies[0].meta[2] = enemies[0].meta[1];
enemies[0].meta[3] = 3;
enemies[0].meta[4] = 1;

enemies[1].x = 136;
enemies[1].y = 45;
enemies[1].size = 11;
enemies[1].type = 'v';
enemies[1].color = CYAN;
enemies[1].meta[0] = -1;
enemies[1].meta[1] = 70;
enemies[1].meta[2] = enemies[1].meta[1];
enemies[1].meta[3] = 3;
enemies[1].meta[4] = 1;

enemies[2].x = 156;
enemies[2].y = 45;
enemies[2].size = 11;
enemies[2].type = 'v';
enemies[2].color = CYAN;
enemies[2].meta[0] = -1;
enemies[2].meta[1] = 70;
enemies[2].meta[2] = enemies[2].meta[1];
enemies[2].meta[3] = 2;
enemies[2].meta[4] = 1;

enemies[3].x = 106;
enemies[3].y = 45;
enemies[3].size = 11;
enemies[3].type = 'v';
enemies[3].color = CYAN;
enemies[3].meta[0] = -1;
enemies[3].meta[1] = 70;
enemies[3].meta[2] = enemies[3].meta[1];
enemies[3].meta[3] = 1;
enemies[3].meta[4] = 1;

drawPaths(paths, numPaths, pathColor);
drawBounds(bounds, numBounds);

//Draw text
drawRect(146,0,14,labelWidth,BLACK);
drawString(150, 3, labelMessage, labelColor);

//Change state
state = STAGE13_IDLE;