/*
 * sorted-list.h
 */
 
#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <stdlib.h>

typedef int (*CompareFuncT)( void *, void * );
typedef void (*DestructFuncT)( void * );

typedef struct Node
{
    void* data;
    struct Node *next;
    
}Node;


struct SortedList 
{
	CompareFuncT compare;
	DestructFuncT destroy;
	int numItems;
	Node *head, *curr, *prev;
	
};
typedef struct SortedList* SortedListPtr;

struct SortedListIterator
{
	Node *ptr;
	int count;
	int tracker;
};
typedef struct SortedListIterator* SortedListIteratorPtr;


SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df);
 
void SLDestroy(SortedListPtr list);

int SLInsert(SortedListPtr list, void *newObj);

int SLRemove(SortedListPtr list, void *newObj);

SortedListIteratorPtr SLCreateIterator(SortedListPtr list);

void SLDestroyIterator(SortedListIteratorPtr iter);

void * SLNextItem(SortedListIteratorPtr iter);

void * SLGetItem( SortedListIteratorPtr iter );

#endif
