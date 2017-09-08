#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *fp;
	char nome[60];
	char idade[10];
	char name[10]="Nome: ";
	char age[10]="Idade: ";
	char anos[10]=" anos.";
	if((fp = fopen("Eu.txt", "w")) == NULL)
	{
		printf("\nNao consigo abrir o arquivo :(\n");
		exit(1);
	}
	printf("Digite o seu nome: ");
	gets(nome);
	fputs(name, fp);
	fputs(nome, fp);
	putc('\n', fp);
	printf("Digite a sua idade: ");
	gets(idade);
	fputs(age, fp);
	fputs(idade, fp);
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
