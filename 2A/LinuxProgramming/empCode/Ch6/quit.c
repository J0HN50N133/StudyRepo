#include "quit.h"

void quit(char* message, int exit_status) 
{
	fprintf(stderr, message);
	exit(exit_status);
}
