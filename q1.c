#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main (int argc, char *argv[]){

	int inputArr[argc - 1];
	

	for(int x = 0; x< argc; x++){
		inputArr[x] = argv[x];
		printf["%d \n", inputArr[x]];
	}
	return 0;
}