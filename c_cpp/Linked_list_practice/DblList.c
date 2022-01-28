#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct ll
{
	int info;
	struct ll *prev;
	struct ll *next;
};
typedef struct ll node;

node *create()
{
	char ch;
	int v;
	node *s, *p; // here, s is the start node
	p = (node *)malloc(sizeof(node));
	if (p == NULL)
	{
		printf("Memory full. Cannot create list.");
		exit(0);
	}
	s = p;
	do
	{
		printf("Enter node info :");
		scanf("%d", &v);
		p->info = v;
		p->next = NULL;
		fflush(stdin);
		printf("Continue?");
		scanf("%c", &ch);
		if (ch == 'y' || ch == 'Y')
		{
			p->next = (node *)malloc(sizeof(node));
			if (p->next == NULL)
			{
				printf("Memory full. Cannot create list.");
				exit(0);
			}
			p->next->prev = p; // Link to Previous node.
			p = p->next;
		}
	} while (ch == 'y' || ch == 'Y');
	s->prev = NULL; // Prev part of first node is null.
	return (s);
}
node *insfirst(node *s, int v)
{
	node *nw = (node *)malloc(sizeof(node));
	nw->info = v;
	nw->next = s;
	nw->prev = NULL;
	s->prev = nw;
	s = nw;
	return (s);
}
node *inslast(node *s, int v)
{
	node *p = s, *t, *nw;
	nw = (node *)malloc(sizeof(node));
	nw->info = v;
	nw->next = NULL;
	nw->prev = NULL;
	if (s == NULL)
		s = nw;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = nw;
		nw->prev = p;
	}
	return (s);
}
node *inspos(node *s, int pos, int v)
{
	int cnt = 0;
	node *p, *pr = NULL, *nw;
	nw = (node *)malloc(sizeof(node));
	nw->info = v;
	nw->next = NULL;
	nw->prev = NULL;
	p = s;
	while (p)
	{
		cnt++;
		if (cnt == pos)
			break;
		pr = p;
		p = p->next;
	}
	if (p == NULL)
	{
		if (cnt + 1 == pos)
		{
			pr->next = nw;
			nw->prev = pr;
		}
		else
			printf("Element not found in this position");
	}
	else
	{
		if (p == s)
		{
			nw->next = s;
			s->prev = nw;
			s = nw;
		}
		else
		{
			nw->next = p;
			nw->prev = p->prev;
			p->prev = nw;
			nw->prev->next = nw;
		}
	}
	return (s);
}

node *delfirst(node *s)
{
	node *p = s;
	s = s->next;
	if (s != NULL)
		s->prev = NULL;
	free(p);
	return (s);
}
node *dellast(node *s)
{
	node *p = s, *t;
	if (p->next == NULL)
	{
		t = p;
		s = NULL;
	}
	else
	{
		while (p->next != NULL)
			p = p->next;
		t = p;
		p->prev->next = NULL;
		t->prev = NULL;
	}
	free(t);
	return (s);
}
node *delpos(node *s, int pos)
{
	int cnt = 0, i;
	node *p, *pr = NULL;
	p = s;
	while (p)
	{
		cnt++;
		if (cnt == pos)
			break;
		pr = p;
		p = p->next;
	}
	if (p == NULL)
		printf("Element not found in this position");
	else if (p == s) // first node will be deleted
	{
		s = s->next;
		if (s != NULL)
			s->prev = NULL;
		p->next = NULL;
	}
	else
	{
		pr->next = p->next;
		if (pr->next != NULL)
			pr->next->prev = pr;
	}
	free(p);
	return (s);
}

void disp(node *p)
{
	node *bk;
	while (p != NULL)
	{
		if (p->next == NULL)
			printf("%d,[%u]", p->info, p->next);
		else
			printf("%d,[%u]-->", p->info, p->next);
		bk = p;
		p = p->next;
	}
	p = bk;
	printf("\n");
	while (p != NULL)
	{
		if (p->prev == NULL)
			printf("%d,[%u]", p->info, p->prev);
		else
			printf("%d,[%u]-->", p->info, p->prev);
		p = p->prev;
	}
}

