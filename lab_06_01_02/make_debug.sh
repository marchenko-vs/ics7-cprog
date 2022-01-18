#!bin/bash/
	
gcc -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -g3 -c --coverage main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -g3 -c --coverage object.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -g3 -c --coverage objects.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -g3 -c --coverage strfuncs.c

gcc -o app.exe --coverage main.o object.o objects.o strfuncs.o
