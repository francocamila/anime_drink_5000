#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include  <sys/types.h>

int main(){
char nomef[201];
char usuario[200];
int i;
int pid;
int fd[2];
pipe(fd);
pid = fork();
	if (pid ==0){
	printf("\nDigite seu nome:\n");
	gets(usuario);
	sprintf(nomef, usuario);
	write(fd[1], nomef, strlen(nomef)+1);
	usleep(500000);}
else{
i = -1;
do{
i++;
read(fd[0], nomef+i, 1);
}while(nomef[i]!='\0');
printf("Nome pelo pai: %s\n", nomef);
}
return 0;}
