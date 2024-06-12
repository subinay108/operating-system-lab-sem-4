// Write a Program on Signal handling, sending singnals, signal interrupt
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sig_handler(int signum){
    printf("Received signal %d\n", signum);
}

int main(){
    if(signal(SIGINT, sig_handler) == SIG_ERR){
        perror("Signal registration failed");
        return 1;
    }
    if(signal(SIGTERM, sig_handler) == SIG_ERR){
        perror("Signal registration failed");
        return 1;
    }
    printf("Sending SIGINT\n");
    kill(getpid(), SIGINT);
    sleep(2);
    printf("Sending SIGTERM\n");
    kill(getpid(), SIGTERM);

    // Signal set operations
    sigset_t set;
    sigemptyset(&set); // initialize an empty signal set
    sigaddset(&set, SIGUSR1); // Add SIGUSR1 to the set
    if(sigismember(&set, SIGUSR1)){
        printf("SIGUSR1 is in the set\n");
    }else{
        printf("SIGUSR1 is not in the set\n");
    }

    return 0;
}