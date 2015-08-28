#ifndef LISTTHING_H_INCLUDED
#define LISTTHING_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
typedef struct {
	char *s;
	unsigned int lnum:20;//20 bit unsigned int
}Linedata;

struct _lines {
	Linedata data;
	struct _lines *next;
};
typedef struct _lines Node;
typedef struct _lines *llist;//Node *

Node * newNode();
void freeList(llist mylist);
void printList(llist op);


#endif // LISTTHING_H_INCLUDED
