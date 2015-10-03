#include<stdlib.h>
#include<stdio.h>
#include"sorted-list.h"


int main(void)
{

  SortedListPtr si =SLCreate(NULL, NULL);
  SLInsert(si, "My");
  SLInsert(si, "Name");
  SLInsert(si, "Name");
  SLInsert(si, "Is");
  SLInsert(si, "Mina");
  
  SLRemove(si, "My");
  
  si->curr=si->head;
  while(si->curr != NULL)
  {
     printf("%s ",si->curr->data);       
     si->curr= si->curr->next;  
  } 
 	
	
	
	return 0;
}
