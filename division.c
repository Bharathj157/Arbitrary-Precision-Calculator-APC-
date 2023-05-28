/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head==NULL || *tail==NULL)
    return  FAILURE;
    
    while((*head)->next!=NULL)
    {
        *head=(*head)->next;
        free((*head)->prev);
    }
    
    free((*head));
    *head=*tail=NULL;

}

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR, char *argv[])
{
	/* Definition goes here */
    int signvar=0;
     if(argv[1][0]=='-')
	 signvar++;
     if(argv[3][0]=='-')
	 signvar++;
    if((*head2)->data==0 && (*head2)->prev==NULL && (*head2)->prev==NULL)
    {
	printf("NOT DEFINED / INFINITY\n");
	return 0;
    }

    int c1=0,c2=0,q=1;
    Dlist *t1=*head1;
    Dlist *t2=*head2;
    
    while(t1 != NULL)
    {
	t1=t1->next;
	c1++;
    }

    while(t2 != NULL)
    {
	t2=t2->next;
	c2++;
    }
    t1=*head1;
    t2=*head2;    
    if(c1 == c2)
    {
         
       while(t1!=NULL && t2!= NULL && t1->data==t2->data){
	   t1=t1->next;
           t2=t2->next;
       }
       if(t1!=NULL && t2!=NULL){
       if((t2)->data > (t1)->data)
       {
	   printf("0\n");
	   return FAILURE;
       }
       }
    }
    else if(c2 > c1)
    {
        printf("0\n");
	return FAILURE;
    }

   while(1)
    {
	c1=0,c2=0;
	subtraction(head1,tail1,head2,tail2,headR,tailR);	
        dl_delete_list(head1,tail1);
        *head1=*headR;
	*tail1=*tailR;
	*headR=NULL;
	*tailR=NULL;
    t1=*head1;
    t2=*head2;   
   
    while(t1!=NULL)
    {
	t1=t1->next;
	c1++;
    }

    while(t2!=NULL)
    {
	t2=t2->next;
	c2++;
    }
    t1=*head1;
    t2=*head2;    
	
    
    if(c1==c2)
    {
	
       while(t1!=NULL && t2!=NULL && t1->data==t2->data){
	   t1=t1->next;
           t2=t2->next;
       }

      if(t1!=NULL&&t2!=NULL){ 
       if((t1)->data < (t2)->data)
       {
         break;
       }
      }
    }
    else if(c1 < c2)
    {
       break;
    }

    q++;
     
    }
    if(signvar==1)
    printf("-");

    printf("%d\n",q);
    return 0;
}
