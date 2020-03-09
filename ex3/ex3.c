#include <stdio.h> 

int main(){
	int age = 10; 
	int height =72; 
	int *ptr = &age; 
	printf("I am %d years old.\n", age); 
	printf("I am %d inches tall.\n", *ptr); 

	return 0; 
}