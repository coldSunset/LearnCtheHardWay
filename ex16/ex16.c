#include <stdio.h>
#include <assert.h> 
#include <stdlib.h> 
#include <string.h> 

// Structure definition 
struct Person 
{
	char *name; 
	int age; 
	int height; 
	int weight; 
};

// a function which creates a structure
struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person)); 
	assert(who!=NULL); 

	who -> name = strdup(name); 
	who -> age = age; 
	who -> height = height; 
	who -> weight = weight; 

	return who; 
}

// a function to destroy a struct once we are finished 
void Person_destroy(struct Person *who)
{
	assert(who != NULL); 

	free(who->name); 
	free(who); 
}

// a function to print out information regarding the struct
void Person_print(struct Person *who)
{
	printf("Name: %s\n", who -> name); 
	printf("\tAge: %d\n", who -> age); 
	printf("\tHeight: %d\n", who -> height); 
	printf("\tWeight: %d\n", who -> weight); 
	printf("\tsize of struct is : %ld\n", sizeof(who)); 
}

int main (int argv, char *argc[])
{
	// make two people structures 
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140); 
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180); 

	// print them out and where they are in memory 
	printf("Joes is at memory location %p:\n", joe); 	
	Person_print(joe); 

	printf("Frank is at memory location %p:\n", frank); 
	Person_print(frank); 

	// make everyone age 20 years and print them again 
	joe -> age += 20; 
	joe -> height -= 2; 
	joe -> weight += 20; 
	Person_print(joe); 

	frank -> age += 20; 
	frank -> weight += 20; 
	Person_print(frank); 

	//destroy them boith so we can clean up 
	Person_destroy(joe); 
	Person_destroy(frank); 

	printf("%ld\n", sizeof(Person)); 

	return 0 ;
}