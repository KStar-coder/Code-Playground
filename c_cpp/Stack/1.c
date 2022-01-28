#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int *arr;
    int capacity;
    int top;

    stack(int c)
    {
        capacity = c;
        arr = (int *)malloc(sizeof(int) * capacity);
        top = -1;
    }
    // push with overflow warning, pop with underflow warning, peak with underflow warning, size, isEmpty
    void push(int x)
    {
        if (top + 1 == capacity)
        {
            printf("\nOVERFLOW!");
            exit(1);
        }
        top++;
        arr[top] = x;
    }
    int pop()
    {
        if (top == -1)
        {
            printf("\n UNDERFLOW");
            exit(2);
        }
        int res = arr[top];
        top--;
        return res;
    }
    int peak()
    {
        if (top == -1)
        {
            printf("\n Warning UNDERFLOW! Can't peek \n");
            return 0;
        }
        else
            return arr[top];
    }
    int size()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};

int main()
{
    stack s(3);
    s.push(1);
    printf("%d", s.peak());
    s.push(2);
    printf("%d", s.peak());
    s.push(3);
    printf("%d", s.peak());

    s.pop();
    printf("%d", s.peak());
    s.pop();
    printf("%d", s.peak());
    s.pop();
    printf("%d", s.peak());
}