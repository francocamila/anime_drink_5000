1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int	fd[2];
pipe(fd);
pid = fork();
```
Um pipe. Porque o pipe é criado e compartilhado entre os dois processos. 

(b)
```C
int pid;
int	fd[2];
pid = fork();
pipe(fd);
```
Dois pipes. Pois primeiro há um fork com duas posições diferentes na memória para cada processo, e haverá um pipe diferente para cada processo.

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?

SIGHUP- Corte: sinal emitido aos processos associados a um terminal quando este se "desconecta". Este sinal também é emitido a cada processo de um grupo quando o chefe termina sua execução. 
SIGQUIT- Abandono: sinal emitido aos processos do terminal quando com a tecla de abandono (QUIT ou CTRL+d) do teclado são adicionadas.
SIGILL-Instrução ilegal: emitido quando uma instrução ilegal é detectada.
SIGBUS- Emitido em caso de violação da segmentação: tentativa de acesso a um dado fora do domínio de endereçamento do processo. 
SIGSYS- Argumento incorreto de uma chamada de sistema.

3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?

Não se deve contar com o sinal chegando precisamente, pois em um ambiente de multiprocessamento há tipicamente uma certa quantidade de delay involvida. 
