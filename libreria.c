#include <libreria.h>
#include <stdio.h>
#include <stdlib.h>

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
    char** lines = NULL;
    char line[MaxLineLength];
    int lineCount = 0;
    int capacity = 10;
    
    lines = (char**)malloc(sizeof(char*) * capacity);

    if (lines == NULL){
        fprintf(stderr, "Error");
        return -1;
    }

    while (fgets(line, MaxLineLength, stdin)){

        if (line[strlen(line) - 1] == '\n'){
            line[strlen(line) - 1] == '\0';
        }

        lines[lineCount] = strdup(lines);

        if (lines[lineCount] == NULL){
            fprintf(stderr, "Error");
            return -1;
        }

        lineCount++;

        if(lineCount >= capacity){
            capacity *= 2;
            lines = (char**)malloc(sizeof(char*) * capacity);

            if (lines == NULL){
                fprintf(stderr, "Error");
                return -1;
            }
        }
        
    }

    qsort(lines, lineCount, sizeof(char*), compareLines);

    int linesToShow = (N < lineCount) ? N : lineCount;

    for (int i = 0; i < linesToShow; i++){
        printf("%s\n", lines[i]);
    }
    free(lines);

    return 0;
    
}

int compareLines(const void* a, const void* b){
    const char* line1 = *(const char**)a;
    const char* line2 = *(const char**)b;
    return strlen(line2)-strlen(line1);
}