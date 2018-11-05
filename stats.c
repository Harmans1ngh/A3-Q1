#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

//declared the functions 
int findMin(void *input_ints);
int findMax(void *input_ints);
int findAvg(void *input_ints);
	
int main (int argc, char *argv[]){

	// check if there is an argument in the excecution. 
	if(argc < 2){
		printf("Sorry sir/maam this program cannot execute due to the fact that there are not enough arguments.\nPlease I request that you next time enter in some numbers as an argument so this program can execute with joy.\nThanks! and have a wonderful day. :) \n");
	exit(1);
	}
	int inputArr[argc - 1];
	void *min, *max, *avg;
	int temp;
	
	// populate array with input
	for(int x = 1; x< argc; x++){
		inputArr[x-1] = atoi(argv[x]);
		
	}
	
	//declare threads
	pthread_t maxThread, minThread, avgThread;
	
	//create the threads with error checking
	temp = pthread_create( &maxThread, NULL, (void *)findMax, (void *) inputArr);
	if (temp != 0){
		printf("Thread creation error");
		exit(1);
	}
	
	temp = pthread_create( &minThread, NULL, (void *)findMin, (void *) inputArr);
	if (temp != 0){
		printf("Thread creation error");
		exit(1);
	}	

	temp = pthread_create( &avgThread, NULL, (void *)findAvg, (void *) inputArr);
	if (temp != 0){
		printf("Thread creation error");
		exit(1);
	}
	
	//join the threads with error checking
	pthread_join(maxThread, &max);
	if (temp != 0){
		printf("Thread join error");
		exit(1);
	}

	pthread_join(minThread, &min);
	if (temp != 0){
		printf("Thread join error");
		exit(1);
	}

	pthread_join(avgThread, &avg);
	if (temp != 0){
		printf("Thread join error");
		exit(1);
	}

	//prints the avg, min, and max values
	printf("\nThe Average Value is: %ld \nThe Minimum Value is: %ld \nThe Maximum Value is: %ld \n\n", (uintptr_t)avg, (uintptr_t)min, (uintptr_t)max);
	
	return 0;
}

//function to find the max number
int findMax(void *input_vals) {
	int max=0;
	int *ptr = (int *)input_vals;

	while(*ptr != '\0'){
		if(*ptr > max){
			max = *ptr;
		}
		ptr++;
	}
	
	return max;
}

//function to find the min number
int findMin(void *input_vals) {
	int *ptr = (int *)input_vals;
	int min = *ptr;

	while(*ptr != '\0'){
		if(*ptr < min){
			min = *ptr;
		}
		ptr++;
	}
	return min;
}

//function to find the average number
int findAvg(void *input_vals) {
	int *ptr = (int *)input_vals;
	int sum=0;
	int temp=0;

	while(*ptr != '\0'){
		sum += *ptr;
		temp++;
		ptr++;
	}
	return (sum/temp);
}
