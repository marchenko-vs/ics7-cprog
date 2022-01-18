#!bin/bash/
	
gcc -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -c main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -c object.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -c objects.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -c strfuncs.c

gcc main.o object.o objects.o strfuncs.o -o app.exe
