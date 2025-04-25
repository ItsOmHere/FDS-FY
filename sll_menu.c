#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
	};
	struct node *head,*temp,*new,*prev;
void insAtFirst()
{
	int n;
	head=NULL;
	new=malloc(sizeof(struct node));
	printf("Enter the data of node:");
	scanf("%d",&new->data);
	
	if(head == NULL)
		{
			head=new;
			temp=new;
		}
	else	
		{
			new->next=head;
			head=new;
					
		}
};
void insAtLast()
{
	int n;
	head=NULL;
	
	new=malloc(sizeof(struct node));
	printf("\nEnter the data in node:");
	scanf("%d",&new->data);
	if(head == NULL)
		{
			head=new;
			temp=new;
		}
	else
		{
			while(temp->next !=NULL)
			{
				temp= temp->next;
			}
			temp->next=new;
			temp=new;		
		}
};
void delAtFirst()
{	
	if(head == NULL)
	{
		printf("Empty");
	}
	else
	{
		temp=head;
		head=head->next;
		temp->next=NULL;
		free(temp);
	}
};
void delAtLast()
{
	if(head == NULL)
	{
		printf("Linked list is Empty");
	}
	else
	{
		temp = head;
		while(temp->next != NULL)
		{
			prev=temp;
			temp = temp->next;
		}
		if(temp == head)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			prev->next = NULL;
			free(temp);
		}
	}
};
void display()
{
	if(head == NULL)
	{
		printf("Linked list is Empty");
	}
	else
	{
		printf("Linked list: ");
		temp = head;
		while(temp != NULL)
		{
		printf("\t%d",temp->data);
		temp=temp->next;
		}
	
	}
};

void main()
{
	head=NULL;
	int ch,ch1;
	do
	{
		printf("\n\n1.Insertion\n2.Deletion\n3.display\n4.Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					printf("\n\n1.Insert At First\n2.Insert At Last\nEnter your Choice:");
					scanf("%d",&ch1);
					switch(ch1)	
					{
						case 1 : insAtFirst(); break;
						case 2 : insAtLast(); break;
						default : printf("Wrong Choice");
					}
					break;
				}
			case 2:
				{
					printf("\n\n1.Delete At First\n2.Delete At Last\nEnter your Choice:");
					scanf("%d",&ch1);
					switch(ch1)	
					{
						case 1 : delAtFirst(); break;
						case 2 : delAtLast(); break;
						default : printf("Wrong Choice");
					}
					break;
				}
			case 3: 
				{
					display();
					break;
				}
			case 4: printf("Exiting");break;
			default :
				{
					printf("Wrong Choice");
				}
		}
	}while(ch != 4);
};
	
	
			
