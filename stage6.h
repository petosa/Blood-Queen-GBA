//Draw background
drawImage3(0, 0, CASTLE_WIDTH, CASTLE_HEIGHT, castle);

//Draw Health
drawHealth(life);

//String at bottom
labelMessage = "Castle - Foyer";
labelWidth = 92;
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
numEnemies = 3;

enemies[0].x = 55;
enemies[0].y = 75;
enemies[0].size = 10;
enemies[0].type = 'g';
enemies[0].color = FLARE;
enemies[0].meta[0] = -1;
enemies[0].meta[1] = 20;
enemies[0].meta[2] = enemies[0].meta[1];
enemies[0].meta[3] = 1;
enemies[0].meta[4] = 3;

enemies[1].x = 125;
enemies[1].y = 75;
enemies[1].size = 10;
enemies[1].type = 'g';
enemies[1].color = FLARE;
enemies[1].meta[0] = -1;
enemies[1].meta[1] = 20;
enemies[1].meta[2] = enemies[1].meta[1];
enemies[1].meta[3] = 2;
enemies[1].meta[4] = 6;

enemies[2].x = 195;
enemies[2].y = 75;
enemies[2].size = 10;
enemies[2].type = 'g';
enemies[2].color = FLARE;
enemies[2].meta[0] = -1;
enemies[2].meta[1] = 20;
enemies[2].meta[2] = enemies[2].meta[1];
enemies[2].meta[3] = 3;
enemies[2].meta[4] = 7;


drawPaths(paths, numPaths, pathColor);
drawBounds(bounds, numBounds);

//Draw text
drawRect(146,0,14,labelWidth,BLACK);
drawString(150, 3, labelMessage, labelColor);

//Change state
state = STAGE6_IDLE;