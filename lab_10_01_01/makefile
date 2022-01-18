CC := gcc

OUT_DIR := out/
INC_DIR := inc/
SRC_DIR := src/
UNIT_DIR := unit_tests/

CFLAGS := -std=c99 -Wall -Werror -Wvla -pedantic -Iinc
LFLAGS :=
DFLAGS := -g3 --coverage

OBJS := $(OUT_DIR)main.o $(OUT_DIR)list.o $(OUT_DIR)team.o $(OUT_DIR)teams.o
UNIT_OBJS := $(OUT_DIR)check_main.o $(OUT_DIR)check_find.o \
$(OUT_DIR)check_pop_front.o $(OUT_DIR)check_reverse.o \
$(OUT_DIR)check_sort.o

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
	$(CC) $(OBJS) $(LFLAGS) -o app.exe

unit_tests.exe : $(UNIT_OBJS) $(OUT_DIR)list.o $(OUT_DIR)team.o $(OUT_DIR)teams.o
	$(CC) $^ $(LFLAGS) -lcheck -o unit_tests.exe

$(OUT_DIR)main.o : $(SRC_DIR)main.c $(INC_DIR)list.h $(INC_DIR)team.h $(INC_DIR)teams.h
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -c -o $(OUT_DIR)main.o

$(OUT_DIR)list.o : $(SRC_DIR)list.c $(INC_DIR)team.h $(INC_DIR)list.h
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -c -o $(OUT_DIR)list.o

$(OUT_DIR)team.o : $(SRC_DIR)team.c $(INC_DIR)team.h
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -c -o $(OUT_DIR)team.o

$(OUT_DIR)teams.o : $(SRC_DIR)teams.c $(INC_DIR)team.h $(INC_DIR)teams.h $(INC_DIR)list.h
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -c -o $(OUT_DIR)teams.o

$(OUT_DIR)check_main.o : $(UNIT_DIR)check_main.c
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) $< -c -o $(OUT_DIR)check_main.o

$(OUT_DIR)check_find.o : $(UNIT_DIR)check_find.c $(INC_DIR)team.h $(INC_DIR)teams.h $(INC_DIR)list.h
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -c -o $(OUT_DIR)check_find.o

$(OUT_DIR)check_pop_front.o : $(UNIT_DIR)check_pop_front.c $(INC_DIR)team.h $(INC_DIR)teams.h $(INC_DIR)list.h
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -c -o $(OUT_DIR)check_pop_front.o

$(OUT_DIR)check_reverse.o : $(UNIT_DIR)check_reverse.c $(INC_DIR)team.h $(INC_DIR)teams.h $(INC_DIR)list.h
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -c -o $(OUT_DIR)check_reverse.o

$(OUT_DIR)check_sort.o : $(UNIT_DIR)check_sort.c $(INC_DIR)team.h $(INC_DIR)teams.h $(INC_DIR)list.h
	$(CC) $(CFLAGS) -I $(INC_DIR) $< -c -o $(OUT_DIR)check_sort.o

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
