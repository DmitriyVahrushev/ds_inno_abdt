#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//при копировании процесса создается копия дискриптора файла, 
//но эта копия указыает на ту же структуру в ядре с описанием файла, что и исходный процесс

// демонстрация. оба процесса считывают по слову. при этом, после того как один из процессов считал слово
// в описании файла обновляется значение сдвига каретки в файле. поэтому второй процесс считывает уже
// второе слово. 
// но если закрыть файл с fclose в одном из процессов, то с ним не получится работать в другом процессе
// так как, как мне кажется , дело в сопадающем значение дескрипторов файлов
void main(){
    FILE *fptr;
    //FILE *fptr2;
    char text[100];
    fptr = fopen("ex3_example.txt", "r");
    //fptr = fopen("ex3_example2.txt", "w");
    if(fptr == NULL)
    {
      printf("Cannot open file! \n");   
      exit(1);             
    }
    int pid = fork();
    if (pid < 0){
      printf("Error occured \n");
      exit(1);
    } else if (pid > 0){
      fscanf(fptr, "%s", text);
      printf("%s \n", text);
      //fclose(fptr);
    } else{
      fscanf(fptr, "%s", text);
      printf("%s \n", text);
      //fclose(fptr);
    }
    fclose(fptr);
}