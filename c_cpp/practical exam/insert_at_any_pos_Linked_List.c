#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *input()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *head = temp;
    int x;
    char ch;

    do
    {
        /* code */
        printf("Enter the value: ");
        scanf("%d", &x);
        temp->data = x;
        temp->next = NULL;
        printf("\nWanna enter more?(y/n)");
        scanf(" %c", &ch);

        if (ch == 'Y' || ch == 'y')
        {
            //create the next node
            temp->next = (struct node *)malloc(sizeof(struct node));
            if (temp == NULL) //OUT OF RAM
            {
                printf("\nOverflow!");
                exit(0);
            }
            temp = temp->next;
        }

    } while (ch == 'y' || ch == 'Y');
    return (head);
}
//inserting at any position
struct node *insert_pos(struct node *head, int x, int pos)
{
    struct node *curr = head;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    for (int i = 0; i <= pos - 2 && curr != NULL; i++)
    {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
    return (head);
}
void display(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node *head;
    head = input();
    insert_pos(head, 3, 1);
    display(head);
    return 0;
}