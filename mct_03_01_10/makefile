CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wvla -pedantic
OBJS := out/main.o out/matrix.o out/matrix_array.o

app.exe : out/ $(OBJS)
	$(CC) $(OBJS) -o app.exe

debug.exe : CFLAGS += -g3 --coverage -ggdb

debug.exe : out/ $(OBJS)
	$(CC) $(OBJS) --coverage -o debug.exe

out/ :
	mkdir out

out/main.o : src/main.c inc/matrix.h inc/matrix_array.h
	$(CC) $(CFLAGS) src/main.c -I inc/ -c -o out/main.o

out/matrix.o : src/matrix.c inc/matrix.h
	$(CC) $(CFLAGS) -I inc/ src/matrix.c -c -o out/matrix.o

out/matrix_array.o : src/matrix_array.c inc/matrix.h inc/matrix_array.h
	$(CC) $(CFLAGS) -I inc/ src/matrix_array.c -c -o out/matrix_array.o

.PHONY : debug clean

debug : debug.exe

clean :
	rm -rf out/ *.txt *.exe *.gcov
