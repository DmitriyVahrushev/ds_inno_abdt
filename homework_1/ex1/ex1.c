#include <stdio.h>
#include <unistd.h>

void main(){
    for(int i = 0; i < 3; i++){
        fork();
        sleep(5);
    }
    // int pid = fork();
    // printf("Hello world!\n");
    // if (pid < 0){
    //     printf("Something went wrong\n");
    // } else if (pid > 0){
    //     printf("Hello from parent\n");
    //     sleep(10);
    // } else
    // {
    //     printf("Hello from child\n");
    //     sleep(10);
    // }
}