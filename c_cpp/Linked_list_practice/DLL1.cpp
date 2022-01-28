#include <iostream>

using namespace std;

class node
{
public:
    int key;
    int data;
    struct node *next;
    struct node *prev;

    node()
    {
        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
    }
    node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class DoublyLinkedList
{
public:
    node *head;
    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(node *n)
    {
        head = n;
    }
    // standard operations of doubly linked list

    // 1)check if a node exist

    node *CheckIfExists(int k)
    {
        node *temp = NULL;
        node *ptr = head;
        {
            while (ptr != NULL)
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp; // returns that node if it exists else returns NULL
        }
    }

    // 2) Append a node to the list(attach another node to the end)
    void AppendNode(node *n)
    {
        if (CheckIfExists(n->key) != NULL)
        {
            cout << "Node with key value: " << n->key << " already exists" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended as head node" << endl;
            }
            else
            {
                node *ptr;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->prev = ptr;
                n->next = NULL;
                cout << "Node appended" << endl;
            }
        }
    }
    void PrependNode(node *n)
    {
        if (CheckIfExists(n->key) == NULL)
        {
            cout << "Node with key value: " << n->key << " already exists" << endl;
        }
        else if (head == NULL)
        {
            head = n;
            cout << "Node prepended as head node" << endl;
        }
        else
        {
            head->prev = n;
            n->next = head;
            n = head;
            cout << "Node prepended" << endl;
        }
    }
    // 3) Insert in between
    void InsertNode(int k, node *n)
    {
        node *ptr = CheckIfExists(k); // will either return the node after which we need to insert or NULL
        if (ptr == NULL)
        {
            cout << "No node exists with key value: " << k << endl;
        }
        else
        {
            if (CheckIfExists(n->key) != NULL)
            {
                cout << "Node with key: " << k << " already exists" << endl;
            }
            else
            {
                node *nextnode = ptr->next;
                if (nextnode == NULL)
                {
                    ptr->next = n;
                    n->prev = ptr;
                    cout << "Node inserted at the end" << endl;
                }
                else
                {
                    n->next = nextnode;
                    ptr->next = n;
                    n->prev = ptr;
                    nextnode->prev = n;
                    cout << "Node inserted after the node with key value: " << k << endl;
                }
            }
        }
    }

    // Delete node by unique key
    void DeleteNode(int k)
    {
        node *ptr = CheckIfExists(k);
        if (ptr == NULL)
        {
            cout << "Node with the given key does not exist" << endl;
        }
        else
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "The head node has been delinked and new head is updated";
            }
            else
            {
                node *nextnode = ptr->next;
                node *prevnode = ptr->prev;
            }
        }
    }
};

int main()
{

    return 0;
}