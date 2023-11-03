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
    /*Inicializa la lista lines*/

    if (lines == NULL){
        fprintf(stderr, "Error");
        return -1;
    }/*Comprueba que se ha creado correctamente lines*/

    while (fgets(line, MaxLineLength, stdin)){
    /*Mientras que se obtengan lineas*/    
    
        if (line[strlen(line) - 1] == '\n'){
            line[strlen(line) - 1] == '\0';
        } /*Quita el ultimo elemento de la linea si fuera un salto de linea*/

        lines[lineCount] = strdup(lines);
        /*Añade la linea a la lista de lineas lines*/

        if (lines[lineCount] == NULL){
            fprintf(stderr, "Error");
            return -1;
        } /*Verifica que se haya añadido algo en el ultimo elemento de lines*/

        lineCount++;
        /*Incrementa el contador de las lineas introducidas*/

        if(lineCount >= capacity){
            capacity *= 2;
            lines = (char**)malloc(sizeof(char*) * capacity);
            /*Actualiza la capacidad de lines si se llega a su máximo, multiplicando la misma por 2*/

            if (lines == NULL){
                fprintf(stderr, "Error");
                return -1;
            }/*Comprueba que al hacer la actualización de lines se haya creado correctamente y no pierda datos*/
        }
        
    }

    qsort(lines, lineCount, sizeof(char*), compareLines);
    /*Ordena las line dentro de lines haciendo uso de la funcion compareLines, 
    con lo que hacemos un cambio si se obtiene un positivo al utilizar la funcion*/

    int linesToShow = (N < lineCount) ? N : lineCount;
    /* int linesToShow = 0
        if (N < lineCount) {
            linesToShow = N;
        } else {
            linesToShow = lineCount;
        }
    */

    for (int i = 0; i < linesToShow; i++){
        printf("%s\n", lines[i]);
    }/*Imprimimos las lineas*/

    free(lines);
    /*Liberamos de memoria la lista lines*/

    return 0;
    
}

int compareLines(const void* a, const void* b){
    const char* line1 = *(const char**)a;
    const char* line2 = *(const char**)b;
    return strlen(line2)-strlen(line1);
} /*Funcion que se utiliza para comparar las lineas con el objetivo de utilizarla para la ordenación,
    devuelve un numero negativo si la primera linea es mayor que la segunda y positivo si la segunda linea es mayor que la primera*/