// Write a program on SJF proces scheduling when arrival time is 0 for all processes

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
	int pid[n],bt[n], ct[n], wt[n];

	int ctTimeline = 0;
	// arrival time is 0 for all process (assume)
	// since 'at' is 0 for all therefore 'tat' is same as 'ct'

	// input process ids of each process
	printf("Enter the process id of all the processes: ");
	for(i = 0; i < n; i++){
		scanf("%d", &pid[i]);
	}

	// input burst time of each processes
	for(i = 0; i < n; i++){
		printf("Enter the burst time of process with id = p%d: ", pid[i]);
		scanf("%d", &bt[i]);
	}

	// sort process with respect to burst time
	int min = 0;
	int j;
	for(i = 0; i < n - 1; i++){
		for(j = i; j < n; j++){
			if(bt[min] > bt[j]){
				min = j;
			}
		}
		// swap i and min of bt
		swap(&bt[i], &bt[min]);

		// swap i and min of pid
		swap(&pid[i], &pid[min]);

	}

	// calculate ct
	for(i = 0; i < n; i++){
		ctTimeline += bt[i];
		ct[i] = ctTimeline;
	}

	// calculate wt
	// wt = tat - bt = ct - bt;
	for(i = 0; i < n; i++){
		wt[i] = ct[i] - bt[i];
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
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], 0, bt[i], ct[i], ct[i], wt[i]);
	}

	printf("Avergate wait time: %f\n", avgWT);
	printf("Avergate turn around time: %f\n", avgTAT);
	
}
