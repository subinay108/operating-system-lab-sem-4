// Write a program on SJF proces scheduling when arrival time is different for all processes

#include<stdio.h>


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int n;
	printf("Enter the no. of process: ");
	scanf("%d", &n);
	int i;
	int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];


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


	// ready queue
	// process with least arrival time will enter at first at readyQueue

	// process will enter to ready queue

	// then their burst time will compared to find the shortest job and selection
	// selected job will be completed first
	// after completion

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
	// Step 2: Initialize complete timeline to min of arrival time
	printf("min at: %d", at[0]);
	int ctTimeline = at[0];

	// Step3: select the process with minimum burst time
	for(i = 0; i < n; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(bt[min] > bt[j]){
				min = j;
			}
		}
		
		// swap i and min of at, pid, bt, ct
		swap(&at[i], &at[min]);
		swap(&bt[i], &bt[min]);
		swap(&pid[i], &pid[min]);


		// complete the shortest job
		printf("Burst time: \n");
		printf("i = %d j = %d min = %d\n", i , j, min);
		printf("bt - %d\n", bt[0]);
		printf("bt - %d\n", bt[1]);
		printf("bt - %d\n", bt[2]);
		printf("bt - %d\n", bt[3]);
		

		// i is the min
		ctTimeline += bt[i];
		ct[i] = ctTimeline;
	}

	// Step3: 


	

	// calculate ct
	// for(i = 0; i < n; i++){
	// 	ctTimeline += bt[i];
	// 	ct[i] = ctTimeline;
	// }

	// calculate tat
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
	float totalWT = 0, avgWT;
	for(i = 0; i < n; i++){
		totalWT += wt[i];
	}

	avgWT = totalWT / n;

	// avergate turn around time
	float totalTAT = 0, avgTAT;
	for(i = 0; i < n; i++){
		totalTAT += ct[i];
	}

	avgTAT = totalTAT / n;

	// print the table
	// Process Id, Arrival Time, Burst Time, Complete Time, Turn Around Time, Waiting Time

	printf("ProcessId\tArrivalTime\tBurstTime\tCompleteTime\tTurnAroundTime\tWaitingTime\n");
	for(i = 0; i < n; i++){
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
	}

	printf("Avergate wait time: %f\n", avgWT);
	printf("Avergate turn around time: %f\n", avgTAT);
	
}
