#ifndef OBJECT_H
#define OBJECT_H

#define MAX_OBJECTS 100

typedef struct
{
    int id;
    int type;
    int active;
    int p[10];
} Object;

extern Object objects[MAX_OBJECTS];
extern int objectCount;

void addObject();
void deleteObject();
void modifyObject();
void redrawCanvas();

#endif