// Write a program on Round Robin Scheduling
#include<stdio.h>

#define MAX_SIZE 100

int readyQueue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int process){
	if(front == -1 && rear == -1){
		front = 0;
		rear = 0;
		readyQueue[rear] = process;
	}else if(rear != MAX_SIZE){
		rear++;
		readyQueue[rear] = process;
	}else{
		printf("Overflow");
	}
}

void dequeue(){
	if(front == -1 || front == rear + 1){
		printf("Underflow");
	}else{
		front++;
	}
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int n;
	printf("Enter the no. of process: ");
	scanf("%d", &n);
	int i;
	int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], rt[n];


	// input process ids of each process
	printf("Enter the process id of all the processes: ");
	for(i = 0; i < n; i++){
		scanf("%d", &pid[i]);
	}

	// input arrival time and burst time of each processes
	for(i = 0; i < n; i++){
		printf("Enter the arrival time and burst time of process with id = p%d: ", pid[i]);
		scanf("%d %d", &at[i], &bt[i]);
	}

	// Step1: Sort the process with respect to arrival time
	int min = 0;
	int j;
	for(i = 0; i < n - 1; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(at[min] > at[j]){
				min = j;
			}
		}
		// swap i and min of at
		swap(&at[i], &at[min]);

		// swap i and min of pid
		swap(&pid[i], &pid[min]);

		// swap i and min of bt
		swap(&bt[i], &bt[min]);
	}

	// Step2: 



	
	return 0;
}