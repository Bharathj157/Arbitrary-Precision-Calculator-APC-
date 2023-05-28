/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "apc.h"

int input_validate(int argc,char *argv[])
{
    if(argc!=4)
    { 
	return FAILURE;
    }

    if(argv[2][0]=='+' || argv[2][0]=='-'|| argv[2][0]=='x'|| argv[2][0]=='/')
	return SUCCESS;
    else
    {
	
	return FAILURE;
    }
}

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    //CREATING NEW NODE
    Dlist *new=malloc(sizeof(Dlist));

    //INSERTING value to new node 
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
    new->prev=*tail;
    (*tail)->next=new;
    *tail=new;
}

void insert_list(char *argv[],Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2)
{
    int num;

    for(int i=0;i<strlen(argv[1]);i++)
    {
	if(argv[1][i]!='+' && argv[1][i]!='-'){

	    num=(int)(argv[1][i]-'0');
	    dl_insert_last(head1,tail1,num);
	}
    }

//    print_list((*head1));

    for(int i=0;i<strlen(argv[3]);i++)
    {

	if(argv[3][i]!='+' && argv[3][i]!='-'){
	    num=(int)(argv[3][i]-'0');
	    dl_insert_last(head2,tail2,num);
	}
    }

  //  print_list((*head2));

}


void print_list(Dlist *head)
{
    /* Cheking the list is empty or not */
    if (head == NULL)
    {
	printf("INFO : List is empty\n");
    }
    else
    {
	while (head)		
	{
	    /* Printing the list */
	    printf("%d", head -> data);

	    /* Travering in forward direction */
	    head = head -> next;	    
	}
	printf("\n");	
    }
}

int extraction(int argc,char *argv[])
{
    int minus=0;
    if(argv[2][0]=='x')
	return 2;
    if(argv[2][0]=='/')
	return 3;

    if(argv[1][0]=='-')
	minus++;
    if(argv[2][0]=='-')
	minus++;
    if(argv[3][0]=='-')
	minus++;

    if(minus%2==0)
	return 0;
    else
	return 1;
}