node *reverse(node *s)
{
	node *p, *r = NULL, *t;
	p = s;
	while (p)
	{
		t = p;
		p = p->next;
		t->next = r;
		if (r != NULL)
			t->next->prev = t;
		r = t;
	}
	r->prev = NULL;
	return (r);
}
void mdlNode(node *s)
{
	node *fp = s;
	node *sp = s;
	node *prev;
	if (s != NULL)
	{
		while (fp != NULL && fp->next != NULL)
		{
			fp = fp->next->next;
			prev = sp;
			sp = sp->next;
		}
		if (fp == NULL)
			printf("The middle element is %d and %d \n", prev->info, sp->info);
		else
			printf("The middle element is %d \n", sp->info);
	}
}
void nthNodetail(node *s, int n)
{
	node *rptr = s;
	node *ptr = s;
	int cnt = 0;
	if (s != NULL)
	{
		while (cnt < n)
		{
			if (ptr == NULL)
			{
				printf("%d is greater than the no. of nodes in list", n);
				return;
			}
			ptr = ptr->next;
			cnt++;
		}
		while (ptr != NULL)
		{
			rptr = rptr->next;
			ptr = ptr->next;
		}
		printf("Node no. %d from last is %d ", n, rptr->info);
	}
}
void nthNodetail1(node *s, int n)
{
	node *rptr = s;
	node *ptr = s;
	int cnt = 0;
	while (ptr != NULL)
	{
		if (cnt >= n)
			rptr = rptr->next;
		ptr = ptr->next;
		cnt++;
	}
	if (cnt < n)
		printf("%d is greater than the no. of nodes in list", n);
	else
		printf("Node no. %d from last is %d ", n, rptr->info);
}

int main()
{
	node *st, nd;
	int choice, dchoice, ps, val;
	// clrscr();
	do
	{
		system("cls");
		printf("\n----Main Menu----");
		printf("\n1:Create list");
		printf("\n2:Disp list");
		printf("\n3:Delete an element");
		printf("\n4:Insert an elelement");
		printf("\n5:Reverse");
		printf("\n6:Middle node");
		printf("\n7:nth node from tail");
		printf("\n8:Exit");
		printf("\nEnter you choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			st = create();
			break;
		case 2:
			disp(st);
			getch();
			break;
		case 3:
			system("cls");
			do
			{
				printf("\n--Delete Menu--");
				printf("\n1:Delete first");
				printf("\n2:Delete last");
				printf("\n3:Delete at a position");
				printf("\n4:Delete an element");
				printf("\n5:Exit");
				printf("\nEnter you choice:");
				scanf("%d", &dchoice);
				switch (dchoice)
				{
				case 1:
					st = delfirst(st);
					break;
				case 2:
					st = dellast(st);
					getch();
					break;
				case 3:
					printf("Enter node position to delete:");
					scanf("%d", &ps);
					st = delpos(st, ps);
					break;
				case 4:
					// st=delelem(st);
					break;
				case 5:
					printf("\n Leaving deletion");
					break;
				}
			} while (dchoice != 5);
			break;
		case 4:
			system("cls");
			do
			{
				printf("\n--Insert Menu--");
				printf("\n1:Insert at first");
				printf("\n2:Insert at last");
				printf("\n3:Insert at position");
				printf("\n4:Insert after an element");
				printf("\n5:Exit");
				printf("\nEnter you choice:");
				scanf("%d", &dchoice);
				switch (dchoice)
				{
				case 1:
					printf("Enter value to be inserted:");
					scanf("%d", &val);
					st = insfirst(st, val);
					break;
				case 2:
					printf("Enter value to be inserted:");
					scanf("%d", &val);
					st = inslast(st, val);
					getch();
					break;
				case 3:
					printf("Enter node position to insert:");
					scanf("%d", &ps);
					printf("Enter value to be inserted:");
					scanf("%d", &val);
					st = inspos(st, ps, val);
					break;
				case 4:
					//	st=delelem(st);
					break;
				case 5:
					printf("\n Leaving insertion");
					break;
				}
			} while (dchoice != 5);
			break;
		case 5:
			st = reverse(st);
			break;
		case 6:
			mdlNode(st);
			getch();
			break;
		case 7:
			// printf("Enter node position from trail:");
			// scanf("%d",&ps);
			// nthNodetail(st,ps);
			// nthNodetail1(st,ps);
			// isPallind(st);
			getch();
			break;
		case 8:
			printf("I am leaving");
			break;
		}
	} while (choice != 8);
	getch();
}
