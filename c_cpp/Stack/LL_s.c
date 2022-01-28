#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *next;
} *top = NULL;

void push(int x)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct node *temp = top;

    int res = top->data;
    top = top->next;
    free(temp);

    return res;
}

bool isEmpty()
{
    return (top == NULL); // short hand code for return 1 if head is empty
}
int peek()
{
    return top->data;
}

int main()
{
    push(5);
    return 0;
    printf("%d", peek());
    return 0;
}
