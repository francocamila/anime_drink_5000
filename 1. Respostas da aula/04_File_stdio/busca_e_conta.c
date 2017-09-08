#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{   
int n=0;
char string[30];
FILE *fp = fopen(argv[2], "r");
if (fp == NULL)
{
    printf("Não foi possível acessar o arquivo\n");
    exit(-1);
}

while(!feof(fp))//this loop searches the for the current word
{
    fscanf(fp,"%s",string);
    if(strcmp(string,argv[1]) == 0)//if match found increment num
    n++;
}
printf("'%s' ocorre %d vezes no arquivo '%s'\n",argv[1],n, argv[2] );
return 0;
}
