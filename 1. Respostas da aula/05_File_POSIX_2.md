Para todas as questões, utilize as funções da norma POSIX (open(), close(), write(), read() e lseek()). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```
#include <stdio.h>
#include <fcntl.h>	
#include <unistd.h>	
#include <stdlib.h>	
int main(int argc, const char * argv[])
{
	int fp, i;
	char string[20]={"Ola mundo!"};
	
	fp = open("ola_mundo.txt", O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
		for(i=0; string[i]; i++){
		write(fp, &(string[i]), 1);} // Grava a string, caractere a caractere	
	write(fp, "\n", 1);
	close(fp);

	return 0;
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
#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()

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
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

```
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
```

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

```
long int tam_arq_texto(const char *nome_arquivo)
{
struct stat st;
stat(nome_arquivo, &st);
return st.st_size;
}
```

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `void le_arq_texto(char *nome_arquivo, char *conteúdo);` Repare que o conteúdo do arquivo é armazenado no vetor `conteudo[]`. Ou seja, ele é passado por referência. Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

```
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
free(conteudo);
}
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include "bib_arqs.h"

int main(int argc, char *argv[])
{   
int n=0, fp, i=0,tam=0;
char *string, *palavra;
fp = open(argv[2], O_RDONLY);
if (fp == -1)
{
    printf("Não foi possível acessar o arquivo\n");
    exit(-1);
}
le_arq_texto(argv[2], string); 

for (i=0; i<strlen(string); i++)//loop procura a palavra
{

    if(strcmp(string,argv[1]) == 0)
	n++;
}
printf("'%s' ocorre %d vezes no arquivo '%s'\n",argv[1],n, argv[2] );
return 0;
}
```
```



