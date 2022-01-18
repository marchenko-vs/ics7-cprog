#!bin/bash/

mkdir out

gcc -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -g3 -c --coverage src/main.c -o out/main.o
gcc -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -g3 -c --coverage src/array.c -o out/array.o
gcc -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -g3 -c --coverage src/sort.c -o out/sort.o

gcc -o app.exe --coverage out/main.o out/sort.o out/array.o
