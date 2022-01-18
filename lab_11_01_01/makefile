CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wvla
OBJS := out/my_snprintf.o
UNIT_OBJS := out/check_main.o out/check_my_snprintf.o

unit_tests.exe : $(UNIT_OBJS) $(OBJS)
	$(CC) out/my_snprintf.o $(UNIT_OBJS) -lcheck -o unit_tests.exe

out/check_main.o : unit_tests/check_main.c inc/my_snprintf.h
	mkdir -p out/
	$(CC) $(CFLAGS) $< -I inc/ -c -o out/check_main.o

out/my_snprintf.o : src/my_snprintf.c inc/my_snprintf.h
	$(CC) $(CFLAGS) $< -I inc/ -c -o out/my_snprintf.o

out/check_my_snprintf.o : unit_tests/check_my_snprintf.c inc/my_snprintf.h
	$(CC) $(CFLAGS) $< -I inc/ -c -o out/check_my_snprintf.o

.PHONY : clean unit

unit : unit_tests.exe
	./unit_tests.exe

clean :
	rm -rf out/
	rm *.exe
