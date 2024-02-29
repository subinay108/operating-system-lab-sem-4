// Write a program on duplicating a process image, waiting for a process, zombie
#include<stdio.h>
#include<stdlib.h>
#include<sys/ptrace.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/unistd.h>
#include<fcntl.h>
#include<errno.h>
#define BUFFER_SIZE 4096

void copy_process_image(pid_t pid, const char *output_path){
	char mem_path[64];
	snprintf(mem_path, sizeof(mem_path), "/proc/%d/mem", pid);
	int mem_fd = open(mem_path,O_RDONLY); 
	if(mem_fd == -1){
		perror("Failed to open/proc/PID/mem");
		return;
	}
	int output_fd = open(output_path, O_WRONLY |O_CREAT | O_TRUNC, 0777);
	if(output_fd == -1){
		perror("Failed to create output file");
		close(mem_fd);
		return;
	}
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	while((bytes_read = pread(mem_fd, buffer, BUFFER_SIZE, 0)) > 0){
		if(write(output_fd, buffer, bytes_read) != bytes_read){
			perror("Failed to write to output file");
			close(mem_fd);
			close(output_fd);
			return;
		}
	}
	close(mem_fd);
	close(output_fd);
	printf("Process image copied to %s\n", output_path);
}

int main(int argc, char *argv[]){
	if(argc != 3){
		fprintf(stderr, "Usage: %s <pid><output_path>\n", argv[0]);
		return 1;
	}
	pid_t pid = atoi(argv[1]);
	const char*output_path = argv[2];
	copy_process_image(pid, output_path);
	return 0;
}



