#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;

    node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

node *insertBegin(struct node *head, int x)
{
    struct node *temp = new node(x);
    if (head == NULL)
        return temp;

    temp->next = head;
    head->prev = temp;
    temp->prev = NULL;

    return temp;
}

void display(struct node *head)
{
    struct node *curr = head;
    while (curr != NULL)
    {
        cout << (curr->data) << " -> ";
        curr = curr->next;
    }
}

int main()
{
    struct node *head = new node(10);
    struct node *temp1 = new node(20);
    struct node *temp2 = new node(30);
    struct node *temp3 = new node(40);

    head->next = temp1;
    head->prev = NULL;

    temp1->next = temp2;
    temp1->prev = head;

    temp2->next = temp3;
    temp2->prev = temp1;

    temp3->next = NULL;
    temp3->prev = temp2;
    insertBegin(head, 50);
    display(head);
    return 0;
}
