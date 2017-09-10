#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()
#include <string.h>

int main(int argc, const char *argv[]){
int fp, i;
char nome[60], idade[10], name[10]={"Nome: "}, age[10]={"Idade: "};
fp= open("ola_usuario_1.txt", O_WRONLY | O_CREAT, S_IRWXU);
if (fp == -1)
{
	printf("Erro na abertura do arquivo");
	exit(-1);
}
printf("\nDigite seu nome:");
gets(nome);
	for (i=0; name[i]; i++){
write(fp, &(name[i]),1);
}
	for (i=0; nome[i]; i++){
write(fp, &(nome[i]), 1);
}
write(fp, "\n", 1);
printf("Digite sua idade:");
gets(idade);
	for(i=0; age[i]; i++){
write(fp, &(age[i]),1);
}
	for(i=0; idade[i]; i++){
write(fp, &(idade[i]), 1);
}
write(fp, "\n", 1);
close(fp);
}

