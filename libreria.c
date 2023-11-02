#include <libreria.h>
#include <stdio.h>

#define MaxLineLength 1024

int head(int N){
    char line[MaxLineLength];
    int count = 0;

    while (count < N){
        if(fgets(line, MaxLineLength, stdin) == NULL){
            break;
        } else {
            printf("%s", line);
            count++;
        }
    }
    return 0;
}

int longlines(int N){
    
}