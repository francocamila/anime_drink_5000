#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

FILE *fp = fopen ("fibonacci.txt", "rb");
int r;

if (!fp){
printf("Erro na abertura do arquivo.");
exit(-1);
}

while((r = getc(fp)) != EOF){
printf("%d\n", r);
}
return 0;
}

