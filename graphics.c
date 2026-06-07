#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphics.h"

char canvas[ROWS][COLS];

void initializeCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height; i++)
    {
        for(j = x; j < x + width; j++)
        {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS)
                canvas[i][j] = '*';
        }
    }
}

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while(1)
    {
        if(y1 >= 0 && y1 < ROWS && x1 >= 0 && x1 < COLS)
            canvas[y1][x1] = '*';

        if(x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if(e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if(e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void drawTriangle(int x1, int y1,
                  int x2, int y2,
                  int x3, int y3)
{
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

void drawCircle(int xc, int yc, int r)
{
    int x, y;

    for(y = -r; y <= r; y++)
    {
        for(x = -r; x <= r; x++)
        {
            if(x*x + y*y <= r*r)
            {
                int row = yc + y;
                int col = xc + x;

                if(row >= 0 && row < ROWS &&
                   col >= 0 && col < COLS)
                {
                    canvas[row][col] = '*';
                }
            }
        }
    }
}