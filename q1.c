#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int findMin(void *input_ints);
int findMax(void *input_ints);
int findAvg(void *input_ints);
	
int main (int argc, char *argv[]){

	if(argc < 2){
		printf("Sorry sir/maam this program cannot execute due to the fact that there are not enough arguments.\nPlease I request that you next time enter in some numbers as an argument so this program can execute with joy.\nThanks! and have a wonderful day. :) \n");
	}
	int inputArr[argc - 1];
	void *min, *max, *avg;
	int temp;
	

	for(int x = 1; x< argc; x++){
		inputArr[x] = atoi(argv[x]);gcc
		//printf("%d \n", inputArr[x]);
	}

	pthread_t maxThread, minThread, avgThread;
	temp = pthread_create( &maxThread, NULL, (void *)findMax, (void *) inputArr);
	temp = pthread_create( &minThread, NULL, (void *)findMin, (void *) inputArr);
	temp = pthread_create( &avgThread, NULL, (void *)findAvg, (void *) inputArr);
	
	pthread_join(maxThread, &max);
	pthread_join(minThread, &min);
	pthread_join(avgThread, &avg);

	printf("%d, %d, %d", min, max, avg);
	
	return 0;
}

int findMax(void *input_ints) {
	int max=0;
	int *ptr = (int *)input_ints;

	while(*ptr != '\0'){
		if(*ptr > max){
			max = *ptr;
		}
		ptr++;
	}
	return max;
}

int findMin(void *input_ints) {
	int *ptr = (int *)input_ints;
	int min = *ptr;

	while(*ptr != '\0'){
		if(*ptr < min){
			min = *ptr;
		}
		ptr++;
	}
	return min;
}


int findAvg(void *input_ints) {
	int *ptr = (int *)input_ints;
	int sum=0;
	int temp;

	while(*ptr != '\0'){
		sum += *ptr;
		temp++;
		ptr++;
	}
	return (sum/n);
}
