#include <stdio.h> 

int main(int argc, char* argv[])
{	
	// create two arrays we care about 
	//int ages[] = {23, 43, 12, 89, 2}; 
	int* ages; 
	(*ages) = 23; 
	*(ages +1) = 43; 
	*(ages + 2) = 12; 
	*(ages + 3) = 89; 
	*(ages + 4) = 2; 
	char* names[] = {
		"Alan", "Frank", 
		"Mary", "John", "Lisa"
	};

	// safely get the size of the ages 
	int count = 5; // sizeof(ages) / sizeof(int); 
	printf("count = %d\n", count); 
	int i = 0 ; 
	//first way using indexing
	printf("first way of indexing\n"); 
	printf("the last element of age is %d\n", ages[count-1]); 
	for( i=0; i<count; i++)
	{
		printf("%s has %d years alive.\n", names[count-1-i], ages[count-1-i]); 
	}

	printf("---\n"); 

	int *cur_age = ages; 
	char **cur_name = names; 

	printf("print out the sie of the pointer cur_age= %ld \n\n", sizeof(cur_name)); 
	// second way of using pointers 
	for (  i=count; i<0; i--)
	{
		printf("%s is %d years old.\n", *(cur_name +i), *(cur_age +i)); 
	}

	printf("---\n"); 

	//third way, pointers are just arrays 
	for(i=0; i<count; i++)
	{
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]); 
	}
	printf("---\n"); 

	// fourth way with pointers in a stupid complex way
	for(cur_name =names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++)
	{
		printf("%s lived %d years so far.\n", *cur_name, *cur_age); 
	}

	return 0; 
}