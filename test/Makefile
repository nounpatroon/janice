
CC := gcc
CFLAGS := -g -Wall -Werror -O2 --std=c89
LIBS := -lm

all: linux

linux:
	$(CC) $(CFLAGS) $(SRC).c ../source/$(SRC).c $(LIBS) -o a.out
	valgrind --tool=memcheck --leak-check=full ./a.out
