#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

FILE *fp = fopen ("fibonacci.txt", "wb");
int i=0, aux=0, a=0, b=1;

if (!fp){
printf("Erro na abertura do arquivo.");
exit(-1);
}

for (i = 0; i<=100; i++){

aux = a + b;
a = b;
b = aux;
putc(aux, fp);
}
fclose(fp);
return 0;
}
