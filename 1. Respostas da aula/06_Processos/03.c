#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


int main(int argc, const char *argv[])
{
char *lista_de_argumentos[2]={"NULL, NULL"};
int i;
for (i=1; i<argc; i++){
//printf("%s\n", argv[i]);
if (fork() ==0)
{
lista_de_argumentos[0] = (char*)argv[i];
execvp(lista_de_argumentos[0],lista_de_argumentos);
exit(0);
}
}
wait(NULL);
return 0;
}
