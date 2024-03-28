#include<stdio.>
#include<signal.h>

int main(int argc, char **argv){
    void InterruptHandler(), InitHandler(), n = 0;
    signal(SIGINT, InterruptHandler);
    printf("This is not required!");
}