CC := gcc
OUT_DIR := out/
SRC_DIR := src/
INC_DIR := inc/
UNIT_DIR := unit_tests/
CFLAGS := -std=c99 -Wall -Werror -Wvla
OBJS := $(OUT_DIR)main.o $(OUT_DIR)queue.o
UNIT_OBJS := $(OUT_DIR)check_main.o $(OUT_DIR)check_queue_push.o \
$(OUT_DIR)check_queue_pop.o $(OUT_DIR)check_queue_peek.o \
$(OUT_DIR)check_queue_fill.o

app.exe : $(OBJS)
	$(CC) $^ -o app.exe

unit_tests.exe : $(OUT_DIR)queue.o $(UNIT_OBJS)
	$(CC) $^ -lcheck -o unit_tests.exe

$(OUT_DIR)main.o : $(SRC_DIR)main.c $(INC_DIR)queue.h
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -o $(OUT_DIR)main.o -c

$(OUT_DIR)queue.o : $(SRC_DIR)queue.c $(INC_DIR)queue.h
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) $< -I $(INC_DIR) -c -o $(OUT_DIR)queue.o

$(OUT_DIR)check_main.o : $(UNIT_DIR)check_main.c $(INC_DIR)queue.h
	mkdir -p out
	$(CC) $(CFLAGS) $< -I $(INC_DIR) -c -o $(OUT_DIR)check_main.o

$(OUT_DIR)check_queue_push.o : $(UNIT_DIR)check_queue_push.c $(INC_DIR)queue.h
	$(CC) $(CFLAGS) $< -I $(INC_DIR) -c -o $(OUT_DIR)check_queue_push.o

$(OUT_DIR)check_queue_pop.o : $(UNIT_DIR)check_queue_pop.c $(INC_DIR)queue.h
	$(CC) $(CFLAGS) $< -I $(INC_DIR) -c -o $(OUT_DIR)check_queue_pop.o

$(OUT_DIR)check_queue_peek.o : $(UNIT_DIR)check_queue_peek.c $(INC_DIR)queue.h
	$(CC) $(CFLAGS) $< -I $(INC_DIR) -c -o $(OUT_DIR)check_queue_peek.o

$(OUT_DIR)check_queue_fill.o : $(UNIT_DIR)check_queue_fill.c $(INC_DIR)queue.h
	$(CC) $(CFLAGS) $< -I $(INC_DIR) -c -o $(OUT_DIR)check_queue_fill.o

.PHONY : clean unit

unit : unit_tests.exe
	./unit_tests.exe

clean :
	rm -rf $(OUT_DIR) *.exe
