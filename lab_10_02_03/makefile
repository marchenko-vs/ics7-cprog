CC := gcc

OUT_DIR := out/
INC_DIR := inc/
SRC_DIR := src/
UNIT_DIR := unit_tests/

CFLAGS := -std=c99 -Wall -Werror -Wvla -pedantic -Iinc
LFLAGS :=
DFLAGS := -g3 --coverage

OBJS := $(OUT_DIR)main.o $(OUT_DIR)list.o
UNIT_OBJS := $(OUT_DIR)check_main.o $(OUT_DIR)check_free_list.o \
$(OUT_DIR)check_print_list_number.o $(OUT_DIR)check_push_back.o \
$(OUT_DIR)check_decompose_number.o $(OUT_DIR)check_square_number.o \
$(OUT_DIR)check_multiply_numbers.o

release : CFLAGS += -DNDEBUG -g0
release : lastrelease | app.exe

debug : CFLAGS += $(DFLAGS)
debug : LFLAGS += --coverage
debug : lastdebug | app.exe

lastdebug :
	touch lastdebug
	rm -rf $(OUT_DIR) app.exe
	rm -f lastrelease

lastrelease :
	touch lastrelease
	rm -rf $(OUT_DIR) app.exe
	rm -f lastdebug

app.exe : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o app.exe

unit_tests.exe : $(UNIT_OBJS) $(OUT_DIR)list.o
	$(CC) $(LFLAGS) $^ -lcheck -o unit_tests.exe

$(OUT_DIR)main.o : $(SRC_DIR)main.c $(INC_DIR)list.h
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)main.c -o $(OUT_DIR)main.o

$(OUT_DIR)list.o : $(SRC_DIR)list.c $(INC_DIR)list.h
	$(CC) $(CFLAGS) $< -c -o $(OUT_DIR)list.o

$(OUT_DIR)check_main.o : $(UNIT_DIR)check_main.c
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OUT_DIR)check_main.o

$(OUT_DIR)check_free_list.o : $(UNIT_DIR)check_free_list.c $(INC_DIR)list.h
	$(CC) $(CFLAGS) $< -c -o $(OUT_DIR)check_free_list.o

$(OUT_DIR)check_print_list_number.o : $(UNIT_DIR)check_print_list_number.c $(INC_DIR)list.h
	$(CC) $(CFLAGS) $< -c -o $(OUT_DIR)check_print_list_number.o

$(OUT_DIR)check_push_back.o : $(UNIT_DIR)check_push_back.c $(INC_DIR)list.h
	$(CC) $(CFLAGS) $< -c -o $(OUT_DIR)check_push_back.o

$(OUT_DIR)check_decompose_number.o : $(UNIT_DIR)check_decompose_number.c $(INC_DIR)list.h
	$(CC) $(CFLAGS) $< -c -o $(OUT_DIR)check_decompose_number.o

$(OUT_DIR)check_square_number.o : $(UNIT_DIR)check_square_number.c $(INC_DIR)list.h
	$(CC) $(CFLAGS) $< -c -o $(OUT_DIR)check_square_number.o

$(OUT_DIR)check_multiply_numbers.o : $(UNIT_DIR)check_multiply_numbers.c $(INC_DIR)list.h
	$(CC) $(CFLAGS) $< -c -o $(OUT_DIR)check_multiply_numbers.o

.PHONY : clean func unit debug

.NOTPARALLEL : clean func unit

unit : CFLAGS += $(DFLAGS)
unit : LFLAGS += --coverage
unit : unit_tests.exe

unit : debug unit_tests.exe
	./unit_tests.exe
	@echo
	@echo "Unit tests coverage report:"
	@echo
	gcov -rf $(OUT_DIR)list.gcno
	mv *.gcov $(OUT_DIR)

func : debug
	bash make_func.sh
	@echo
	@echo "Functional tests coverage report:"
	@echo
	gcov -rf $(OUT_DIR)*.gcno
	mv *.gcov $(OUT_DIR) 

clean :
	rm -rf $(OUT_DIR) *.exe
	rm -f lastdebug lastrelease
