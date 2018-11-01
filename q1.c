#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main (int argc, char *argv[]){

	if(argc < 2){
		printf("sorry sir/maam this program cannot execute due to the fact that there are not enough arguments.\n
			please I request that you next time enter in some numbers as an argument so this program can execute with joy.\n
			Thanks! and have a nice day.");
	}
	int inputArr[argc - 1];
	int min, max, avg;
	

	for(int x = 1; x< argc; x++){
		inputArr[x] = atoi(argv[x]);
		printf("%d \n", inputArr[x]);
	}

	pthread_t maxThread, minThread, avgThread;
	pthread_create(&maxThread, NULL, findMax, inputArr);
	pthread_create(&minThread, NULL, findMin, inputArr);
	pthread_create(&avgThread, NULL, findAvg, inputArr);
	return 0;
}
