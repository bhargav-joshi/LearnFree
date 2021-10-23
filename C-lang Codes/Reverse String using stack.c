#include<stdio.h>
#define MAX 50
char stack[MAX];
int top=-1;
void push(char item)
{
	if(top==MAX-1)
		printf("Stack is full1\n");
	else
	{
		top++;
		stack[top]=item;
	}
}
int pop()
{
	char item;
	if(top==-1)
		printf("Stack is empty!\n");
	else
	{
		item=stack[top];
		top--;
		return item;
	}
}
int main(void)
{
	char str[20];
	int i,l;
	printf("Enter a string:\n");
	scanf("%s",str);
	for(l=0;str[l];l++);
	for(i=0;i<l;i++)
	{
		push(str[i]);
	}
	for(i=0;i<l;i++)
	{
		str[i]=pop();
	}
	printf("Reversed string is:%s\n",str);
	return 0;
}