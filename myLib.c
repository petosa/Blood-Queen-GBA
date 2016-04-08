#include <stdio.h>
#include "myLib.h"
#include "text.h"

unsigned short *videoBuffer = (unsigned short *)0x6000000;

//Set individual pixel in the buffer to a color
void setPixel(int r, int c, unsigned short color)
{
	videoBuffer[OFFSET(r, c, 240)] = color;
}

//Magenta is treated as transparent in this setpixel loop
void drawTransparent(int row, int col, int height, int width, const u16* image)
{
	for(int r=0; r<height; r++)
	{
		for(int c = 0; c<width; c++)
		{
			if (image[15*r + c] != MAGENTA)
			setPixel(row+r, col+c, image[15*r + c]);
		}
	}
}

//DMA to draw a solid rectange
void drawRect(int row, int col, int height, int width, unsigned short color)
{
	volatile short colorvar = color;
	for(int r=0; r<height; r++)
	{
		DMA[3].src = &colorvar;
		DMA[3].dst = &videoBuffer[OFFSET(row+r, col, 240)];
		DMA[3].cnt = width | DMA_ON | DMA_SOURCE_FIXED;
	}
}

//Paint finished
void waitForVblank()
{
	while(SCANLINECOUNTER > 160);
	while(SCANLINECOUNTER < 160);
}

/* drawimage3
* A function that will draw an arbitrary sized image
* onto the screen (with DMA).
* @param r row to draw the image
* @param c column to draw the image
* @param width width of the image
* @param height height of the image
* @param image Pointer to the first element of the image.
*/
void drawImage3(int r, int c, int width, int height, const u16* image)
{
	for (int x = 0; x < height; x++) {
	DMA[DMA_CHANNEL_3].src = image + width*x;
	DMA[DMA_CHANNEL_3].dst = videoBuffer + 240*r + 240*x + c;
	DMA[DMA_CHANNEL_3].cnt = width |
		DMA_SOURCE_INCREMENT |
		DMA_DESTINATION_INCREMENT |
		DMA_ON;
	}	
}
