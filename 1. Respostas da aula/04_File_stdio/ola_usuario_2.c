#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, const char * argv[]){
FILE *fp;
char nome[10]="Nome: ";
char idade[10] = "Idade: ";
char anos[10] = " anos.";
int i;
	if((fp = fopen("Eu.txt", "w")) == NULL)
	{
		printf("\nNao consigo abrir o arquivo :(\n");
		exit(1);
	}
fputs(nome, fp);
fputs(argv[1], fp);
putc('\n', fp);
fputs(idade, fp);
fputs(argv[2], fp);
fputs(anos, fp);
putc('\n', fp);
	if (ferror(fp))
	{
		perror("Erro na gravacao");
		fclose(fp);
		exit(1);
	}
fclose(fp);

}
