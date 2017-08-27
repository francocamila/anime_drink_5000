#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"

int main(int argc, char *argv[])
{
int i=0; int n=0;
for (i=0; i<argc; i++)
{
n += Num_Caracs(argv[i]);
}
printf("\n Numero de Caracteres: %d\n",n);
return 0;
}
