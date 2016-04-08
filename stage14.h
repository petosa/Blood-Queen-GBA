//Draw background
drawImage3(0, 0, THRONE_WIDTH, THRONE_HEIGHT, throne);

//Draw Health
drawHealth(life);

//String at bottom
labelMessage = "Inner Palace - Where am I...";
labelWidth = 176;
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

enemies[1].x = 116;
enemies[1].y = 75;
enemies[1].size = 11;
enemies[1].type = 'g';
enemies[1].color = BLUE;
enemies[1].meta[0] = -1;
enemies[1].meta[1] = 40;
enemies[1].meta[2] = enemies[1].meta[1];
enemies[1].meta[3] = 6;
enemies[1].meta[4] = 1;

enemies[2].x = 116;
enemies[2].y = 75;
enemies[2].size = 11;
enemies[2].type = 'g';
enemies[2].color = MAGENTA;
enemies[2].meta[0] = -1;
enemies[2].meta[1] = 40;
enemies[2].meta[2] = enemies[2].meta[1];
enemies[2].meta[3] = 8;
enemies[2].meta[4] = 1;

enemies[3].x = 116;
enemies[3].y = 75;
enemies[3].size = 11;
enemies[3].type = 'g';
enemies[3].color = GREEN;
enemies[3].meta[0] = -1;
enemies[3].meta[1] = 40;
enemies[3].meta[2] = enemies[3].meta[1];
enemies[3].meta[3] = 7;
enemies[3].meta[4] = 1;

enemies[0].x = 116;
enemies[0].y = 75;
enemies[0].size = 11;
enemies[0].type = 'g';
enemies[0].color = RED;
enemies[0].meta[0] = -1;
enemies[0].meta[1] = 40;
enemies[0].meta[2] = enemies[0].meta[1];
enemies[0].meta[3] = 1;
enemies[0].meta[4] = 1;

drawPaths(paths, numPaths, pathColor);
drawBounds(bounds, numBounds);

//Draw text
drawRect(146,0,14,labelWidth,BLACK);
drawString(150, 3, labelMessage, labelColor);

//Change state
state = STAGE14_IDLE;