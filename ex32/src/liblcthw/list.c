#include <lcthw/list.h>
#include <lcthw/dbg.h> 

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
	ListNode* node = calloc(1, sizeof(Listnode)); 
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

	if(list->first = NULL)
	{
		list->first = node; 
		list->last = node; 
	}
	else
	{
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
	ListNode* node = list->first; 
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