#include<stdio.h>
#include<string.h>
#define MAX 20
#define length 20
char playlist[MAX][length];
int rear =-1;
int front = -1;

void enQueue(char song[])
{
    if (rear == -1 && front == -1)
    {
        rear =0;
        front=0;
        strcpy(playlist[rear],song);
    }
    else if(((rear + 1)% MAX)==front)
    {
        
        printf("Playlist is full");
    }
    else{
    	rear=(rear + 1)%MAX;
    	strcpy(playlist[rear],song);
	}
};
void deQueue()
{
    if(rear == -1 && front==-1)
    {
        printf("Playlist is empty");
        
    }
    else if(rear == front)
    {
        
        printf("Now playing: %s",playlist[front]);
        front=-1;
        rear=-1;
    }
    else
    {
    	printf("Now Playing: %s",playlist[front]);
    	front=(front+1)%MAX;
    }
    	
    		
}
void display()
{
    if(rear == -1 &&front==-1)
    {
        printf("Playlist is Empty");
        
    }    
    else
    {
        
    int i;
    for(i=front;i != rear;i=(i+1)%MAX)
    {
    	printf("%d. %s",i-front+1,playlist[i]);
    }
    printf("%d. %s",i-front+1,playlist[rear]);

    }
    
};
int main()
{
	int ch;
	char song[length];
	do
	{
		printf("=== Music Playlist Menu ===\n");
        	printf("1. Add Song\n");
        	printf("2. Play Next Song\n");
        	printf("3. Display Playlist\n");
        	printf("4. Exit\n");
        	printf("Choose an option: ");
        	scanf("%d", &ch);
        	getchar();
        	switch(ch)
        	{
        		case 1:
        			{
        				printf("Enter Song Name:");
        				fgets(song,length,stdin);
        				enQueue(song);
        				break;
        			}
        		case 2:
        			{
        				deQueue();
        				break;
        			}
        		case 3:
        			{
        				printf("====Songs Coming Next====");
        				display();
        				break;
        			}
        		case 4:
        			{
        				printf("Exitiong....!");
        				break;
        			}
        		default :
        			{
        				printf("Invalid Choice.....!");
        			}
        	}
        
        } while(ch != 4);
  	return 0;
}	
        
		
	
