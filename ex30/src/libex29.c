#include <stdio.h>
#include <ctype.h>
#include "dbg.h"
#include <string.h> 



int print_a_message(const char* msg)
{
	printf("A STRING: %s\n", msg); 

	return 0; 
}

int uppercase(const char* msg)
{
	int i =0 ; 
	int msg_len = strlen(msg); 
	//BUG: \0 termination problems 
	for(i=0; i<msg_len; i++)
	{
		printf("%c", toupper(msg[i])); 
	}

	printf("\n"); 
 
	return 0; 
}

int lowercase(const char* msg)
{
	int i =0; 
	int msg_len = strlen(msg); 
	//BUG: \0 termination problems 
	for(i=0; i < msg_len; i++)
	{
		printf("%c", tolower(msg[i])); 
	}

	printf("\n"); 

	return 0; 
}

int fail_on_purpose(const char* msg)
{
	(void)msg; 
	return 1; 
}