// Program to use the popen() function to execute a command and capture its output

#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char buffer[1024];

    // Open a pipe to the 'ls' command
    /*
    The popen() function opens a pipe between the calling program and an executed command.
    This means that output of the command can be read by the calling program. 
    The popen() function takes two arguments:
        command: The command to be executed
        mode: The mode in which the pipe should be opened. 
              This can be either "r" for reading or "w" for writing
    The popen() function returns a file pointer to the pipe. This file pointer can be used to
    read or write to the pipe, depending on the mode in which the pipe was opened.
    */
    const char* command = "ls";
    fp = popen(command, "r");
    if(fp == NULL){
        perror("popen");
        exit(EXIT_FAILURE);
    }
    // print the command name
    printf("Command: %s\n", command);
    printf("output: \n");
    // Read the output of the command line by line
    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        printf("%s", buffer);
    }

    // close the pipe
    pclose(fp);

    return 0;
}