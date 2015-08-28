#ifndef LINESDEAL_H_INCLUDED
#define LINESDEAL_H_INCLUDED
#include"listthing.h"
#include<stdbool.h>

typedef struct {
unsigned int line:20;//20 bit unsigned int
unsigned char x:7;//7bit unsigned char
} Point;

typedef struct _Points{
    Point * data;
    struct _Points *next;
}Points;
typedef Points *_9mer;

_9mer Load9mer(llist op);

bool FileAck(char *filename);
llist LoadLines(char *pathwn);



#endif // LINESDEAL_H_INCLUDED
