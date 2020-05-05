#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#define STACK_SIZE (1024*1024)

static char child_stack[STACK_SIZE];

static int child_fn(){

    printf("PID: %ld\n", (long) getpid());
    printf("Network namespace:\n ");
    system("ip link");
    printf("\n\n");

    //system("dd if=/dev/zero of=./contfs bs=1024 count=30720");
    //system("chmod 777 ./contfs");
    //system("losetup /dev/loop0 ./contfs");
    //system("mkfs -t ext4 -m 1 -v /dev/loop0");
    //system("mount -t ext4 /dev/loop0 /home");
    //system("mount -t proc proc /proc");

    printf("\n\n");
    system("ps");
    char cmd_name[] = "ffdsfds";
    while (strcmp(cmd_name, "exit") != 0)
    {
        scanf("%s", cmd_name);
        printf("%s\n", cmd_name);
        system(cmd_name);         
    }

    return EXIT_SUCCESS;
}

int main(){
    printf("Original `net` Namespace:\n");
    system("ip link");
    pid_t child_pid = clone(
        child_fn, child_stack + STACK_SIZE,  CLONE_NEWPID | CLONE_NEWNET | CLONE_NEWNS | CLONE_NEWUTS | CLONE_NEWIPC | SIGCHLD, NULL);
    printf("clone()= %ld\n", (long) child_pid);
    waitpid(child_pid, NULL, 0);
    return EXIT_SUCCESS;
}