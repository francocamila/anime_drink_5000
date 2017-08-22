Para todas as questões, compile-as com o gcc e execute-as via terminal.

1. Crie um "Olá mundo!" em C.

#include <stdio.h>

int main (int argc, char **argv)
{
printf( "Olá mundo!");
return 0; 
}


2. Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Ola Eu
```

#include <stdio.h>

int main(int argc, char **argv)
{
char nome[60];
printf("Digite o seu nome:");
scanf("%s", nome);
printf ("\n Olá %s \n", nome);
}



3. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu Mesmo
```

biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/2$ ./olahumano
Digite o seu nome:Eu Mesmo

 Olá Eu 

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_1
$ Digite o seu nome: "Eu Mesmo"
```

biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/2$ ./olahumano
Digite o seu nome:"Eu Mesmo"

 Olá "Eu 

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_1
```

biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/2$ echo Eu | ./olahumano
Digite o seu nome:
 Olá Eu 

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_1
```

biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/2$ echo Eu Mesmo | ./olahumano
Digite o seu nome:
 Olá Eu

 
(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Eu Mesmo" | ./ola_usuario_1
```

biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/2$ echo "Eu Mesmo" | ./olahumano
Digite o seu nome:
 Olá Eu

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_1 < ola.txt
```

biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/2$ ./olahumano < ola.txt
Digite o seu nome:
 Olá Ola

4. Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e *argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu
$ Ola Eu
```

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{ int i;
printf("\nOla");
for (i =1; i<argc; i++)
{
printf(" %s\n", argv[i]);
}
}

5. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_2 Eu Mesmo
```

biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/4$ ./olahumano2 Eu Mesmo

Ola Eu
 Mesmo

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_2 "Eu Mesmo"
```

biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/4$ ./olahumano2 "Eu Mesmo"

Ola Eu Mesmo


(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_2
```
biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/4$ echo Eu | ./olahumano2

Ola

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```

biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/4$ echo Eu Mesmo | ./olahumano2

Ola

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```
biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/4$ echo "Eu Mesmo" | ./olahumano2

Ola

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_2 < ola.txt
```
biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/4$ echo Ola mundo cruel! > ola.txt
biloca@biloca-X450LA:~/Desktop/Embarcados/Questoes/03_GCC/4$ ./olahumano2 < ola.txt

Ola


6. Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':

```bash
$ ./ola_usuario_3 Eu
$ Ola Eu
$ Numero de entradas = 2
```

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{ int i;
printf("\nOla");
for (i =1; i<argc; i++)
{
printf(" %s", argv[i]);
}
printf("\n Numero de entradas: %d\n", i);
}



7. Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':

```bash
$ ./ola_argumentos Eu Mesmo e Minha Pessoa
$ Argumentos: Eu Mesmo e Minha Pessoa
```

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{ int i;
printf("\nArgumentos:");
for (i =1; i<argc; i++)
{
printf(" %s", argv[i]);
}
printf("\n");
}


8. Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo:
`int Num_Caracs(char *string);` Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.

#include "num_caracs.h"

int Num_Caracs(char *palavra)
{ 
int i= 0;
while ((palavra[i]) != '\0')
{
i++;
}
return i;
}

Protótipo 'num_caracs.h':

int Num_Caracs(char *palavra);


9. Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':

```bash
$ ./ola_num_caracs_1 Eu Mesmo
$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
$ Argumento: Eu / Numero de caracteres: 2
$ Argumento: Mesmo / Numero de caracteres: 5
```

#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"

int main(int argc, char *argv[])
{
int i=0; 
for (i=0; i<argc; i++)
{
printf("Argumento: %s", argv[i]);
printf("\n Numero de Caracteres: %d\n",Num_Caracs(argv[i]));
}
return 0;
}


10. Crie um Makefile para a questão anterior.


ola_num_caracs_1: ola_num_caracs1.o num_caracs.o
	gcc $(CFLAGS) -o ola_num_caracs_1 ola_num_caracs_1.o num_caracs.o
ola_num_caracs_1.o: ola_num_caracs_1.c num_caracs.h
	gcc $(CFLAGS) -c ola_num_caracs_1.c
num_caracs.o: num_caracs.c num_caracs.h
	gcc $(CFLAGS) -c num_caracs.c
clean:
	rm -f *.o ola_num_caracs_1


11. Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':

```bash
$ ./ola_num_caracs_2 Eu Mesmo
$ Total de caracteres de entrada: 25
```

#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"

int main(int argc, char *argv[])
{
int i=0; int n=0;
for (i=0; i<argc; i++)
{
n += Num_Caracs(argv[i]);
}
printf("\n Numero de Caracteres: %d\n",n);
return 0;
}

12. Crie um Makefile para a questão anterior.

ola_num_caracs_2: ola_num_caracs2.o num_caracs.o
	gcc $(CFLAGS) -o ola_num_caracs_2 ola_num_caracs_2.o num_caracs.o
ola_num_caracs_2.o: ola_num_caracs_2.c num_caracs.h
	gcc $(CFLAGS) -c ola_num_caracs_2.c
num_caracs.o: num_caracs.c num_caracs.h
	gcc $(CFLAGS) -c num_caracs.c
clean:
	rm -f *.o ola_num_caracs_2
