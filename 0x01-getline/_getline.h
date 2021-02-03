#ifndef _H_GETLINE_H_
#define _H_GETLINE_H_

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h> /* File Control Operations:  */
#include <unistd.h>  /* write */
#include <string.h> /* memset */
#include <errno.h>

#define READ_SIZE 1024
#define BUFF_SIZE 1

char *_getline(const int fd);


/* strings functions */
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
void *_memset(void *arr, char c, size_t size);

#endif
