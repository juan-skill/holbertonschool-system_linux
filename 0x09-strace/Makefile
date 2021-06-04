# Makefile
CC = gcc
# Define the c flags compiler
CFLAGS = -g -Wall -Werror -Wextra -pedantic -std=gnu99

SRC0 = strace_0.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = strace_0

SRC1 = strace_1.c
OBJ1 = $(SRC1:.c=.o)
NAME1 = strace_1

SRC2 = strace_2.c
OBJ2 = $(SRC2:.c=.o)
NAME2 = strace_2

strace_0: strace.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

strace_1: strace.h $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)

strace_2: strace.h $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)
