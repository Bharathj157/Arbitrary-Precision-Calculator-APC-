/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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
int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    //CREATING NEW NODE
    Dlist *new=malloc(sizeof(Dlist));
    
    //INSERING value to new node 
    new->prev=NULL;
    new->next=NULL;
    new->data=data;
    
    //checking for list empty
    if(*head==NULL || *tail==NULL)
    { 
        *tail=*head=new;
        return SUCCESS;
    }
    
    //logic for mutiple node
    new->next=*head;
    (*head)->prev=new;
    (*head)=new;
    return SUCCESS;
}

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
    
    Dlist *t1=*tail1,*t2=*tail2; 
    int flag=0,num,temp,i=0,k =1;
   
   while(t2!=NULL && t1!=NULL)
   {
                  
       num=t1->data+t2->data+flag;
       if(num<10)
       {
	   flag=0;
       }
       else
       {
	   temp=num;
	   temp/=10;
	   flag=temp%10;
       }
       dl_insert_first(headR,tailR,num%10);
    t1=t1->prev;
       t2=t2->prev;


   }

   if(t2==NULL && t1!=NULL)
   { 
       while(t1!=NULL)
       {
	   num=t1->data+flag;

	   if(num<10)
	   {
	       flag=0;
	   }
	   else
	   {
	       temp=num;
	       temp/=10;
	       flag=temp%10;
	   }
	   dl_insert_first(headR,tailR,num%10);
	   t1=t1->prev;
       }
       if(flag!=0)
	   dl_insert_first(headR,tailR,flag);

   }
   else if(t1==NULL && t2!=NULL)
   {
       while(t2!=NULL)
       {
	   num=t2->data+flag;

	   if(num<10)
	   {
	       flag=0;
	   }
	   else
	   {
	       temp=num;
	       temp/=10;
	       flag=temp%10;
	   }
	   dl_insert_first(headR,tailR,num%10);
	   t2=t2->prev;
       }
       if(flag!=0)
	   dl_insert_first(headR,tailR,flag);
   }
   else
   {
       if(flag!=0)
	   dl_insert_first(headR,tailR,flag);
   }
}

