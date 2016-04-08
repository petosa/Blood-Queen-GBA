typedef unsigned short u16;

#define REG_DISPCTL *(unsigned short *)0x4000000
#define MODE3 3
#define BG2_ENABLE (1<<10)
#define SCANLINECOUNTER *(volatile unsigned short *)0x4000006 

//Global variables
extern unsigned short *videoBuffer;
extern int life;

#define COLOR(r, g, b)  ((r) | (g)<<5 | (b)<<10)
#define FLAME COLOR(3,2,12)
#define FLARE COLOR(9,2,21)
#define FLASH COLOR(3,2,22)
#define RED COLOR(31,0,0)
#define GREEN COLOR(0,31,0)
#define BLUE COLOR(0,0,31)
#define STONE COLOR(9, 13, 15)
#define LEAF COLOR(6, 11, 8)
#define BOULDER COLOR(19, 18, 12)
#define BOAR COLOR(9, 2, 2)
#define DAMP COLOR(12,16,15)
#define CYAN COLOR(0, 31, 31)
#define MAGENTA COLOR(31,0,31)
#define WHITE COLOR(31,31,31)
#define BLACK 0
#define OOZE COLOR(12,22,15)
#define ROYAL COLOR(11,4,4)
#define GOO COLOR(5,1,15)
#define AUTUMN COLOR(31,22,15)
#define TERMITE COLOR(5,2,1)
#define CARPET COLOR(13,1,10)
#define GLOW COLOR(22,16,3)
#define OFFSET(r, c, rowlen) ((r)*(rowlen) + (c))

// Buttons

#define BUTTON_A		(1<<0)
#define BUTTON_B		(1<<1)
#define BUTTON_SELECT		(1<<2)
#define BUTTON_START		(1<<3)
#define BUTTON_RIGHT		(1<<4)
#define BUTTON_LEFT		(1<<5)
#define BUTTON_UP		(1<<6)
#define BUTTON_DOWN		(1<<7)
#define BUTTON_R		(1<<8)
#define BUTTON_L		(1<<9)

#define KEY_DOWN_NOW(key)  (~(BUTTONS) & key)

#define BUTTONS *(volatile unsigned int *)0x4000130

/* DMA */
#define REG_DMA0SAD         *(const volatile u32*)0x40000B0 // source address
#define REG_DMA0DAD         *(volatile u32*)0x40000B4       // destination address
#define REG_DMA0CNT         *(volatile u32*)0x40000B8       // control register

// DMA channel 1 register definitions
#define REG_DMA1SAD         *(const volatile u32*)0x40000BC // source address
#define REG_DMA1DAD         *(volatile u32*)0x40000C0       // destination address
#define REG_DMA1CNT         *(volatile u32*)0x40000C4       // control register

// DMA channel 2 register definitions
#define REG_DMA2SAD         *(const volatile u32*)0x40000C8 // source address
#define REG_DMA2DAD         *(volatile u32*)0x40000CC       // destination address
#define REG_DMA2CNT         *(volatile u32*)0x40000D0       // control register

// DMA channel 3 register definitions
#define REG_DMA3SAD         *(const volatile u32*)0x40000D4 // source address
#define REG_DMA3DAD         *(volatile u32*)0x40000D8       // destination address
#define REG_DMA3CNT         *(volatile u32*)0x40000DC       // control register

//DMA Struct
typedef struct
{
	const volatile void *src;
	const volatile void *dst;
	unsigned int cnt;
} DMA_CONTROLLER;

//Player object
typedef struct
{
	int x;
	int y;
	int size;
} PLAYER;

//Path object
typedef struct
{
	int x;
	int y;
	int w;
	int h;
} PATH;

//Boundary object
typedef struct
{
	int x;
	int y;
	int w;
	int h;
	int vis;
} BOUND;

//Enemy object
typedef struct
{
	int x;
	int y;
	int size;
	char type;
	u16 color;
	int meta[5];
} ENEMY;

//More globals
extern PLAYER me;
extern PLAYER oldMe;

#define DMA ((volatile DMA_CONTROLLER *) 0x040000B0)

// Defines
#define DMA_CHANNEL_0 0
#define DMA_CHANNEL_1 1
#define DMA_CHANNEL_2 2
#define DMA_CHANNEL_3 3

#define DMA_DESTINATION_INCREMENT (0 << 21)
#define DMA_DESTINATION_DECREMENT (1 << 21)
#define DMA_DESTINATION_FIXED (2 << 21)
#define DMA_DESTINATION_RESET (3 << 21)

#define DMA_SOURCE_INCREMENT (0 << 23)
#define DMA_SOURCE_DECREMENT (1 << 23)
#define DMA_SOURCE_FIXED (2 << 23)

#define DMA_REPEAT (1 << 25)

#define DMA_16 (0 << 26)
#define DMA_32 (1 << 26)

#define DMA_NOW (0 << 28)
#define DMA_AT_VBLANK (1 << 28)
#define DMA_AT_HBLANK (2 << 28)
#define DMA_AT_REFRESH (3 << 28)

#define DMA_IRQ (1 << 30)
#define DMA_ON (1 << 31)


// Prototypes
void setPixel(int r, int c, unsigned short color);
void drawTransparent(int row, int col, int height, int width, const u16* image);
void drawRect(int row, int col, int height, int width, unsigned short color);
void delay(int n);
void waitForVblank();
void drawHealth(int l);
void fillScreen(u16 color);
void drawImage3(int r, int c, int width, int height, const u16* image);
void drawPaths(PATH *paths, int numPaths, short pathColor);
void drawBounds(BOUND *bounds, int numBounds);
unsigned char getMovementData(int x, int y, int size, BOUND bounds[], int numBounds);
int enemyLogic(ENEMY enemies[], int numEnemies, PLAYER p, u16 pathColor);
void teleport(PLAYER* p, PLAYER* op, int x, int y);
