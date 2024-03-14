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
		printf("Overflow\n");
	}
}

void dequeue(){
	if(front == -1 || front == rear + 1){
		printf("Underflow\n");
	}else{
		front++;
	}
}

int isQueueEmpty(){
	if(rear == -1 || front == rear + 1){
		return 1;
	}
	return 0;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

float calculateAverage(int* arr, int size){
	int i;
	float total = 0, avg = 0;
	for(i = 0; i < size; i++){
		total += arr[i];
	}
	avg = total / size;
	return avg;
}

int main()
{
	int n;
	printf("Enter the no. of process: ");
	scanf("%d", &n);
	int i;
	int pid[n], at[n], bt[n],temp_bt[n], ct[n], tat[n], wt[n], rt[n];


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

	// input time quantum
	int tq;
	printf("Enter time quantum: ");
	scanf("%d", &tq);

	// sort process according to arrival time
	int min, j;
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
	
	// keep 1 copy of bt
	for(i = 0; i < n; i++){
		temp_bt[i] = bt[i];
	}
	
	// initialize response time arr to -1
	for(i = 0; i < n; i++){
		rt[i] = -1;
	}

	// insert the first process into the readyQueue
	enqueue(0);
	int readyProcess = 1;
	int processTimeline = at[0];
	int lapTime = 0;
	
	// loop untill all the process(es) is not completed
	int completedProcess = 0; 
	while(completedProcess < n){
		int index = readyQueue[front];
		if(rt[index] == -1){
			rt[index] = processTimeline - at[index];
		}
		temp_bt[index]--;
		processTimeline++;
		lapTime++;
		
		while(readyProcess < n && at[readyProcess] == processTimeline){
			enqueue(readyProcess);
			readyProcess++;
		}

		if(temp_bt[index] == 0){
			ct[index] = processTimeline;
			completedProcess++;
			dequeue();
			lapTime = 0;
		}else if(lapTime == tq){
			dequeue();
			enqueue(index);
			lapTime = 0;
		}

	}
	
	// tat = ct - at
	for(i = 0; i < n; i++){
		tat[i] = ct[i] - at[i];
	}

	// calculate wt
	// wt = tat - bt;
	for(i = 0; i < n; i++){
		wt[i] = tat[i] - bt[i];
	}

	// average wait time
	float avgWT = calculateAverage(wt, n);
	
	// avergate turn around time
	float avgTAT = calculateAverage(tat, n);
	
	// average response time
	float avgRT = calculateAverage(rt, n);

	// print the table
	// Process Id, Arrival Time, Burst Time, Complete Time, Turn Around Time, Waiting Time

	printf("ProcessId\tArrivalTime\tBurstTime\tCompleteTime\tTurnAroundTime\tWaitingTime\tResponseTime\n");
	for(i = 0; i < n; i++){
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
	}

	printf("Average wait time: %f\n", avgWT);
	printf("Average turn around time: %f\n", avgTAT);
	printf("Average response time: %f\n", avgRT);
	
	return 0;
}