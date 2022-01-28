#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create()
{
    int v;
    struct node *s, *p;
    char ch;
    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("\n Out of RAM");
        exit(1);
    }
    s = p;
    do
    {
        printf("\nEnter the data of the node:");
        scanf("%d", &v);
        p->data = v;
        p->next = NULL;
        fflush(stdin);
        printf("\nWanna enter more?");
        scanf(" %c", &ch);
        if (ch == 'Y' || ch == 'y')
        {
            p->next = (struct node *)malloc(sizeof(struct node));
            if (p->next == NULL)
            {
                printf("\n Out of RAM mf!");
                exit(1);
            }
            p->next->prev = p;
            p = p->next;
        }
    } while (ch == 'Y' || ch == 'y');
    return s; // start node
}

struct node *insertBegin(struct node *head, int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head->next;
    head->next = temp;
    temp->prev = head;
    // swap data
    int t = temp->data;
    temp->data = head->data;
    head->data = t;
    return head;
}

void disp(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
    }
}
int main()
{
    struct node *h;
    h = create();
}
