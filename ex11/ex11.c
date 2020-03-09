#include <stdio.h> 

int  main(int argc, char* argv[])
{
	/*int numbers[4] = {0}; 
	char name[4] = {'a', '\0'}; 

	//first print them out raw
	printf("numbers: %d %d %d %d \n", numbers[0], numbers[1], 
		numbers[2], numbers[3]); 
	printf("name each : %c %c %c %c\n", 
		name[0], name[1], name[2], name[3]); 
	printf("name: %s\n", name); 

	//set up the numbers 
	numbers[0] = 1; 
	numbers[1] = 2; 
	numbers[2] = 3; 
	numbers[3] = 4; 

	//set up the name 
	name[0] = 'Z'; 
	name[1] = 'E'; 
	name[2] = 'D'; 
	name[3] = '\0'; 

//print them out initialised 
	printf("numbers: %d %d %d %d \n", numbers[0], numbers[1], 
		numbers[2], numbers[3]); 
	printf("name each : %c %c %c %c\n", 
		name[0], name[1], name[2], name[3]); 
	printf("name: %s\n", name); 

	//print the name like a string 
	printf("name: %s\n", name); 

	//another way to use name 
	char* another = "Zed"; 

	printf("%s\n", another); 

	printf("another each: %c %c %c %c\n", 
		another[0], another[1], another[2], another[3]); 

	printf("Size of name[0] : %d \n", sizeof(name[0])); */

	char name2[4] = {'A', 'A', 'A', '\0'};
	int number = (name2[0] << 24) + (name2[1] << 16) + (name2[2] << 8) + (name2[3]) 
	;
	printf("this is the value of the second number %d\n", number >> 16); 

	printf("first number = %d\n", number >>24);
	int j =0 ;
	for (int i = 24; i> -8; i -=  8)
	{	
		printf("i = %d ", i); 
		printf("number[%d] = %d \n", j , (number >> i) & 0x000000FF);  
		j++; 
	}
	return 0; 
}