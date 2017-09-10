#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include "bib_arqs.h"

int main(int argc, char *argv[])
{   
int n=0, fp, i=0,tam=0;
char *string, *palavra;
fp = open(argv[2], O_RDONLY);
if (fp == -1)
{
    printf("Não foi possível acessar o arquivo\n");
    exit(-1);
}
le_arq_texto(argv[2], string); 

for (i=0; i<strlen(string); i++)//loop procura a palavra
{

    if(strcmp(string,argv[1]) == 0)
	n++;
}
printf("'%s' ocorre %d vezes no arquivo '%s'\n",argv[1],n, argv[2] );
return 0;
}
