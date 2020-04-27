#include <stdio.h>
#include <unistd.h>
#include <string.h>

void main(){
    printf("Terminal\n");
    char cmd_name[10];
    while (1)
    {
        scanf("%s", cmd_name);
        printf("Your command is %s \n", cmd_name);
        if (strcmp("pwd", cmd_name) == 0){
            printf("Success\n");
            char cwd[100];
            getcwd(cwd, sizeof(cwd));
            //printf("%s", system("pwd"));
            printf("%s", cwd);
        }
        else if (strcmp("pwd", cmd_name) == 0)
        {
            
        }
        else
        {
            printf("No such command \n");
        }
        
    }
    
}