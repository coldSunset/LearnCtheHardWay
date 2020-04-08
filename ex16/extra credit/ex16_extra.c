#include <stdio.h> 

struct Person
{
	char* name ;
	int age; 
	int height; 
	int weight;
}; 


void Person_print(struct Person someone)
{
	printf("Name: %s\n", (someone).name); 
	printf("\tAge: %d\n", (someone).age); 
	printf("\tHeight: %d\n", (someone).height); 
	printf("\tWeight: %d\n", (someone).weight); 
}

int main(int argc, char* argv[])
{
	 // create a Joe and Frank 
	 struct Person Joe = {"Joe Daniher", 19, 185, 85} ;
	 struct Person Frank = {.name="Frank Rosevelt", .height=44, .weight=178, .age=86}; 

	 // print out their details
	Person_print(Joe); 
	Person_print(Frank); 

	// change their details 

	Joe.age += 20; 
	Joe.height *= 1.01; 
	Joe.weight -= 3.5; 
	Person_print(Joe); 

	Frank.age += 20; 
	Frank.height *= 1.05; 
	Frank.weight -= 4; 
	Person_print(Frank); 

	return 0; 
}