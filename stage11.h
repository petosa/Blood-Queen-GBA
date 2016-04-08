//Draw background
drawImage3(0, 0, THRONE_WIDTH, THRONE_HEIGHT, throne);

//Draw Health
drawHealth(life);

//String at bottom
labelMessage = "Inner Palace - Shrine";
labelWidth = 133;
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
numEnemies = 8;

enemies[0].x = 150;
enemies[0].y = 40;
enemies[0].size = 11;
enemies[0].type = 'g';
enemies[0].color = GLOW;
enemies[0].meta[0] = -1;
enemies[0].meta[1] = 10;
enemies[0].meta[2] = enemies[0].meta[1];
enemies[0].meta[3] = 5;
enemies[0].meta[4] = 1;

enemies[1].x = 70;
enemies[1].y = 40;
enemies[1].size = 11;
enemies[1].type = 'g';
enemies[1].color = GLOW;
enemies[1].meta[0] = -1;
enemies[1].meta[1] = 10;
enemies[1].meta[2] = enemies[1].meta[1];
enemies[1].meta[3] = 5;
enemies[1].meta[4] = 1;

enemies[2].x = 180;
enemies[2].y = 80;
enemies[2].size = 11;
enemies[2].type = 'g';
enemies[2].color = GLOW;
enemies[2].meta[0] = -1;
enemies[2].meta[1] = 10;
enemies[2].meta[2] = enemies[2].meta[1];
enemies[2].meta[3] = 5;
enemies[2].meta[4] = 1;

enemies[3].x = 40;
enemies[3].y = 80;
enemies[3].size = 11;
enemies[3].type = 'g';
enemies[3].color = GLOW;
enemies[3].meta[0] = -1;
enemies[3].meta[1] = 10;
enemies[3].meta[2] = enemies[3].meta[1];
enemies[3].meta[3] = 5;
enemies[3].meta[4] = 1;

enemies[4].x = 150;
enemies[4].y = 120;
enemies[4].size = 11;
enemies[4].type = 'g';
enemies[4].color = GLOW;
enemies[4].meta[0] = -1;
enemies[4].meta[1] = 10;
enemies[4].meta[2] = enemies[4].meta[1];
enemies[4].meta[3] = 5;
enemies[4].meta[4] = 1;

enemies[5].x = 70;
enemies[5].y = 120;
enemies[5].size = 11;
enemies[5].type = 'g';
enemies[5].color = GLOW;
enemies[5].meta[0] = -1;
enemies[5].meta[1] = 10;
enemies[5].meta[2] = enemies[5].meta[1];
enemies[5].meta[3] = 5;
enemies[5].meta[4] = 1;

enemies[6].x = 80;
enemies[6].y = 80;
enemies[6].size = 11;
enemies[6].type = 'g';
enemies[6].color = WHITE;
enemies[6].meta[0] = 1;
enemies[6].meta[1] = 10;
enemies[6].meta[2] = enemies[6].meta[1];
enemies[6].meta[3] = 5;
enemies[6].meta[4] = 1;

enemies[7].x = 140;
enemies[7].y = 80;
enemies[7].size = 11;
enemies[7].type = 'g';
enemies[7].color = WHITE;
enemies[7].meta[0] = 1;
enemies[7].meta[1] = 10;
enemies[7].meta[2] = enemies[7].meta[1];
enemies[7].meta[3] = 5;
enemies[7].meta[4] = 1;

drawPaths(paths, numPaths, pathColor);
drawBounds(bounds, numBounds);

//Draw text
drawRect(146,0,14,labelWidth,BLACK);
drawString(150, 3, labelMessage, labelColor);

//Change state
state = STAGE11_IDLE;