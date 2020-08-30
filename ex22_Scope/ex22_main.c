#include "ex22.h"
#include "dbg.h"

// const char* MY_NAME = "Zed A. Shaw"; 

// void scope_demo(int count)
// {
// 	log_info("count is %d", count); 

// 	if(count > 10)
// 	{
// 		int count = 100; //BAD! BUGS!

// 		log_info("count is this scope is %d", count); 
// 	}

// 	log_info("count is at exit: %d", count); 
// }

int main(int argc, char* argv[])
{
	// test out THE_AGE accessors 
	//log_info("My name: %s, age: %d", MY_NAME, (get_age())); 
	int test = get_age();
	printf("%i\n", test); 
	return 0;
}