// Write a program to implement Multilevel Queue Scheduling
// Assumption: all the processes user process and system process have same arrival time

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
	int pid[n], bt[n], su[n], ct[n], tat[n], wt[n];


	// input process ids of each process
	printf("Enter the process id of all the processes: ");
	for(i = 0; i < n; i++){
		scanf("%d", &pid[i]);
	}

	// burst time of each processes
	for(i = 0; i < n; i++){
		printf("Enter the burst time of process with id = p%d: ", pid[i]);
		scanf("%d", &bt[i]);
        printf("Enter system process(0)/ user Process(1): ");
        scanf("%d", &su[i]);
	}

    // sort the processes according to su
    int min, j;
	for(i = 0; i < n - 1; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(su[min] > su[j]){
				min = j;
			}
		}
		// swap i and min of su
		swap(&su[i], &su[min]);

		// swap i and min of pid
		swap(&pid[i], &pid[min]);

		// swap i and min of bt
		swap(&bt[i], &bt[min]);

	}

	// Step 2: Initialize complete timeline to min of arrival time
	int ctTimeline = 0;


	// Step3: 

	// calculate ct
	for(i = 0; i < n; i++){
		ctTimeline += bt[i];
		ct[i] = ctTimeline;
	}

	// calculate tat
	// tat = ct - at = ct - 0 = ct;
	for(i = 0; i < n; i++){
		tat[i] = ct[i];
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

	printf("ProcessId\tProcessType\tBurstTime\tCompleteTime\tTurnAroundTime\tWaitingTime\n");
	for(i = 0; i < n; i++){
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], su[i], bt[i], ct[i], tat[i], wt[i]);
	}

	printf("Avergate wait time: %f\n", avgWT);
	printf("Avergate turn around time: %f\n", avgTAT);
	
}