int main(int argc,char *argv[])
{
    /* Declare the pointers */
    Dlist *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL ,*headR=NULL,*tailR=NULL,*t1,*t2,*temp,*headR2=NULL,*tailR2=NULL;
    char option, operator;
    int sign=0,check,c1=0,c2=0,check_zero;

      
    /* Code for reading the inputs */
    if(input_validate(argc,argv)==SUCCESS)
    {
	printf("VAlidation is successful\n");
    }
    else
    {
	printf("VAlidarion is unsuccessful\n");
	return 0;
    }
    /* Function for extracting the operator */
    check=extraction(argc,argv);

    if(check==0)
	operator='+';
    else if(check==1)
	operator='-';
    else if(check==2)
	operator='x';
    else if(check==3) 
	operator='/';

    insert_list(argv,&head1,&tail1,&head2,&tail2);
    
    if(operator == '-' || operator =='+'){  
	t1=head1;
	t2=head2;
	if(strlen(argv[1])==strlen(argv[3]))
	{
	    if(argv[1][0]=='-' && argv[3][0]!='-')
	    {
                  sign=1;
	    }
	    else if(argv[1][0]!='-' && argv[3][0]=='-')
	    {
	          sign=0;
	    }
	    else if(head1->data==head2->data)
	    {
		while(t1->data==t2->data)
		{
		    t1=t1->next;
		    t2=t2->next;

		    if(t1==NULL)
			break;

		}
		if(t1!=NULL && t2!=NULL)
		{
		    if(t1->data > t2->data)
		    {
		       if(argv[1][0]=='-')
			   sign=1;
		    }

		}
		else
		{
		   if(argv[1][0]=='-' && argv[3][0]=='-' && argv[2][0]=='+')
		       sign=1;
		}


            }
	    else if(head1->data  > head2->data)
	    {
		if(argv[1][0]=='-')
		    sign=1;
	    }
	    else
	    {
		if(argv[3][0]=='-' || argv[2][0]=='-')
		    sign=1;
	    }


	}
	else
	{
	    
	    while(t1->next!=NULL){
		t1=t1->next;
		c1++;
	    }
	    while(t2->next!=NULL){
		t2=t2->next;
		c2++;
	    }

	    if(c1>c2)
	    {
		if(argv[1][0]=='-')
		    sign=1;
	    }
	    else if(c1<c2)
	    {
		if(argv[3][0]=='-'||argv[2][0]=='-')
		    sign=1;
	    }
	    else
	    {
		t1=head1;
		t2=head2;
		while(t1->data==t2->data)
		{
                    t1=t1->next;
		    t2=t2->next; 

		    if(t1==NULL||t2==NULL)
			break;
		}

		if(t1==NULL && t2==NULL)
		{
                    if(argv[1][0]=='-'||argv[3][0]=='-')
			sign=1;
		}
		else if(t1==NULL&&t2!=NULL)
                {
		    if(argv[3][0]=='-'&&argv[2][0]!='-')
			sign=1;
		
		}
		else if(t1!=NULL && t2==NULL)
		{
                    if(argv[1][0]=='-')
			sign=1;
		}
		else if(t1!=NULL && t2!=NULL)
		{
	        if(t1->data > t2->data)
		{
		    if(argv[1][0]=='-')
			sign=1;
		}
		else
		{
		    if(argv[3][0]=='-')
			sign=1;
		}
		}
	    }

	}
    }
   
    if(operator=='-' || operator=='x'){
	t1=head1;
	t2=head2;
	if(strlen(argv[1])==strlen(argv[3]))
	{
	    if(argv[1][0]=='-' && argv[3][0]=='-'){

		while(t1->data==t2->data)
		{
		    t1=t1->next;
		    t2=t2->next;

		    if(t1==NULL)
			break;
		}
                
		if(t1!=NULL&&t2!=NULL)
		{
		if(t1->data<t2->data)
		{   
		    temp=head1;
		    head1=head2;
		    head2=temp;

		    temp=tail1;
		    tail1=tail2;
		    tail2=temp; 
		}
		}
	    }
	    else if(argv[1][0]=='-' && argv[3][0]!='-')
	    {
		temp=head1;
		head1=head2;
		head2=temp;

		temp=tail1;
		tail1=tail2;
		tail2=temp;  
	    }
	    else if(argv[1][0]!='-'&& argv[3][0]!='-')
	    {	

		while(t1->data==t2->data)
		{
		    t1=t1->next;
		    t2=t2->next;
		    if(t1==NULL)
			break;
		}

		if(t1!=NULL){
		if(t1->data < t2->data)
		{	
		    temp=head1;
		    head1=head2;
		    head2=temp;

		    temp=tail1;
		    tail1=tail2;
		    tail2=temp;
		}
            }
	    }
	}
	else if(strlen(argv[1]) < strlen(argv[3]))
	{
	    while(t1->next!=NULL){
		t1=t1->next;
		c1++;
	    }
	    while(t2->next!=NULL){
		t2=t2->next;
		c2++;
	    }
	    if(c1<c2){
		temp=head1;
		head1=head2;
		head2=temp;

		temp=tail1;
		tail1=tail2;
		tail2=temp;
	    } 
	}
	else 
	{

	    while(t1->next!=NULL){
		t1=t1->next;
		c1++;
	    }
	    while(t2->next!=NULL){
		t2=t2->next;
		c2++;
	    }
	    if(c1==c2)
	    {
		if(head1->data < head2->data)
		{ 
		    temp=head1;
		    head1=head2;
		    head2=temp;

		    temp=tail1;
		    tail1=tail2;
		    tail2=temp;

		} 

	    }
	}
    }
    //  print_list(head1);
    //  print_list(head2); 
    switch (operator)
    {
	case '+':
	    /* call the function to perform the addition operation */
	    addition(&head1, &tail1, &head2, &tail2, &headR,&tailR);
	    if(argv[2][0]=='+')
	    printf("Addition of 2 numbers is : ");
	    else
	    printf("Subtraction of 2 numbers is : ");

	    if(sign==1)
		printf("-");
	    print_list(headR);
	    break;
	case '-':	
	    /* call the function to perform the subtraction operation */
	    check_zero=subtraction(&head1, &tail1, &head2, &tail2, &headR,&tailR);
	    if(argv[2][0]!='-')
	    printf("Addition of 2 numbers is : ");
	    else
	    printf("Subtraction of 2 numbers is : ");

	    if(sign==1 && check_zero==1)
		printf("-");
	    print_list(headR);
	    break;
	case 'x':	
	    /* call the function to perform the multiplication operation */
	    printf("Multiplication of two number is : ");
	    multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR,&headR2,&tailR2,argv);
	    print_list(headR2);
	    break;
	case '/':	
	    printf("Division of 2 numbers is : ");
	    division(&head1, &tail1, &head2, &tail2, &headR, &tailR,argv);
	    /* call the function to perform the division operation */
	    break;
	default:
	    printf("Invalid Input:-( Try again...\n");
    }
    return 0;
}
