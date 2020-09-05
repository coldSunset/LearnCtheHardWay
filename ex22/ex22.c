#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int THE_SIZE = 1000; 
double *ptr_ratio; 
int THE_AGE = 37; 

int get_age()
{
	return THE_AGE; 
}

void set_age(int age)
{
	THE_AGE = age; 
}

double update_ratio(double new_ratio)
{
	static double ratio = 1.0; 
	ptr_ratio = &ratio; 
	double old_ratio = ratio; 
	log_info("----- value of ratio is: %i and address of ratio is %i", ptr_ratio, &ptr_ratio); 
	ratio = new_ratio; 

	return old_ratio; 
}

	void print_size()
	{
		log_info("I think size is: %d", THE_SIZE); 
	}