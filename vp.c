#include<stdio.h>
#include <string.h>
char stack[10];
int top = -1;
int MAX = 10;
void push(char c)
{
	if(top == MAX-1)
	{
		printf("Stack Overflow!");
	}
	else
	{
		top++;
		stack[top]=c;
	}
}
void pop()
{
	if(top == -1)
	{
		printf("Stack Underflow!");
	}
	else
	{
		top--;
	}
}
void vp(char exp[])
{
	int l = strlen(exp);
	int flag=0;
	for(int i=0;i<l;i++)
	{
		if(exp[i] !=')'||exp[i] !=']'||exp[i] !='}')
		{
			char c = exp[i];
			push(c);
		}
		else if(exp[i]='}')
		{
			if(stack[top]=='{')
			{	
				pop();
			}
			else
			{
				printf("Paranthesis check not valid.");
				flag=1;
				break;
			}
		}
		else if(exp[i]=')')
		{
			if(stack[top]=='(')
			{	
				pop();
			}
			else
			{
				printf("Paranthesis check not valid.");
				flag=1;
				break;
			}
		}
		else if(exp[i]=']')
		{
			if(stack[top]=='[')
			{	
				pop();
			}
			else
			{
				printf("Paranthesis check not valid.");
				flag=1;
				break;
			}
		}
		else
		{
		continue;
		}
		
	}
	if(flag == 0)
	{
		printf("Valid Parenthesis!!!");
	}
}
int main()
{
	char exp[10];
	printf("Enter the string:");
	scanf("%s",exp);
	vp(exp);
	return 0;
}
	
