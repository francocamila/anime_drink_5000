#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

long tam_arq_texto(char *nome_arquivo)
{
FILE *fp = fopen(nome_arquivo, "r");
long tamanho=0;
if (fp != NULL){
fseek(fp, 0, SEEK_END);
tamanho = ftell(fp);
fseek(fp, 0, SEEK_SET);
fclose(fp);
}
else{
printf("Arquivo inexistente");
}
return tamanho;
}

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
long tam=0;
FILE *fp = fopen(nome_arquivo, "r");
tam = tam_arq_texto(nome_arquivo);
conteudo = (char *)malloc(tam * (sizeof(char)));
fgets(conteudo, sizeof(char)*tam, fp);
puts(conteudo);
fclose(fp);
free(conteudo);
}
