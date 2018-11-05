#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *findMin() {}
void *findMax() {}
void *findAvg() {}
	
int main (int argc, char *argv[]){

	if(argc < 2){
		printf("Sorry sir/maam this program cannot execute due to the fact that there are not enough arguments.\nPlease I request that you next time enter in some numbers as an argument so this program can execute with joy.\nThanks! and have a wonderful day. :) \n");
	}
	int inputArr[argc - 1];
	int min, max, avg;
	

	for(int x = 1; x< argc; x++){
		inputArr[x] = atoi(argv[x]);
		printf("%d \n", inputArr[x]);
	}

	pthread_t threads[maxThread];
	pthread_t threads[minThread];
	pthread_t threads[avgThread];
	pthread_create(&maxThread, NULL, findMax, NULL);
	pthread_create(&minThread, NULL, findMin, inputArr);
	pthread_create(&avgThread, NULL, findAvg, inputArr);
	
	
	return 0;
}
