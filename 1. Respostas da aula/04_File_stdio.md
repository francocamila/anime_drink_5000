Para todas as questões, compile-as com o gcc e execute-as via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 int main (int argc, const char * argv[])
 {
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
```

2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

```
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
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

```
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
```

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

```
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
```

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `void le_arq_texto(char *nome_arquivo, char *conteúdo);` Repare que o conteúdo do arquivo é armazenado no vetor `conteudo[]`. Ou seja, ele é passado por referência. Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

```
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
```

```
long tam_arq_texto(char *nome_arquivo);
void le_arq_texto(char *nome_arquivo, char *conteudo);
```

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```

```
#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main (int argc, char * argv[]){

char *tala;
le_arq_texto(argv[1], tala);
}

```


7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{   
int n=0;
char string[30];
FILE *fp = fopen(argv[2], "r");
if (fp == NULL)
{
    printf("Não foi possível acessar o arquivo\n");
    exit(-1);
}

while(!feof(fp))//enquanto não chegar ao fim do arquivo
{
    fscanf(fp,"%s",string);
    if(strcmp(string,argv[1]) == 0)//se encontra uma palavra igual no texto
    n++;
}
printf("'%s' ocorre %d vezes no arquivo '%s'\n",argv[1],n, argv[2] );
return 0;
}
```
