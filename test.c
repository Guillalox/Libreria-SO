#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libreria.h"

int main(int argc, char *argv[]) {
    int N = 10; // Número predeterminado de líneas a mostrar

    if (argc == 3) {
        N = atoi(argv[2]); // Si se proporcionan 3 argumentos,contando el argumento ./test, el segundo argumento se convierte en N

        // Verifica el primer argumento para determinar qué función llamar
        if (strcmp(argv[1], "-head") == 0) {
            head(N);
        } else if (strcmp(argv[1], "-tail") == 0) {
            tail(N);
        } else if (strcmp(argv[1], "-longlines") == 0) {
            longlines(N);
        } else {
            // Muestra un mensaje de uso incorrecto si el primer argumento no coincide con las opciones válidas
            fprintf(stderr, "Uso incorrecto. Uso: %s <-head|-tail|-longlines> [número de líneas]\n", argv[0]);
            return 1;
        }
    }

    if (argc == 2) {
        // Si se proporcionan 2 argumentos,contando el argumento ./test, se toma el valor de N=10
        // Verifica el primer argumento para determinar qué función llamar
        if (strcmp(argv[1], "-head") == 0) {
            head(N);
        } else if (strcmp(argv[1], "-tail") == 0) {
            tail(N);
        } else if (strcmp(argv[1], "-longlines") == 0) {
            longlines(N);
        } else {
            // Muestra un mensaje de uso incorrecto si el primer argumento no coincide con las opciones válidas
            fprintf(stderr, "Uso incorrecto. Uso: %s <-head|-tail|-longlines> [número de líneas]\n", argv[0]);
            return 1;
        }
    } else if (argc > 3 || argc < 2) {
        // Si se proporciona un número incorrecto de argumentos, muestra un mensaje de uso incorrecto
        fprintf(stderr, "Uso incorrecto. Uso: %s <-head|-tail|-longlines> [número de líneas]\n", argv[0]);
        return 1;
    }

    return 0;
}
