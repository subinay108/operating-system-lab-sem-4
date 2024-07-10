//Experiment 11
//AIM: 
//Write a Program on Resource Request Algorithm. Wait for Graph.
//CODE:
#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10
int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
// Function prototypes
void request_resources(int pid, int request[]);
int check_request(int pid, int request[]);
int check_safety();
int main() 
{
	int num_processes, num_resources;
	printf("Enter the number of processes: ");
    	scanf("%d", &num_processes);
    	printf("Enter the number of resources: ");
   	scanf("%d", &num_resources);
    	// Initialize available resources
    	printf("Enter the number of available instances of each resource:\n");
    	for (int i = 0; i < num_resources; i++) 
	{
        	scanf("%d", &available[i]);
    	}
    	// Initialize maximum resources needed by each process
    	printf("Enter the maximum number of instances of each resource needed by each process:\n");
    	for (int i = 0; i < num_processes; i++) 
	{
        	printf("Process %d: ", i);
        	for (int j = 0; j < num_resources; j++) 
		{
            		scanf("%d", &maximum[i][j]);
            		need[i][j] = maximum[i][j];
        	}
    	}
    	// Initialize allocation of resources to each process
    	printf("Enter the number of instances of each resource currently allocated to each process:\n");
    	for (int i = 0; i < num_processes; i++) 
	{
        	printf("Process %d: ", i);
        	for (int j = 0; j < num_resources; j++) 
		{
            		scanf("%d", &allocation[i][j]);
            		need[i][j] -= allocation[i][j];
        	}
    	}
    	// Perform resource requests and check safety
    	int pid, request[MAX_RESOURCES];
    	printf("Enter the process ID and the requested resources for that process (-1 to exit):\n");
    	while (1) 
	{
       		printf("Process ID: ");
        	scanf("%d", &pid);
        	if (pid == -1)
            		break;  
        	printf("Requested resources: ");
        	for (int i = 0; i < num_resources; i++) 
		{
            		scanf("%d", &request[i]);
        	}
        	request_resources(pid, request);
        	if (check_safety()) 
		{
            		printf("Request granted safely.\n");
        	} 
		else 
		{
           		printf("Request cannot be granted safely. Try again later.\n");
        	}
    	}
    	return 0;
}

void request_resources(int pid, int request[]) {
    if (check_request(pid, request)) {
        for (int i = 0; i < MAX_RESOURCES; i++) {
            available[i] -= request[i];
            allocation[pid][i] += request[i];
            need[pid][i] -= request[i];
        }
    } else {
        printf("Invalid request.\n");
    }
}
int check_request(int pid, int request[]) {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        if (request[i] > need[pid][i] || request[i] > available[i])
            return 0;
    }
    return 1;
}

int check_safety() 
{
	int work[MAX_RESOURCES];
    	int finish[MAX_PROCESSES] = {0};   
    	// Initialize work to available
    	for (int i = 0; i < MAX_RESOURCES; i++) 
	{
        	work[i] = available[i];
    	}
    	// Check if process can finish
    	for (int i = 0; i < MAX_PROCESSES; i++) 
	{
        	if (!finish[i]) 
		{
            		int can_allocate = 1;
            		for (int j = 0; j < MAX_RESOURCES; j++) 
			{
                		if (need[i][j] > work[j]) 
				{
                    			can_allocate = 0;
                    			break;
                		}
            		}
            		if (can_allocate) 
			{
                		for (int j = 0; j < MAX_RESOURCES; j++) 
				{
                    			work[j] += allocation[i][j];
                		}
               			finish[i] = 1;
                		i = -1; // Start from the beginning again
            		}
        	}
    	}
    	// If all processes can finish, return true
    	for (int i = 0; i < MAX_PROCESSES; i++) 
	{
        	if (!finish[i])
           		return 0;
    	}
    	return 1;
}

