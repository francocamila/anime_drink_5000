1. Crie um código em C que escreve a sequência de Fibonacci em arquivo em formato binário. Comece a sequência com os valores 0 e 1, e grave suas primeiras 100 posições em arquivo.

```
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

FILE *fp = fopen ("fibonacci.txt", "wb");
int i=0, aux=0, a=0, b=1;

if (!fp){
printf("Erro na abertura do arquivo.");
exit(-1);
}

for (i = 0; i<=100; i++){

aux = a + b;
a = b;
b = aux;
putc(aux, fp);
}
fclose(fp);
return 0;
}
```

2. Crie um código em C que lê o arquivo da questão anterior e escreve os valores lidos da sequência de Fibonacci na tela.

```
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
```


