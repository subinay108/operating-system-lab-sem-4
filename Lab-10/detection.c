// Write a Program to detect Deadlock
#include<stdio.h>

static int mark[20];
int i, j, np, nr;
int main(){
	int alloc[10][10], request[10][10], avail[10], r[10], w[10];
	printf("Enter the no of process: ");
	scanf("%d", &np);
	printf("Enter the no. of resources: ");
	scanf("%d", &nr);
	
	for(i = 0; i < nr; i++){
		printf("Total amount of the resources R%d: ", i + 1);
		scanf("%d", &r[i]);
	}
	
	printf("Enter the request matrix:\n");
	for(i = 0; i < np; i++){
		for(j = 0; j < nr; j++){
			scanf("%d", &request[i][j]);
		}
	}
	printf("Enter the allocation matrix:\n");
	for(i = 0; i < np; i++){
		for(j = 0; j < nr; j++){
			scanf("%d", &alloc[i][j]);
		}
	}
	
	// Available Resource Calculation
	for(j = 0; j< nr; j++){
		avail[j] = r[j];
		for(i = 0; i < np; i++){
			avail[j] -= alloc[i][j];
		}
	}
	
	// marking processes with zero allocation
	for(i = 0; i < np; i++){
		int count = 0;
		for(j = 0; j < nr; j++){
			if(alloc[i][j] == 0){
				count++;
				break;
			}
		}
		if(count == nr){
			mark[i] = 1;
		}
	}
	
	// initialize w with avail
	for(j = 0; j < nr; j++){
		w[j] = avail[j];
	}
	
	// mark processes with request less than or equal to W
	for(i = 0; i < np; i++){
		int canbeprocessed = 0;
		if(mark[i] != 1){
			for(j = 0; j < nr; j++){
				if(request[i][j] <= w[j]){
					canbeprocessed = 1;
				}else{
					canbeprocessed = 0;
					break;
				}
			}
		}
		if(canbeprocessed){
			mark[i] = 1;
			for(j = 0; j < nr; j++){
				w[j] += alloc[i][j];
			}
		}
	}
	
	// checking for unmarked processes
	int deadlock = 0;
	for(i = 0; i < np; i++){
		if(mark[i] != 1){
			deadlock = 1;
			break;
		}
	}
	
	if(deadlock){
		printf("Deadlock detected");
	}else{
		printf("No Deadlock possible");
	}

}