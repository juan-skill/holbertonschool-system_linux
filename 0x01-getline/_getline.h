#ifndef _H_GETLINE_H_
#define _H_GETLINE_H_

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h> /* File Control Operations:  */
#include <unistd.h>  /* write */
#include <string.h> /* memset */
#include <errno.h>


#define READ_SIZE 4
#define BUFF_STAT 218
#define OTHER_CHAR '\b'
#define NULL_CHAR '\0'


/**
 * struct linkedfd_s - singly linked list for fd
 *
 * @fd: The file descriptor associated
 * @buffer_static: The buffer static associated to fd
 * @next: pointer to the next node
 */
typedef struct linkedfd_s
{
	int fd;
	char buffer_static[BUFF_STAT];
	struct linkedfd_s *next;
} linkedfd_t;


char *_getline(const int fd);
linkedfd_t *addnodefd(int fd);

/* strings functions */
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
void *_memset(void *arr, char c, size_t size);

#endif
