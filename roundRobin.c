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

int main()
{
	
	return 0;
}