#include <stdio.h>
#include <unistd.h>
#include <string.h>

void main(){
    char cmd_name[] = "ffdsfds";
    while (strcmp(cmd_name, "exit") != 0)
    {
        scanf("%s", cmd_name);
        //printf("Your command is %s \n", cmd_name);
        system(cmd_name);         
    }
    
}