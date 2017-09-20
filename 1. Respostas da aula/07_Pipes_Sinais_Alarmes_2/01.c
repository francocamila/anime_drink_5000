#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include  <sys/types.h>

int main()
{
	int pid, f=0, p=0;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	// Cria o pipe
	pipe(fd);
	// Cria o processo
	pid = fork();
	// Codigo do filho
	if(pid == 0){
	for(f=0; f<11; f++){
	read(fd[0], &f, sizeof(int));
	printf("\n%d", f);
	}}
	else{
	for(p=0; p<11; p++){
 	write(fd[1], &p, sizeof(int));}
	}
wait(NULL);
return 0;
} 
