#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h> 

struct ListNode; 		//each list points to next and prev node and holds a value
typedef struct ListNode
{
	struct ListNode *next; 
	struct ListNode *prev; 
	void *value; 
} ListNode; 

typedef struct List 	//Container for List information, holds count and pointers to first 
{														// and last node
	int count; 
	ListNode* first; 
	ListNode* last;  
} List; 

List* List_create();  // allocates section of memory, sets it to 0. Returns pointer to List
void List_destroy(List* list); //Destroys Lists. Frees up contents. 
void List_clear(List* list); // Clears Contents
void List_clear_destroy(List* list); // Clears contents and then destroys nodes 

#define List_count(A) ((A)->count) // counts number of notes 
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)//pointer of first node
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)//pointer to last node

void List_push(List* list, void* value);//pushes new node to end of list. Increments count
void* List_pop(List* list);//removes last item of list. Decrements count

void List_unshift(List* list, void* value);//pushed new node to start of the list. Count++
void* List_shift(List* list);// removes first node. Count-- 

void* List_remove(List* list, ListNode* node);//removes a node. Frees node 

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
													ListNode* V =\
NULL;\
for(V= _node = L->S; _node != NULL; V = _node = _node->M)

// EXTRA CREDIT FUNCTIONS 

// Copying 
// Joining 
// Splitting

#endif //lcthw_List_h