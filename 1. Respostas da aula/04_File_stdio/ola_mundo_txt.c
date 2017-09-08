#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, const char * argv[]){
FILE *fp;
int i=0;
char frase[30] = "Ola mundo!";
fp = fopen("ola_mundo.txt", "w");
if (!fp)
{
printf("Erro na abertura do arquivo");
exit(0);
}
fputs(frase,fp);
fclose(fp);
} 
