#include<stdio.h>
int MAX=5;
int queue[5];
int front=-1;
int rear=-1;
int size=5;

void enQueue(int n)
{
    if (rear == -1 && front == -1)
    {
        rear =0;
        front=0;
        queue[rear]=n;
    }
    else if(((rear + 1)% size)==front)
    	{
        
      	  printf("Queue is full");
   	}
    else
    	{
    	rear=(rear + 1)%size;
    	queue[rear]=n;
	}
};
void deQueue()
{
    if(rear == -1 && front==-1)
    {
        printf("Queue is empty");
        
    }
    else if(rear == front)
    {
        
        printf("%d has been removed from Queue",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
    	printf("%d has been removed from Queue",queue[front]);
    	front=(front+1)%size;
    }
    	
    		
}
void display()
{
    if(rear == -1 && front==-1)
    {
        printf("Queue is Empty");
        
    }
    else
    {
        
    int i;
    i =front;
    
    while(front != rear)
    {
    	printf("%d\t",queue[front]);
    	front=(front+1)%size;
    }
    printf("%d",queue[rear]);
    printf("\n");
    front= i;
    }
    
    
}
int main()
{
    int ch;
    while(ch != 4)
    {
    	printf("\n\n 1.enQueue \n2.deQueue \n3.display \n4.Exit \nEnter your Choice:");
    	scanf("%d",&ch);
    	switch(ch)
    {
        case 1:{
                    int n;
                    printf("Enter Number to be enQueued:");
                    scanf("%d",&n);
                    enQueue(n);
                    break;
                }
        case 2:{
                    deQueue();
                    break;
                }
        case 3:{
                    display();            
                }   break;
        case 4:{
                    break;
                }
    }
    }
    return 0;
}
