#!/bin/bash

gcc -c libreria.c
ar rcs libreria.a libreria.o

gcc -Wall -Wextra -o test test.c -L./ -l:libreria.a

rm libreria.o

echo "Compilación completada"