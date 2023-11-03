#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libreria.h"

int main(int argc, char *argv[]) {
    int N = 10; 
    if (argc == 3) {
        N = atoi(argv[2]);
    }

    if (argc == 2) {
        if (strcmp(argv[1], "-head") == 0) {
            head(N);
        } else if (strcmp(argv[1], "-tail") == 0) {
            tail(N);
        } else if (strcmp(argv[1], "-longlines") == 0) {
            longlines(N);
        } else {
            fprintf(stderr, "Uso incorrecto. Uso: %s <-head|-tail|-longlines> [número de líneas]\n", argv[0]);
            return 1;
        }
    } else {
        fprintf(stderr, "Uso incorrecto. Uso: %s <-head|-tail|-longlines> [número de líneas]\n", argv[0]);
        return 1;
    }

    return 0;
}
