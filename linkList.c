#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sorted-list.h"


//*-**==*=--=-*----=*-*=--*-*-=-*-=-*-*=--*-=-*=--*-=-*-=-=-*-*=--*-=-*-=-*-=-*-*=--*-=-=-=-=-=-=-=-=-=-*-=--*-=-

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df)
{       
        SortedListPtr sl = malloc(sizeof(struct SortedList));  //......->>>>>(SortedListPtr)
        sl->compare = cf;
        sl->destroy = df;
        sl->numItems = 0;
        sl->head = NULL;

        return sl;         
} 


//*-**==*=--=-*----=*-*=--*-*-=-*-=-*-*=--*-=-*=--*-=-*-=-=-*-*=--*-=-*-=-*-=-*-*=--*-=-=-=-=-=-=-=-=-=-*-=--*-=-

int SLInsert(SortedListPtr list, void *newObj)
{
     Node* addNode= malloc(sizeof(Node));
        
     
    if(list == NULL)
    {
        printf("NUll List Cannot ADD ELEMENTS!");    
        return 0;
    }
    
    
    addNode->data = newObj;      //new node= passed Value
    
    
    if(list->compare == NULL || list->head == NULL)  //if empty or No Comaprison
    {
        addNode->next = list->head;
        list->head = addNode;
    }
    
    
    else
    {
        list->curr = list->head;
        list->prev = NULL;
        
        while(list->curr != NULL && list->compare(newObj, list->curr->data) > -1)//go throght the sorted list
        {
        	
        	if(    list->compare(newObj, list->curr->data) == 0   )
        	{
        		return 0;
			}
        
            list->prev = list->curr;
            list->curr= list->curr->next;
        }
        
    	if( list->prev == NULL )                                          
       	{                                                                  
           addNode->next = list->head;
           list->head = addNode;
        }
        else
        {
            list->prev->next = addNode;
            addNode->next = list->curr;
        }
    }
    
    list->numItems++;
    
    return 0;   
}

//*-**==*=--=-*----=*-*=--*-*-=-*-=-*-*=--*-=-*=--*-=-*-=-=-*-*=--*-=-*-=-*-=-*-*=--*-=-=-=-=-=-=-=-=-=-*-=--*-=-


int SLRemove(SortedListPtr list, void *newObj)
{
   //checks if it is in head
   if(list->head->data   ==    newObj  )
   {
          list->head=list->head->next;          
   }              
   
   list->curr=list->head;

    while(list->curr != NULL)
        {
            if(list->curr->data    ==    newObj      )
               {
                     list->curr = list->curr->next; 
                     list->prev->next=list->curr;
                     return 0;
                }                                                           
            list->prev = list->curr;
            list->curr= list->curr->next;  
        }       
        list->numItems--;
        return 0;
}






SortedListIteratorPtr SLCreateIterator(SortedListPtr list)
{
	SortedListIteratorPtr mptr= malloc(sizeof(struct SortedListIterator));
	
	if(list == NULL)
    {
        printf("NUll List Cannot ADD ELEMENTS!");    
        return NULL;
    }
	
	mptr->ptr = list->head;
	mptr->count = list->numItems;
	mptr->tracker=0;
	return mptr;
}


void* SLNextItem(SortedListIteratorPtr iter)
{
	if(iter->tracker== iter->count)
	{
		printf("Warrning: End Of The List");
		return iter->ptr;
	}
		
	iter->ptr=iter->ptr->next;
	iter->tracker++;
	return 	iter->ptr;
}

void* SLGetItem(SortedListIteratorPtr iter)
{	

//    printf("INSIDE GET ITEM\n");
  //  Node *ptr = (iter->ptr)->data;
    
    //printf("%s", *ptr);
    
    //printf
    
    //printf("%c", iter->ptr);
    
	if(iter->tracker == iter->count)
		return iter->ptr;
	else if(iter->tracker > iter->count)
		return NULL;
	else
		return iter->ptr;
}



int compareStrings(void *p1, void *p2) {
	char *s1 = p1;
	char *s2 = p2;

	return strcmp(s1, s2);
}



int main(void )
{

	
  SortedListPtr si =SLCreate(compareStrings, NULL);
  
  SLInsert(si, "z");
  SLInsert(si, "a");
  SLInsert(si, "a");
  SLInsert(si, "b");
  SLInsert(si, "x");
  
// SLRemove(si, "x");
  
  
  Node *ptr;
  SortedListIteratorPtr it =  SLCreateIterator(si);
  
  ptr = SLGetItem(it);
  
  printf("GET CURRENT ITEM: %s", ptr->data);

  
  
  ptr = SLNextItem(it);
  
  printf("\nGET NEXT ITEM: %s", ptr->data);
/*  
  si->curr=si->head;
   while(si->curr != NULL)
   {
        printf("%s ",si->curr->data);
        si->curr= si->curr->next;  
   } 
   
   return 0;
   */
}

