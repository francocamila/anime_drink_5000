#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"

int main(int argc, char *argv[])
{
int i=0; 
for (i=0; i<argc; i++)
{
printf("Argumento: %s", argv[i]);
printf("\n Numero de Caracteres: %d\n",Num_Caracs(argv[i]));
}
return 0;
}


