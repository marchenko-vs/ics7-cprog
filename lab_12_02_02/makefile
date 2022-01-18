CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wvla
OUT_DIR := out/
INC_DIR := inc/
SRC_DIR := src/
UNIT_DIR := unit_tests/
PY_DIR := __pycache__
OBJS := $(OUT_DIR)array.o
UNIT_OBJS := $(OUT_DIR)check_main.o $(OUT_DIR)check_a_fill_fibonacci.o \
$(OUT_DIR)check_a_rm_repetitions.o

array.dll : $(OBJS)
	$(CC) -shared $< -Wl,--subsystem,windows -o array.dll

unit_tests.exe : $(UNIT_OBJS) array.dll
	$(CC) $(UNIT_OBJS) -L. -larray -lcheck -o unit_tests.exe

$(OUT_DIR)array.o : $(SRC_DIR)array.c $(INC_DIR)array.h
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -D ARRAY_EXPORTS -c -o $(OUT_DIR)array.o

$(OUT_DIR)check_main.o : $(UNIT_DIR)check_main.c
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OUT_DIR)check_main.o

$(OUT_DIR)check_a_fill_fibonacci.o : $(UNIT_DIR)check_a_fill_fibonacci.c $(INC_DIR)array.h
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -c -o $(OUT_DIR)check_a_fill_fibonacci.o

$(OUT_DIR)check_a_rm_repetitions.o : $(UNIT_DIR)check_a_rm_repetitions.c $(INC_DIR)array.h
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -c -o $(OUT_DIR)check_a_rm_repetitions.o

.PHONY : clean unit

unit : unit_tests.exe
	./unit_tests.exe

clean :
	rm -rf $(OUT_DIR) $(PY_DIR) *.exe *.dll
