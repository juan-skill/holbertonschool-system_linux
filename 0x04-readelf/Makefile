# first useful Makefile

# Define the C compiler to use
CC = gcc

# Define the c flags compiler
CFLAGS = -g -Wall -Wextra -Werror -pedantic

0-hreadelf: 0_main.c
	$(CC) $(CFLAGS) 0_main.c -o 0-hreadelf

1-hreadelf: 1_main.c
	$(CC) $(CFLAGS) 1_main.c -o 1-hreadelf

2-hreadelf: 2_main.c
	$(CC) $(CFLAGS) 2_main.c -o 2-hreadelf

100-hreadelf: 2_main.c
	$(CC) $(CFLAGS) 100_main.c -o 100-hreadelf
