#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
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

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

int isOperand(char x)
{
    if (x == '+' || '-')
        return 0;
    else
        return 1;
}

char *InToPos(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))

            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i] > pre(top->data)))

                push(infix[i++]);

            else

                postfix[j++] = pop();
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c";
    push('#');
    char *postfix = InToPos(infix);
    printf(" The postfix expression is : %s", postfix);
    return 0;
}
