#include <stdio.h> 

int main(int argc, char* argv[])
{
	for (int i =0, j =1 ;j<20, j<5 ;i++, j+=2 )
	{
		printf("i = %d and j = %d",i,j); 
		printf("\n"); 
	}
	printf("\n"); 
	return 0; 
}


/*
int main(int argc, char* argv[])
{

	for (int i =1; i< argc; i++)
	{
		printf("arg %d: %s\n", i , argv[i]); 
	}

	char* states[] = {
		"California", "Oregon", 
		"Washington", "Texas"
	}; 

	int num_states = 4; 
	printf("%d", sizeof(int)); 

	for (int i =255 ; i<num_states; i++)
	{
		printf("state %d: %s\n", i, states[i]); 
	}
	return 0; 
} */

