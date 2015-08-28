#include"linesdeal.h"
#define DEBUG

const unsigned int base4[11] = {1,4,16,64,256,1024,4096,16384,65536,262144,1048576};

Points * newPoints()
{
    Points *nps = malloc(sizeof(Points));
    nps->next = NULL;
    return nps;
}
#ifdef DEBUG
void print9mer(char * s )
{
    register unsigned int shash = 0;
    unsigned char i = 0;

    for(i = 0; i < 9; i++)
    {
        shash += (s[i]-'0')*base4[8-i];
    }
    printf("%u\n",shash);
    for(i = 0 ; i + 9 < 100 ; i++)
    {
        shash =  (shash - (s[i] - '0')*base4[8]) * 4 + s[9+i] - '0';
        printf("%u\n",shash);
    }
}
#endif // DEBUG

_9mer Load9mer(llist mylist)
{
    _9mer ans;
    //_9mer pointslist[base4[9]];
    char * data_s;
    FILE *fpw = fopen("")
    register unsigned int shash = 0;
    unsigned char i = 0;
    while(mylist != NULL)
    {
        //   print9mer(mylist->data.s);
        data_s = mylist->data.s;

        for(i = 0; i < 9; i++)
        {
            shash += (data_s[i]-'0')*base4[8-i];
        }
        printf("%u\n",shash);
        for(i = 0 ; i + 9 < 100 ; i++)
        {
            shash =  (shash - (data_s[i] - '0')*base4[8]) * 4 + data_s[9+i] - '0';
            printf("%u\n",shash);
        }

        system("pause");

        mylist = mylist->next;
    }//    while(mylist != NULL)



    return ans;
}//_9mer Load9mer(llist op)


bool FileAck(char *filename)
{
    FILE *fp;
    fp = fopen(filename,"r");
    if(fp == NULL)
        return false;
    return true;
}//FileAck

llist LoadLines(char *pathwn)
{
	/*
	 * Load lines from file
	 *
	 * (char*)pathwn :path with filename.
	 * return (Aline*) a singel linked list contains data info.
	 * */
    if(FileAck(pathwn) == false)
        perror("no such file.\n");
    FILE *fpr = fopen(pathwn,"r");
	int linecnt = 0;//from 0~1000k-1

    /*
    head -> NULL
    op   -> NULL
    head -> node0
    op   -> node0
    //ass
    node0.next  -> node1 | op->next  ->  node1
    op   -> node1        | op = op->next

    ......

	*/

	llist head = NULL;
	llist op   = NULL;
	llist bkup = NULL;
	//char buff[100];// useless , clear the '\n'.
	bkup = op = head = newNode();

	while( (op->data.s = fgets(malloc(sizeof(char)*102),102,fpr)) != NULL )//102 = 100 + 2 (\r\n)
	{
		op->data.lnum = linecnt++;
        //printf("%d\n%s\n",op->data.lnum,op->data.s);
		//fgets(buff,102,fpr);// useless , clear the '\n'.
		op->next = newNode();
		bkup = op;
		op = op->next;
	}
	free(op);
	bkup->next = NULL;
	fclose(fpr);

	return head;
}//llist LoadLines(char *pathwn)
