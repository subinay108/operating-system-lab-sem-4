// Using pipe function to show how a parent process and child process communicate
// using the pipe function

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(){
    /*
    It creates two descriptors.
    first one is connected to read from the pipe and other one is connected to 
    write into the pipe*/
    int pipefds[2]; // Array to store file descriptors for the pipe

    pid_t pid;
    
    // Create the pipe
    if(pipe(pipefds) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    // Fork a child process
    pid = fork();
    if(pid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    // Parent process
    if(pid > 0){
        printf("Parent proces writing to pipe...\n");
        // close the read end of the pipe in the parent
        close(pipefds[0]);

        // Write data to the pipe
        const char *data = "Hello from the parent!\n";
        if(write(pipefds[1], data, strlen(data)) == -1){
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Cllose the write end of the pipe in the parent
        close(pipefds[1]);

        printf("Parent process waiting for child ... \n");
        wait(NULL); // Wait for the child process to finish       
    }else{ 
        // Child process
        printf("Child process reading from pipe...\n");

        // Close the write end of the pipe in the child
        close(pipefds[1]);

        // Read data from the pipe
        char buffer[100];
        int bytes_read = read(pipefds[0], buffer, sizeof(buffer));
        if(bytes_read == -1){
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Print the data received
        printf("Child process received: %s", buffer);

        // Close the read end of the pipe in the child
        close(pipefds[0]);
    }
    return 0;
}