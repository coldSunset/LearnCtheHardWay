#include <stdio.h> 

int main(int argc, char* argv[])
{
	int values[3]; 
	for(int i=0; i<6; i++)
	{
		values[i] = 2; 
	}
	for(int i =0; i<6; i++)
	{
		printf("%i\t", values[i]); 
	}
	printf("\n"); 
	printf("%i\n", values[7]); 

	return 0; 
}