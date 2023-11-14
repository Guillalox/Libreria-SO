#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLineLength 1024

int head(int N){
    // Declaración de un array para almacenar las primeras N líneas
    char line[MaxLineLength];
    int count = 0;  // Contador de líneas leídas
    // Mientras no se haya alcanzado el numero de lineas deseado
    while (count < N){
        if(fgets(line, MaxLineLength, stdin) == NULL){
            // Leer líneas desde la entrada estándar y almacenarlas en el array
            break;
        } else {
             // Imprimir las primeras N líneas en orden
            printf("%s", line);
            count++;
        }
    }
    return 0;
}
int tail(int N) {
    // Declaración de un array de longitud maxima N para almacenar las últimas N líneas
    char lines[N][MaxLineLength];
    int count = 0; // Contador de líneas leídas

    while (fgets(lines[count % N], MaxLineLength, stdin) != NULL) {
        // Leer líneas desde la entrada estándar y almacenarlas en el array
        count++;
    }
    for (int i = count - N; i < count; i++) {
        // Imprimir las últimas N líneas en orden
        printf("%s", lines[i % N]);
    }
    printf("\n");

    return 0;
}



int compareLines(const void* a, const void* b){
    const char* line1 = *(const char**)a;
    const char* line2 = *(const char**)b;
    return strlen(line2)-strlen(line1);
} /*Funcion que se utiliza para comparar las lineas con el objetivo de utilizarla para la ordenación,
    devuelve un numero negativo si la primera linea es mayor que la segunda y positivo si la segunda linea es mayor que la primera*/

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

    while (fgets(line, MaxLineLength, stdin) != NULL){
    /*Mientras que se obtengan lineas*/    
    
        if (line[strlen(line) - 1] == '\n'){
            line[strlen(line) - 1] = '\0';
        } /*Quita el ultimo elemento de la linea si fuera un salto de linea*/

        lines[lineCount] = strdup(line);
        
        /*Añade la linea a la lista de lineas lines*/

        if (lines[lineCount] == NULL){
            fprintf(stderr, "Error");
            return -1;
        } /*Verifica que se haya añadido algo en el ultimo elemento de lines*/

        lineCount++;
        /*Incrementa el contador de las lineas introducidas*/

        if(lineCount >= capacity){
            capacity *= 2;
            lines = (char**)realloc(lines, sizeof(char*) * capacity);
            /*Actualiza la capacidad de lines si se llega a su máximo, multiplicando la misma por 2 y se usa realloc para evitar la pérdida de datos*/

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


     for (int i = 0; i < lineCount; i++) {
        free(lines[i]);
    } /*Liberar la memoria, se debe recorrer la lista de líneas y liberar cada elemento individualmente*/

    free(lines);
    /*Liberamos de memoria la lista lines*/

    return 0;
    
}

