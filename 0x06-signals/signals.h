#ifndef _SIGNAL_
#define _SIGNAL_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <unistd.h>
#include <signal.h>


int handle_signal(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
int pid_exist(pid_t pid);

#endif
