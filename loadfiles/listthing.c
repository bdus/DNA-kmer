#include"listthing.h"

/******************
    Point x = {0,0};
    x.line--;
    x.x--;
    printf("%u d\n%u c\n",x.line,x.x);
*******************/

Node * newNode()
{
	Node* p = NULL;
	if( (p = malloc(sizeof(Node))) == 0 )
	{
		perror("Exhausted memory.");
	}
	return p;
}
void freeList(llist op)
{
    while(op != NULL)
    {
        free(op->data.s);
        free(op);
        op = op->next;
    }
}
void printList(llist op)
{
    while(op != NULL)
    {
        printf("%d\n%s\n",op->data.lnum,op->data.s);
        op = op->next;
    }
}
