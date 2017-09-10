#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()

int main(int argc, const char * argv[])
{
	int fp, i;
	char string[20]={"Ola mundo!"};
	
	fp = open("ola_mundo.txt", O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
		for(i=0; string[i]; i++){
		write(fp, &(string[i]), 1);} // Grava a string, caractere a caractere	
	write(fp, "\n", 1);
	close(fp);

	return 0;
}
