#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>
#include <string.h>

int main(int argc, const char *argv[]){
int i=0;
char command[300];
for (i=0; i<argc; i++){
strcpy(command, argv[i]);
system(command);
}
}

