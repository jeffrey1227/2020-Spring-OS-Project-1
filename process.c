#define _GNU_SOURCE
#define _USE_GNU
#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>

#define PRINTK 333
#define GET_TIME 334

const long n = 1E9;

int main(int argc, char* argv[]){

    char* name = argv[1];
    pid_t pid = getpid();
    long exec_time = strtol(argv[2], NULL, 10);//convert to long int

    long start_time = syscall(GET_TIME);//start executing

    for(int i = 0; i < exec_time; i++){
        volatile unsigned long j;
        for(j = 0; j < 1000000UL; j++); 
    }
    
    long end_time = syscall(GET_TIME);//end executing

    syscall(PRINTK, getpid(), start_time, end_time);
    //fprintf(stderr, "[Project1] %d %ld.%09ld %ld.%09ld\n", getpid(), \
            start_time / n, start_time % n, end_time / n, end_time % n);

    return 0;
}
