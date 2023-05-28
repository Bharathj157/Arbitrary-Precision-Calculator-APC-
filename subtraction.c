/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include<stdio.h>
#include<stdlib.h>

int dl_delete_first(Dlist **head, Dlist **tail)
{
    //checking for empty list
    if(*head==NULL || *tail==NULL)
    return  FAILURE;
    
    //checking for single node
    if((*head)->next==NULL)
    {
        free((*head));
        *head=*tail=NULL;
        return SUCCESS;
    }
    
    //logic 
    *head=(*head)->next;
    free((*head)->prev);
    (*head)->prev=NULL;
}

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
    
    /* Definition goes here*/
    Dlist *t1=*tail1,*t2=*tail2;
    int flag=0,num;
    while(t1!=NULL && t2!=NULL)
    {
	if(flag==1)
	    t1->data--;

        if(t1->data < t2->data)
	{
	    
	    num=10+t1->data-t2->data;
	    flag=1;
	  //  printf("%d %d\n",t1->data,t2->data,num);
	}
	else
	{
	    num=t1->data-t2->data;
	    flag=0;
	//   printf("%d %d\n",t1->data,t2->data,num);
	}
	dl_insert_first(headR,tailR,num);
	t1=t1->prev;
	t2=t2->prev;
    }

    if(t2==NULL&&t1!=NULL)
    {
	while(t1!=NULL)
	{
	     if(flag==1)
	     {
	        if(t1->data==0)
	        {
		    flag=1;
		    t1->data--;
		    num=t1->data+10;
		    dl_insert_first(headR,tailR,num);
		}
                else
		{
		     flag=0;
		     t1->data--;
		     dl_insert_first(headR,tailR,t1->data);
		}
	     }
	     else
	     {
	        dl_insert_first(headR,tailR,t1->data);
	     }

	     t1=t1->prev;
       	}
    }
  
    if((*headR)->next!=NULL)
    {
        while((*headR)->data==0)
	{
            dl_delete_first(headR,tailR);
	    if((*headR)==(*tailR))
	    {
		break;
	    }
	}
    }
    if(*headR==*tailR && (*headR)->data==0)
    return 0;
    else
    return 1;
}
