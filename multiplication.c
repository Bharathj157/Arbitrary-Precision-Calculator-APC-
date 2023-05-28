/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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


int mul_addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2)
{
    Dlist *t1=*tail1,*t2=*tail2; 
    int flag=0,num,temp;
  
//   print_list(*head1);

  // print_list(*head2); 
   while(t2!=NULL && t1!=NULL)
   {
       num=t1->data+t2->data+flag;
      // printf("%d %d %d\n",num,t1->data,t2->data);
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
       if(t2!=NULL)
       t2->data=num%10;
       else
       dl_insert_first(head2,tail2,num%10);

       t1=t1->prev;
       t2=t2->prev;
   }

   if(t2==NULL && t1!=NULL)
   { 
     //  printf("1st condition\n");
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
    //                    printf("%d\n",flag);
           }
           dl_insert_first(head2,tail2,num%10);
           t1=t1->prev;
     //      printf("inner loop\n");
       }
       if(flag!=0)
           dl_insert_first(head2,tail2,flag);

   }
   else if(t1==NULL && t2!=NULL)
   {
      // printf("Second conditin\n");
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
      //         printf("%d\n",flag);
           }
           t2->data=num%10;
           t2=t2->prev;
       }

       if(flag!=0)
           dl_insert_first(head2,tail2,flag);
   }
   else
   {
       
       if(flag!=0)
       {
	 //  printf("%d\n",flag);
           dl_insert_first(head2,tail2,flag);
       }
     
   }
}


int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR,Dlist **headR2,Dlist **tailR2,char *argv[])
{
	/* Definition goes here */
	
     int signvar=0;
     if(argv[1][0]=='-')
	 signvar++;
     if(argv[3][0]=='-')
	 signvar++;
	 
   *tailR2=NULL;
    Dlist *t1=*tail1,*t2=*tail2,*tR=*tailR;
    dl_insert_first(headR2,tailR2,0);

   // print_list(*headR2);
    int flag=0,num,temp,count=1;

  while(t2!=NULL)
  { 
   t1=*tail1;
   tR=*tailR;  
   flag=0; 
    while(t1!=NULL)
    {
       num=t1->data*t2->data+flag;
     //  printf("%d %d %d\n",num,t1->data,t2->data);
     //  printf("INNER\n");
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

     if(count==1)
     {
       if(tR==NULL || tR->prev==NULL)
       {
	 
          dl_insert_first(headR,tailR,num%10);
       
	  tR=*headR;

	 // printf("hiii\n");
	
	 // tR=tR->prev;

	//  printf("hello\n");
       }
       else
       tR->data=num%10;
     }
     else
	 dl_insert_first(headR,tailR,num%10);
     
       tR=tR->prev;
       t1=t1->prev;
    }

    if(flag!=0)
    {
	dl_insert_first(headR,tailR,flag);
	
    }
       
    mul_addition(headR,tailR,headR2,tailR2);

//   print_list(*headR);

    dl_delete_list(headR,tailR);

    for(int i=0;i<count;i++)
	dl_insert_first(headR,tailR,0);

    count++;
    t2=t2->prev;
 }
 
 if((*headR2)->next!=NULL)
    {
        while((*headR2)->data==0)
	{
            dl_delete_first(headR2,tailR2);
	    if((*headR2)==(*tailR2))
	    {
		break;
	    }
	}
    }
   if((*tail2)->prev!=NULL)
   { 
   if(signvar==1)
    printf("-");
   }

}
