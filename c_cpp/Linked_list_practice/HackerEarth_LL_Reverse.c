#include <stdio.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *input()
{
    struct node *temp, *head;
    temp = (struct node *)malloc(sizeof(struct node));
    head = temp;
    int x;
    char ch;
    do
    {
        /* code */
        printf("\n Enter the data of the node: ");
        scanf("%d", &x);
        temp->data = x;
        temp->next = NULL;
        printf("\n Enter your choice: ");
        scanf(" %c", &ch);
        if (ch == 'Y' || ch == 'y')
        {
            temp->next = (struct node *)malloc(sizeof(struct node));
            if (temp == NULL) //out of RAM
            {
                printf("\n Out of RAM");
                exit(0);
            }
            temp = temp->next;
        }

    } while (ch == 'Y' || ch == 'y');
    return (head);
}

void rev(struct node *head)
{
    struct node *temp = head;
    struct node *curr = head;
}

void printlist(struct node *head)

{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}
int main()
{

    return 0;
}