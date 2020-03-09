#include <stdio.h> 

int main(int argc, char* argv[])
{
	int i = 0; 

	if(argc ==1 )
	{
		printf("You only have argument. You suck. \n"); 
		printf("That argument is %s \n", argv[0]); 
	}
	else if (argc > 1 && argc <4)
	{
		printf("Here are your arguments:\n");
		for(int i =0; i< argc; i++)
		{
			printf("%s ", argv[i]); 
		} 
		printf("\n"); 
	}
	else 
	{
		printf("You have too many arguments, you suck. \n"); 
	}
	return 0; 
}