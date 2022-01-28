struct node *insert_pos(struct node *head, int x, int pos)
// {
//     struct node *curr = head;
//     if (head == NULL)
//     {
//         return NULL;
//     }
//     for (int i = 0; i <= pos - 2; i++)
//     {
//         curr = curr->next;
//     }
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = x;
//     temp = curr->next;
//     curr->next = temp;
//     return (head);
// }