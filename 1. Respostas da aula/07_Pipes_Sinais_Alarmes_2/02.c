#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include  <sys/types.h>

int main(){
char msg1p[100];
char msg2p[100];
char msg1f[100];
char msg2f[100];

int i;
int pid;
int fd[2];
pipe(fd);
pid=fork();
	if(pid == 0){
sprintf(msg1f, "FILHO: Não, você matou o meu pai! Obi Wan me disse!!!\n");
write(fd[1], msg1f, strlen(msg1f)+1);
usleep(500000);}
else{
i = -1;
do{
i++;
read(fd[0], msg1f+i, 1);}
while(msg1f[i] != '\0');
printf("\n%s", msg1f);
sprintf(msg1p, "PAI: Não, EU SOU O SEU PAI.");
write(fd[1], msg1p, strlen(msg1p)+1);
usleep(1000000);
}
	if(pid == 0){
i = -1;
do{
i++;
read(fd[0], msg1p+i, 1);}
while(msg1p[i] != '\0');
printf("\n%s", msg1p);
sprintf(msg2f, "FILHO: NÃAAAAAAAAAAAAAAAAAAAAAAAAAOOOOOOOOOO!\n");
write(fd[1], msg2f, strlen(msg2f)+1);
usleep(1500000);}
else{
usleep(2000000);
i = -1;
do{
i++;
read(fd[0], msg2f+i, 1);}
while(msg2f[i] != '\0');
printf("\n%s", msg2f);
puts( "PAI: hehehehehehehehehe");
}
wait(NULL);
return 0;
}



