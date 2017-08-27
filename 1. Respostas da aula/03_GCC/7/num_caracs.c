#include "num_caracs.h"

int Num_Caracs(char *palavra)
{ 
int i= 0;
while ((palavra[i]) != '\0')
{
i++;
}
return i;
}
