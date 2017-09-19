#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>
#include <string.h>

int main(int argc, const char *argv[]){
int i;
char *user_input[2]={NULL,NULL};
	for (i=1; i<argc; i++){
		if (fork() == 0){
		user_input[0]=(char*)argv[i];
		execvp(user_input[0], user_input);
		exit(0);
		}
	}	
wait(NULL);
}
