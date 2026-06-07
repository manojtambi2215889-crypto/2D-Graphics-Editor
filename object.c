#include <stdio.h>
#include "object.h"
#include "graphics.h"

Object objects[MAX_OBJECTS];
int objectCount = 0;

void redrawCanvas()
{
    int i;

    initializeCanvas();

    for(i = 0; i < objectCount; i++)
    {
        if(objects[i].active)
        {
            switch(objects[i].type)
            {
                case 1:
                    drawRectangle(
                        objects[i].p[0],
                        objects[i].p[1],
                        objects[i].p[2],
                        objects[i].p[3]);
                    break;

                case 2:
                    drawLine(
                        objects[i].p[0],
                        objects[i].p[1],
                        objects[i].p[2],
                        objects[i].p[3]);
                    break;

                case 3:
                    drawTriangle(
                        objects[i].p[0],
                        objects[i].p[1],
                        objects[i].p[2],
                        objects[i].p[3],
                        objects[i].p[4],
                        objects[i].p[5]);
                    break;

                case 4:
                    drawCircle(
                        objects[i].p[0],
                        objects[i].p[1],
                        objects[i].p[2]);
                    break;
            }
        }
    }
}

void addObject()
{
    Object obj;

    obj.id = objectCount + 1;
    obj.active = 1;

    printf("\n1.Rectangle");
    printf("\n2.Line");
    printf("\n3.Triangle");
    printf("\n4.Circle");
    printf("\nEnter type: ");
    scanf("%d", &obj.type);

    switch(obj.type)
    {
        case 1:
            printf("x y width height: ");
            scanf("%d%d%d%d",
                  &obj.p[0], &obj.p[1],
                  &obj.p[2], &obj.p[3]);
            break;

        case 2:
            printf("x1 y1 x2 y2: ");
            scanf("%d%d%d%d",
                  &obj.p[0], &obj.p[1],
                  &obj.p[2], &obj.p[3]);
            break;

        case 3:
            printf("x1 y1 x2 y2 x3 y3: ");
            scanf("%d%d%d%d%d%d",
                  &obj.p[0], &obj.p[1],
                  &obj.p[2], &obj.p[3],
                  &obj.p[4], &obj.p[5]);
            break;

        case 4:
            printf("centerX centerY radius: ");
            scanf("%d%d%d",
                  &obj.p[0], &obj.p[1],
                  &obj.p[2]);
            break;
    }

    objects[objectCount++] = obj;

    redrawCanvas();
}

void deleteObject()
{
    int id;
    int i;

    printf("Enter object id: ");
    scanf("%d", &id);

    for(i = 0; i < objectCount; i++)
    {
        if(objects[i].id == id)
        {
            objects[i].active = 0;
            break;
        }
    }

    redrawCanvas();
}

void modifyObject()
{
    int id;
    int i;

    printf("Enter object id: ");
    scanf("%d", &id);

    for(i = 0; i < objectCount; i++)
    {
        if(objects[i].id == id)
        {
            switch(objects[i].type)
            {
                case 1:
                    printf("New x y width height: ");
                    scanf("%d%d%d%d",
                          &objects[i].p[0],
                          &objects[i].p[1],
                          &objects[i].p[2],
                          &objects[i].p[3]);
                    break;

                case 2:
                    printf("New x1 y1 x2 y2: ");
                    scanf("%d%d%d%d",
                          &objects[i].p[0],
                          &objects[i].p[1],
                          &objects[i].p[2],
                          &objects[i].p[3]);
                    break;

                case 3:
                    printf("New x1 y1 x2 y2 x3 y3: ");
                    scanf("%d%d%d%d%d%d",
                          &objects[i].p[0],
                          &objects[i].p[1],
                          &objects[i].p[2],
                          &objects[i].p[3],
                          &objects[i].p[4],
                          &objects[i].p[5]);
                    break;

                case 4:
                    printf("New centerX centerY radius: ");
                    scanf("%d%d%d",
                          &objects[i].p[0],
                          &objects[i].p[1],
                          &objects[i].p[2]);
                    break;
            }
        }
    }

    redrawCanvas();
}