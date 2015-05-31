#include <stdio.h>
#include <stdlib.h>
#include"findin1line.h"
#define DATAFILE "combine_biodata.txt"
#define TMPDATA "tmpdata"

void CreateIndex_i(unsigned char k, char *skmer);
int main()
{
/*  得到要查询的kmer */
    char* skmer = "3331";
    unsigned char k = 4;

/*  在100w行数据中，查询一条kmer出现的位置，并且保存 */
    CreateIndex_i(k,skmer);

    return 0;
}
void CreateIndex_i(unsigned char k, char *skmer)
{
/* 用于读取/存储数据文件的缓冲区 和 读取次数记录*/
    char buffer[101] = {0};
    char ch;
    unsigned int rowcnt = 0;
    unsigned char i = 0;
    //unsigned int rowcnt = 0;
    FILE *fpr;
    //FILE *fpw;

/*从DATAFILE读取一行数据到缓冲区，对改行进行搜索，将得到的结果输出成表 保存在*/
    fpr = fopen(DATAFILE,"r");

    for(rowcnt = 0; rowcnt < 1000000; rowcnt++ )
    {

        while( (ch = getc(fpr)) != EOF)
        {

            buffer[i] = ch;
            i++;
        }
        //get ch
        buffer[100] = '\0';
        i = 0;
        printf("%s",buffer);

        system("pause");
    }//rowcnt
}
