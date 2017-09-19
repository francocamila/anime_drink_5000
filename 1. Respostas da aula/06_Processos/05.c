#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main(){
int kid=0;
for(kid=0; kid<3; ++kid){
int pid = fork();
pid_t id_atual=getpid();
if (pid<0){
exit(-1);
}
else if(pid==0){
Incrementa_Variavel_Global(id_atual);
printf("\nEsse é o processo Luke.\n");
exit(0);
}
else{
Incrementa_Variavel_Global(id_atual);
printf("\nEsse é o processo Darth Vader.\n");
wait(NULL);}}
}
