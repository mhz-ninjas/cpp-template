#include "funcs.h"

/* funcs.c
 * Implementation of some functions
 */

 int add(int a, int b)
{
	return a + b;
}


static char* hello = "Hello!";

const char* say(void){
	return hello;
}
