#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Binary_Tree node;
struct Binary_Tree
{
    char data;
    node* left;
    node* right;
} * root = NULL;

node* stack[MAX];
int top = -1;

void Inorder(node* r)
{
    if (r)
    {
        Inorder(r->left);
        printf("%c", r->data);
        Inorder(r->right);
    }
}

void Postorder(node* r)
{
    if (r)
    {
        Postorder(r->left);
        Postorder(r->right);
        printf("%c", r->data);
    }
}

void Preorder(node* r)
{
    if (r)
    {
        printf("%c", r->data);
        Preorder(r->left);
        Preorder(r->right);
    }
}

void push(node* Tnode)
{
    if (top == MAX - 1)
    {
        printf("\n Stack Overflow");
        return;
    }
        stack[++top] = Tnode;
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow");
        return ;
    }
    top--;
}

node* getTop() {
    if (top == -1) {
        return NULL;
    }
    return stack[top];
}
int isOperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
        return 1;
    return 0;
}
node* construct(char postfix[])
{
    node* T1;node* T2;
    if (strlen(postfix)==0)
    {
        return NULL;
    }

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperator(postfix[i]))
        {
            node* newnode=(node*)malloc(sizeof(node));
            T1=getTop();
            newnode->right = T1;
            pop();
            T2=getTop();
            newnode->left = T2;
            pop();
            newnode->data = postfix[i];
            push(newnode);
        }
        else
        {
            node* newnode = (node*)malloc(sizeof(node));
            newnode->left = NULL;
            newnode->right = NULL;
            newnode->data = postfix[i];
            push(newnode);
        }
    }
    return getTop(); 
}
int main()
{
    printf("Enter the Postfix Expression -\n");
    char postfix[100];
    scanf("%s", postfix);
    printf("%s\n", postfix);
    root = construct(postfix);

    printf("Postorder Traversal -\n");
    Postorder(root);
     printf("\n\n");
    printf("Inorder Traversal -\n");
    Inorder(root);
     printf("\n\n");
    printf("Preorder Traversal -\n");
    Preorder(root);
    return 0;
}