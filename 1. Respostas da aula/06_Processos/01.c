#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
 
int main(){
int kid=0;
for(kid=0; kid<3; ++kid){
int pid = fork();
if (pid<0){
exit(-1);
}
else if (pid>0){
printf("\nEsse é o processo Darth Vader.\n");
}
else{
printf("\nEsse é o processo Luke.\n");
exit(0);
}
}
}

