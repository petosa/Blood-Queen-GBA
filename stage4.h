//Draw background
drawImage3(0, 0, GRASS_WIDTH, GRASS_HEIGHT, grass);

//Draw Health
drawHealth(life);

//String at bottom
labelMessage = "Forest - Boar";
labelWidth = 84;
labelColor = GREEN;

//Set spawn
spawnX = 2;
spawnY = 73;

//Move player
teleport(&me, &oldMe, spawnX, spawnY);

//Create path
pathColor = DAMP;
numPaths = 4;

paths[0].x = 0;
paths[0].y = 60;
paths[0].w = 240;
paths[0].h = 40;

paths[1].x = 50;
paths[1].y = 30;
paths[1].w = 30;
paths[1].h = 100;

paths[2].x = 105;
paths[2].y = 30;
paths[2].w = 30;
paths[2].h = 100;

paths[3].x = 160;
paths[3].y = 30;
paths[3].w = 30;
paths[3].h = 100;

//Create Bounds
numBounds = 11;
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

bounds[5].x = 190;
bounds[5].y = 0;
bounds[5].w = 50;
bounds[5].h = 60;
bounds[5].vis = 0;

bounds[6].x = 190;
bounds[6].y = 100;
bounds[6].w = 50;
bounds[6].h = 60;
bounds[6].vis = 0;

bounds[7].x = 80;
bounds[7].y = 30;
bounds[7].w = 25;
bounds[7].h = 30;
bounds[7].vis = 0;

bounds[8].x = 80;
bounds[8].y = 100;
bounds[8].w = 25;
bounds[8].h = 30;
bounds[8].vis = 0;

bounds[9].x = 135;
bounds[9].y = 30;
bounds[9].w = 25;
bounds[9].h = 30;
bounds[9].vis = 0;

bounds[10].x = 135;
bounds[10].y = 100;
bounds[10].w = 25;
bounds[10].h = 30;
bounds[10].vis = 0;


//Enemy creation
numEnemies = 1;

enemies[0].x = 51;
enemies[0].y = 60;
enemies[0].size = 40;
enemies[0].type = 'h';
enemies[0].color = BOAR;
enemies[0].meta[0] = -1;
enemies[0].meta[1] = 100;
enemies[0].meta[2] = enemies[0].meta[1];
enemies[0].meta[3] = 1;

drawPaths(paths, numPaths, pathColor);
drawBounds(bounds, numBounds);

//Draw text
drawRect(146,0,14,labelWidth,BLACK);
drawString(150, 3, labelMessage, labelColor);

//Change state
state = STAGE4_IDLE;
