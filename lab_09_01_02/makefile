CC := gcc
CFLAGS := -std=gnu99 -Wall -Werror -Wvla -pedantic
LFLAGS := -lcheck
OBJS := out/main.o out/object.o out/object_array.o out/strfuncs.o
UNIT_OBJS := out/object.o out/object_array.o out/strfuncs.o \
out/check_main.o out/check_str_begins.o out/check_o_cmp_by_density.o \
out/check_o_swap.o

app.exe : out/ $(OBJS)
	$(CC) $(OBJS) -o app.exe

unit_tests.exe : out/ $(UNIT_OBJS)
	$(CC) $(UNIT_OBJS) $(LFLAGS) -o unit_tests.exe

out/ :
	mkdir out/

out/main.o : src/main.c inc/object.h inc/object_array.h inc/strfuncs.h
	$(CC) $(CFLAGS) -I inc/ src/main.c -c -o out/main.o

out/object.o : src/object.c inc/object.h
	$(CC) $(CFLAGS) -I inc/ src/object.c -c -o out/object.o

out/object_array.o : src/object_array.c inc/object.h inc/object_array.h
	$(CC) $(CFLAGS) -I inc/ src/object_array.c -c -o out/object_array.o

out/strfuncs.o : src/strfuncs.c inc/strfuncs.h
	$(CC) $(CFLAGS) -I inc/ src/strfuncs.c -c -o out/strfuncs.o

out/check_main.o : unit_tests/check_main.c inc/check_funcs.h
	$(CC) $(CFLAGS) -I inc/ unit_tests/check_main.c -c -o out/check_main.o

out/check_str_begins.o : unit_tests/check_str_begins.c inc/check_funcs.h inc/strfuncs.h
	$(CC) $(CFLAGS) -I inc/ unit_tests/check_str_begins.c -c -o out/check_str_begins.o

out/check_o_cmp_by_density.o : unit_tests/check_o_cmp_by_density.c inc/check_funcs.h inc/object.h
	$(CC) $(CFLAGS) -I inc/ unit_tests/check_o_cmp_by_density.c -c -o out/check_o_cmp_by_density.o

out/check_o_swap.o : unit_tests/check_o_swap.c inc/check_funcs.h inc/object.h
	$(CC) $(CFLAGS) -I inc/ unit_tests/check_o_swap.c -c -o out/check_o_swap.o

.PHONY : func clean unit debug

func : make_func.sh
	bash make_func.sh

unit : unit_tests.exe

clean :
	rm -rf out/ *.txt *.gcov *.o *.exe
