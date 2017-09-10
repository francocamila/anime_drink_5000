#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()
#include <string.h>

int main(int argc, char *argv[]){
int fp, i;
char nome_arq[60], conteudo[200];
sprintf(nome_arq, "%s.txt", argv[1]);
sprintf(conteudo, "Nome: %s\nIdade: %s anos\n", argv[1], argv[2]);
fp = open(nome_arq, O_WRONLY | O_CREAT, S_IRWXU);
	if (fp==-1){
		printf("Erro na abertura do arquivo");
		exit(-1);
	}
write(fp, conteudo, strlen(conteudo));
close(fp);
}
