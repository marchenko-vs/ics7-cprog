CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wvla -Wpedantic -I
DEBUG := -g3 --coverage
CHECK_OBJS := out/check_main.o out/matrix.o out/check_m_multiply.o out/check_m_power.o

app.exe : out/ out/main.o out/matrix.o
	$(CC) out/main.o out/matrix.o -o app.exe

unit_tests.exe : out/ $(CHECK_OBJS)
	gcc $(CHECK_OBJS) -lcheck -o unit_tests.exe

out/ :
	mkdir out/

out/main.o : src/main.c inc/matrix.h
	$(CC) $(CFLAGS) inc/ $< -c -o out/main.o

out/matrix.o : src/matrix.c inc/matrix.h
	$(CC) $(CFLAGS) inc/ $< -c -o out/matrix.o

out/check_main.o: unit_tests/check_main.c inc/check_funcs.h inc/matrix.h
	gcc $(CFLAGS) inc/ -c unit_tests/check_main.c -o out/check_main.o

out/check_m_multiply.o : unit_tests/check_m_multiply.c inc/check_funcs.h inc/matrix.h
	gcc $(CFLAGS) inc/ -c unit_tests/check_m_multiply.c -o out/check_m_multiply.o

out/check_m_power.o : unit_tests/check_m_power.c inc/check_funcs.h inc/matrix.h
	gcc $(CFLAGS) inc/ -c unit_tests/check_m_power.c -o out/check_m_power.o

unit : unit_tests.exe

func : app.exe make_func.sh
	bash make_func.sh

clean :
	rm -rf *.exe out/
