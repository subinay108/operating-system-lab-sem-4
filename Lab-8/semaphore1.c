// Write a Program on semaphore use functions semctl, semget, semop, set_semvalue, del_semvalue
// Code(set_semvalue and del_semvalue)
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/ipc.h>

#define SEM_KEY 1234 // Key for semaphore set

// Function to set semaphore value
int set_semvalue(int sem_id){
    union semun{
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    }sem_union;

    sem_union.val = 1; // Set the semaphore value to 1
    
    if(semctl(sem_id, 0, SETVAL, sem_union) == -1){
        perror("semctl SETVAL");
        return 0;
    }

    return 1;
}

// Function to delete semaphore
void del_semvalue(int sem_id){
    if(semctl(sem_id, 0, IPC_RMID, 0) == -1){
        perror("semctl IPC_RMID");
        exit(1);
    }
}

int main(){
    int sem_id;

    // Create a semaphore set with one semaphore
    sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if(sem_id == -1){
        perror("semget");
        exit(1);
    }

    // Set semaphore value
    if(!set_semvalue(sem_id)){
        fprintf(stderr, "Failed to set semaphore value\n");
        exit(1);
    }

    printf("Semaphore value set\n");

    // Delete semaphore
    del_semvalue(sem_id);
    printf("Semaphore deleted\n");

    return 0;
}