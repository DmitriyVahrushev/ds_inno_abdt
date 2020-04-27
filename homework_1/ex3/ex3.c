#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
    FILE *fptr;
    char text[100];
    fptr = fopen("ex3_example.txt", "r");
    if(fptr == NULL)
    {
      printf("Error!");   
      exit(1);             
    }
    fork();
    fscanf(fptr, "%s", text);
    sleep(10);
    printf("%s", text);
    fclose(fptr);
}