#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("ps aux k-pcpu");
	// system("date +%s%3N");
	alarm(1);
}

void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("Processo terminado!\n");
	exit(0);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	signal(SIGINT, sig_handler);	
	while(1);
	return 0;
}
