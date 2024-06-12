// Program4: Child Process type - orphan process
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    pid_t a, n;
    printf("\n Before fork \n");
    a = fork();
    
    if(a == 0){
        sleep(3);
        printf("\nI am child having id = %d", getpid());
        printf("\n Parent id = %d", getppid());
    }else{
        // wait(NULL);
        // sleep(3);
        printf("\n My chld id = %d", a);
        printf("\n I am parent having id = %d", getpid());
    }
    return 0;
}

