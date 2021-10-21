#include<stdio.h>
int top=-1,t=-1,n,no;
int stack[30],r[30];
int push(int);
void pop();
void reverse();
int isfull();
int isempty();
void display();
int main()
{
	int i,item,n;
	char ch;
	printf("enter size of stack::");
	scanf("%d",&no);
	do
	{
	   printf("enter the choice::1.push\n2.pop\n3.display list\n4.reverse of list");
	   scanf("%d",&n);
	   switch(n)
	   {
	   	case 1:printf("enter the item to be inserted:");
	   	       scanf("%d",&item);
	   	      push(item);
	   	       break;
	   	case 2:pop();
	   	       break;
	   	case 3:display();
												break;
					case 4:reverse();
				}
				printf("do you want to enter more::");
				scanf(" %c",&ch);
 }
 while((ch=='y')||(ch=='Y'));
	
	
}
int push(int item)
{
	if(!isfull())
	 stack[++top]=item;
	 else
	 printf("\nno element can be inserted");
}
void pop()
{
	if(!isempty())
	top--;
	else
	printf("\n no element can be deleted");
}
void display()
{
	int i;
	if(!isempty())
	{
	for(i=top;i>-1;i--)
	 {
	   printf("%d ",stack[i]);
		}
	}
	else
	printf("no element to display::");
}
void reverse()
{
	int i;
	if(!isempty())
	{
	while(top!=-1)
	{
		r[++t]=stack[top--];
	}
	for(i=t;i>-1;i--)
	{
	 printf("%d ",r[i]);
	}
}
else
{
	printf("no element to display::");
}
}
int isfull()
{
	if(top==no-1)
	return 1;
	else
	return 0;
}
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
