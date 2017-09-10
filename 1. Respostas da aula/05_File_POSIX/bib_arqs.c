#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()
#include <string.h>

long int tam_arq_texto(const char *nome_arquivo)
{
struct stat st;
stat(nome_arquivo, &st);
return st.st_size;
}

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
long int tam=0;
int fp;
fp = open(nome_arquivo, O_RDONLY);
tam = tam_arq_texto(nome_arquivo);
conteudo = (char *)malloc(tam * (sizeof(char)));
read(fp, conteudo, sizeof(char)*tam);
puts(conteudo);
close(fp);
}
