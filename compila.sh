#!/bin/bash

gcc -c libreria.c
ar rcs libreria.a libreria.o

gcc -wall -wextra -o test test.c -I -L./ -l libreria

rm libreria.o

echo "Compilación completada"