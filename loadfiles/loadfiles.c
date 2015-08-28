#include<stdio.h>
#include<stdlib.h>

#include"listthing.h"
#include"linesdeal.h"


//void myListOp(llist op);

int main(void)
{
	char * fn = "tmpdata";

	llist mylist = LoadLines(fn);
	//printList(mylist);

    _9mer pointer = Load9mer(mylist);


	freeList(mylist);
    //printf("\n%p.\n",mylist);
    //printf("\n%p\n%d\n%s\n",mylist->next,mylist->data.lnum,mylist->data.s);
	return 0;
}
