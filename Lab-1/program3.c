// Program3: Child Process with id
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t a, n;
    printf("\n Before fork \n");
    a = fork();
    
    if(a == 0){
        printf("\nI am child having id = %d", getpid());
        printf("\n Parent id = %d", getppid());
    }else{
        printf("\n My chld id = %d", a);
        printf("\n I am parent having id = %d", getpid());
    }
    return 0;
}

