#ifndef _SIGNAL_
#define _SIGNAL_

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>


int handle_signal(void);
void (*current_handler_signal(void))(int);

#endif
