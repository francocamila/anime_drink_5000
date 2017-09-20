#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
char msgs[500];
int i;
int pid[2];
int fd[2];
pipe(fd);
pid[0] = fork();
if (pid[0]==0)
{
sprintf(msgs, "FILHO1: Quando o vento passa, é a bandeira que se move.");
write(fd[1], msgs, strlen(msgs)+1);
usleep(500000);
}
else
{
pid[1]=fork();
if(pid[1]==0)
{
i=-1;
do
{
i++;
read(fd[0], msgs+i, 1);
}while(msgs[i]!='\0');
printf(" %s\n", msgs);
sprintf(msgs, "FILHO2: Não, é o vento que se move.");//
write(fd[1], msgs, strlen(msgs)+1);
}
else
{
usleep(500000);
}
//pai:
i=-1;
do
{
i++;
read(fd[0], msgs+i, 1);
}while(msgs[i]!='\0');
printf(" %s\n", msgs);
puts("PAI: Os dois se enganam. É a mente dos senhores que se move.");//escrever direto
}
exit(0);
}
