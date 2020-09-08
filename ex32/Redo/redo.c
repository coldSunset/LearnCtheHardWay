#include "list.h"
#include "dbg.h" 
#include "minunit.h"
#include <assert.h>

List* List_create() 
{
	return calloc(1, sizeof(List)); 
}

void List_destroy(List* list)
{
	LIST_FOREACH(list, first, next, cur)
	{
		if(cur->prev)
		{
			free(cur->prev); 
		}
	}
	free(list->last); 
	free(list); 
}

void List_clear(List* list)
{
	LIST_FOREACH(list, first, next, cur)
	{
		free(cur->value); 
	}
}

void List_clear_destroy(List* list)
{
	List_clear(list); 
	List_destroy(list); 

}

void List_push(List* list, void* value)
{
	ListNode* node = calloc(1, sizeof(ListNode)); 
	check_mem(node); 

	node->value = value; 

	if(list->last == NULL) //list is empty
	{
		list->first = node; 
		list->last = node;
	}
	else 
	{							// push item to the end of the list 
		list->last->next = node; 
		node->prev = list->last; 
		list->last = node; 
	}

	list->count++; 
error:
	return; 
}

void* List_pop(List* list)
{
	ListNode *node = list->last; // remove last item in List
	return node != NULL ? List_remove(list, node) : NULL; 
}

void List_unshift(List* list, void* value)
{
	ListNode* node = calloc(1, sizeof(ListNode)); 
	check_mem(node); 

	node->value = value; 

	if(list->first == NULL)
	{
		list->first = node; 
		list->last = node; 
	}
	else
	{		// put new item at the start of the list
		node->next = list->first; 
		list->first->prev = node; 
		list->first = node; 
	}
	list->count++; 
error: 
	return; 
}

void* List_shift(List* list)
{
	ListNode* node = list->first; //remove the first item of the list 
	return node != NULL ? List_remove(list, node) : NULL; 
}

void* List_remove(List* list, ListNode* node)
{
	void* result = NULL; 

	check(list->first && list->last, "list is empty.");
	check(node, "node can't be NULL"); 

	if(node == list->first && node == list->last) //Node is the only 
	{											  // element in the list 
		list->first = NULL; 
		list->last = NULL; 
	}
	else if(node == list->first) //Node is the first element in the list
	{
		list->first = node->next; // point first item of list to node's next item
		check(list->first != NULL, "Invalid list, somehow got a first that is NULL."); 
		list->first->prev = NULL; //change previous of new item to NULL 
	}
	else if(node == list->last) //Node is the last element in the list
	{
		list->last = node->prev; //Point last item of List to prev item of node
		check(list->last != NULL, "Invalid list, somehow got a next that is NULL."); 
		list->last->next = NULL; //Point next of new last item to NULL
	}
	else 
	{	//Node appears at the middle of the list 
		ListNode* after = node->next; //store next item of node in 'after' pointer
		ListNode* before = node->prev; //store previous item of node in 'before' pointer
		after->prev = before; // store pointer of before to prev of after node
		before->next = after; // store pointer of after to next of before node
	}

	list->count--; 
	result = node->value; 
	free(node); 
error: 
return result; 
}


static List* list = NULL; 
char* test1 = "test1 data";
char* test2 = "test2 data"; 
char* test3 = "test3 data"; 

char* test_create() 
{
	list = List_create(); 
	mu_assert(list != NULL, "Failed to create list."); 

	return NULL; 
}

char* test_destroy()
{
	List_clear_destroy(list); 

	return NULL; 
}

char* test_push_pop()
{
	List_push(list, test1); 
	mu_assert(List_last(list) == test1, "Wrong last value."); 

	List_push(list, test2); 
	mu_assert(List_last(list) == test2, "Wrong last value.");

	List_push(list, test3); 
	mu_assert(List_last(list) == test3, "Wrong last value."); 
	mu_assert(List_count(list) == 3, "wrong count on push"); 

	char* val = List_pop(list); 
	mu_assert(val == test3, "Wrong value on pop."); 

	val = List_pop(list); 
	mu_assert(val == test2, "wrong value on pop."); 

	val = List_pop(list); 
	mu_assert(val == test1, "Wrong value on pop"); 
	mu_assert(List_count(list) == 0, "Wrong count after pop."); 

	return NULL; 
}

char* test_unshift() 
{
	List_unshift(list, test1); 
	mu_assert(List_first(list) == test1, "Wrong first value"); 

	List_unshift(list, test2);
	mu_assert(List_first(list) == test2, "Wrong first value"); 

	List_unshift(list, test3); 
	mu_assert(List_first(list) == test3, "Wrong last value."); 
	mu_assert(List_last(list) == test3, "Wrong last value (edit).")
	mu_assert(List_count(list) == 3, "Wrong count on unshift"); 

	return NULL; 
}

char* test_remove() 
{
	// we only need to test the middle remove case since push/shift already tests the other cases

	char* val = List_remove(list, list->first->next); 
	mu_assert(val == test2, "Wrong removed element"); 
	mu_assert(List_count(list) == 2, "Wrong first after remove"); 

	mu_assert(List_first(list) == test3, "Wrong first after remove."); //migth be test1
	mu_assert(List_last(list) == test1, "Wrong last after remove.");

	return NULL;  
}

char* test_shift() //remove first item on the List
{
	mu_assert(List_count(list) != 0, "Wrong count before shift");

	char* val = List_shift(list); 
	mu_assert(val == test3, "Wrong value on shift."); //??

	val = List_shift(list); 
	mu_assert(val == test1, "Wrong value on shift."); 
	mu_assert(List_count(list) == 0, "Wrong count after shift.")

	return NULL; 
}

char* all_tests() 
{
	mu_suite_start(); 

	mu_run_test(test_create); 
	mu_run_test(test_push_pop); 
	mu_run_test(test_unshift); 
	mu_run_test(test_remove); 
	mu_run_test(test_shift); 
	mu_run_test(test_destroy); 

	return NULL; 
}

RUN_TESTS(all_tests); 