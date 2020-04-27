#include <stdio.h>
#include <unistd.h>
#include <string.h>

void main(){
    char cmd_name[10];
    while (1)
    {
        scanf("%s", cmd_name);
        //printf("Your command is %s \n", cmd_name);
        system(cmd_name);         
    }
    
}