CFLAGS := -std=c99 -Wall -Werror -Wvla -pedantic

app.exe : out/ out/main.o out/array.o out/sort.o
	gcc out/main.o out/array.o out/sort.o -o app.exe

out/ :
	mkdir out

unit_tests.exe : out/ out/check_main.o out/check_key.o out/check_mysort.o out/array.o out/sort.o
	gcc out/array.o out/sort.o out/check_main.o out/check_key.o out/check_mysort.o -lcheck -o unit_tests.exe

out/main.o : src/main.c inc/array.h inc/sort.h
	gcc $(CFLAGS) -I inc/ -c src/main.c -o out/main.o

out/array.o: src/array.c inc/array.h
	gcc $(CFLAGS) -I inc/ -c src/array.c -o out/array.o

out/sort.o: src/sort.c inc/sort.h
	gcc $(CFLAGS) -I inc/ -c src/sort.c -o out/sort.o

out/check_main.o: unit_tests/check_main.c inc/check_funcs.h inc/array.h inc/sort.h
	gcc $(CFLAGS) -I inc/ -c unit_tests/check_main.c -o out/check_main.o

out/check_key.o: unit_tests/check_key.c inc/check_funcs.h inc/array.h
	gcc $(CFLAGS) -I inc/ -c unit_tests/check_key.c -o out/check_key.o

out/check_mysort.o: unit_tests/check_mysort.c inc/check_funcs.h inc/sort.h
	gcc $(CFLAGS) -I inc/ -c unit_tests/check_mysort.c -o out/check_mysort.o

unit : unit_tests.exe

func :
	bash make_func.sh

clean :
	rm -rf *.o *.exe out/
