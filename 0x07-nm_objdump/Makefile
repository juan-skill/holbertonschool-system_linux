# Makefile
CC=gcc
# Define the c flags compiler
CFLAGS = -g -Wall -Wextra -Werror -pedantic

hnm: main0.c
	$(CC) $(CFLAGS) main0.c -o hnm
	cp hnm test
	touch main0.c

hobjdump: main1.c
	$(CC) $(CFLAGS) main1.c -o hobjdump
	cp hobjdump test
	touch main1.c
