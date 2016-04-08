//Draw background
drawImage3(0, 0, GRASS_WIDTH, GRASS_HEIGHT, grass);

//Draw Health
drawHealth(life);

//String at bottom
labelMessage = "Forest - Termites";
labelWidth = 108;
labelColor = GREEN;

//Set spawn
spawnX = 2;
spawnY = 73;

//Move player
teleport(&me, &oldMe, spawnX, spawnY);

//Create path
pathColor = DAMP;
numPaths = 2;

paths[0].x = 0;
paths[0].y = 60;
paths[0].w = 240;
paths[0].h = 40;

paths[1].x = 50;
paths[1].y = 30;
paths[1].w = 190;
paths[1].h = 100;

//Create Bounds
numBounds = 6;
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

bounds[3].x = 0;
bounds[3].y = 0;
bounds[3].w = 50;
bounds[3].h = 60;
bounds[3].vis = 0;

bounds[4].x = 0;
bounds[4].y = 100;
bounds[4].w = 50;
bounds[4].h = 60;
bounds[4].vis = 0;

bounds[5].x = 70;
bounds[5].y = 70;
bounds[5].w = 170;
bounds[5].h = 20;
bounds[5].vis = 1;

//Enemy creation
numEnemies = 6;

enemies[0].x = 77;
enemies[0].y = 36;
enemies[0].size = 8;
enemies[0].type = 'h';
enemies[0].color = TERMITE;
enemies[0].meta[0] = -1;
enemies[0].meta[1] = 79;
enemies[0].meta[2] = enemies[0].meta[1];
enemies[0].meta[3] = 1;

enemies[1].x = 97;
enemies[1].y = 60;
enemies[1].size = 8;
enemies[1].type = 'v';
enemies[1].color = TERMITE;
enemies[1].meta[0] = 1;
enemies[1].meta[1] = 29;
enemies[1].meta[2] = enemies[1].meta[1];
enemies[1].meta[3] = 1;

enemies[2].x = 117;
enemies[2].y = 36;
enemies[2].size = 8;
enemies[2].type = 'v';
enemies[2].color = TERMITE;
enemies[2].meta[0] = -1;
enemies[2].meta[1] = 79;
enemies[2].meta[2] = enemies[2].meta[1];
enemies[2].meta[3] = 1;

enemies[3].x = 137;
enemies[3].y = 115;
enemies[3].size = 8;
enemies[3].type = 'v';
enemies[3].color = TERMITE;
enemies[3].meta[0] = 1;
enemies[3].meta[1] = 79;
enemies[3].meta[2] = enemies[3].meta[1];
enemies[3].meta[3] = 1;

enemies[4].x = 157;
enemies[4].y = 36;
enemies[4].size = 8;
enemies[4].type = 'v';
enemies[4].color = TERMITE;
enemies[4].meta[0] = -1;
enemies[4].meta[1] = 79;
enemies[4].meta[2] = enemies[4].meta[1];
enemies[4].meta[3] = 1;

enemies[5].x = 77;
enemies[5].y = 106;
enemies[5].size = 18;
enemies[5].type = 'h';
enemies[5].color = TERMITE;
enemies[5].meta[0] = -1;
enemies[5].meta[1] = 79;
enemies[5].meta[2] = enemies[5].meta[1];
enemies[5].meta[3] = 2;

drawPaths(paths, numPaths, pathColor);
drawBounds(bounds, numBounds);

//Draw text
drawRect(146,0,14,labelWidth,BLACK);
drawString(150, 3, labelMessage, labelColor);

//Draw sprites
drawImage3(70,70,170,20,tree);
drawTransparent(30,200,40,40,portal);
drawTransparent(90,230,40,10,castledoor);

//Change state
state = STAGE5_IDLE;
