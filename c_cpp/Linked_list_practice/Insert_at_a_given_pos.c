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
        printf("Enter the data of the node: ");
        scanf("%d", &x);
        temp->data = x;
        temp->next = NULL; // mandatoy step
        printf("\n Wanna enter more?(y/n)");
        scanf(" %c", &ch);
        if (ch == 'Y' || ch == 'y')
        {
            temp->next = (struct node *)malloc(sizeof(struct node));
            if (temp == NULL)               // Not so mandatory
            {                               // Not so mandatory
                printf("\nOut of RAM!!! "); // Not so mandatory
                exit(0);                    // Not so mandatory
            }                               // Not so mandatory
            temp = temp->next;
        }
    } while (ch == 'Y' || ch == 'y');
    return (head);
}
struct node *insertPos(struct node *head)
{
    // We need to iterate the loop pos -2 times
    printf("\nEnter the element to be inserted: ");
    int d;
    scanf("%d", &d);
    int pos;
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    struct node *curr = head;
    for (int i = 1; i <= (pos - 2) && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
        return head;

    temp->next = curr->next;
    curr->next = temp;
    return head;
}
void display(struct node *head)
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
    struct node *h;
    h = input();
    insertPos(h);
    display(h);
    return 0;
}