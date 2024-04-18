// Write a Program on semaphore use functions semctl, semget, semop, set_semvalue, del_semvalue
// Code(semaphore_p and semaphore_v)
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/ipc.h>

#define SEM_KEY 1234 // Key for semaphore set

// Function for semaphore P(wait) operation
void semaphore_p(int sem_id){
    struct sembuf sem_op;
    sem_op.sem_num = 0; // Semaphore index in the set
    sem_op.sem_op = -1; // P operation (decrement semaphore value)
    sem_op.sem_flg = 0; // No flags
    if(semop(sem_id, &sem_op, 1) == -1){
        perror("semop P");
        exit(1);
    }
}

// Function for semaphore V(signal) operation
void semaphore_v(int sem_id){
    struct sembuf sem_op;
    sem_op.sem_num = 0; // Semaphore index in the set
    sem_op.sem_op = 1; // V operation (increment semaphore value)
    sem_op.sem_flg = 0; // No flags
    if(semop(sem_id, &sem_op, 1) == -1){
        perror("semop V");
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

    // Set initial semaphore value to 1
    if(semctl(sem_id, 0, SETVAL, 1) == -1){
        perror("semctl SETVAL");
        exit(1);
    }

    // Perform semaphore P(wait) operation
    semaphore_p(sem_id);
    printf("Semaphore acquire!\n");
    
    // Perform some critical section operations here

    // Perform semaphore V(signal) operation
    semaphore_v(sem_id);
    printf("Semaphore released!\n");

    // Remove the semaphore set
    if(semctl(sem_id, 0, IPC_RMID, 0) == -1){
        perror("semctl IPC_RMID");
        exit(1);
    }

    return 0;
}