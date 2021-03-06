#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> /* opendir */
#include <errno.h>  /* errno */
#include <sys/stat.h>   /* lstat or stat */
#include <string.h> /* str functions */

#include <unistd.h> /* write */

#include <stdbool.h>  /* boolean */

#define KILOBYTE 1024
#define FLUSH -1
#define FLAG_SIZE sizeof("-1aAlrStR")
#define ERROR_FOUND -1
#define DEFAULT_OPTION_COMMAND "one"
#define CURRENT_DIRECTORY "."

/**
 * struct cml - struct to choose the right function depending
 *
 * @option_flag: option to specifier the output
 * @fun_ptr: pointer to the correct printing function
 *
 * Description: on the argument flag passed to _ls()
 */
typedef struct cml
{
	char *option_flag;
	int (*fun_ptr)(char *file_name);
} cml_t;

/**
 * struct linkedList - singly linked list
 * @string: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct linkedList
{
	char *string;
	unsigned int len;
	struct linkedList *next;
} linked_l;


int (*get_op_func(char *s))(char *);
/* ls functions */
int _ls_only(char *dirpath);
int _ls_minus_one(char *dirpath);



char *get_command_options(char **str,  int argc);
size_t get_command_filename(char **str,  int argc, char ***dirpath);
void free_array(char **s, size_t size);
void print_array(char **argv);

/* linked list */
linked_l *addNodeEnd(linked_l **head, char *str);
linked_l *addNode(linked_l **head, char *str);
size_t printList(const linked_l *h);
void freeList(linked_l *head);


char *print_filename(char *str);
int isDird(char *dirpath);
size_t get_current_directory(char ***dirpath);
int errMsg(int err, char *dirpath);
void save_name(const struct stat *sb, struct dirent **entry,
	       linked_l **files, linked_l **directories);
int check_hidden_files(struct dirent **entry);


/* print functions */
int _putchar(char c);
int _puts(char *s);


/* strings functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);


/* memory */
void *_memset(void *s, int b, unsigned int n);

#endif
