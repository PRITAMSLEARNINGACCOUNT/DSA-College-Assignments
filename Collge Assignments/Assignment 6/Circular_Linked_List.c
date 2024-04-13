#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} node;

node *createcircularlinklist(node *);
node *createnode();
node *insertbegin(node *);
node *deletebegin(node *);
void display(node *);

int main()
{
	int option, loop;
	node *tail = NULL;
	printf("\n CREATING CIRCULAR LINK LIST---- :\n");
	tail = createcircularlinklist(tail);
	do
	{
		printf("\n 1.INSERT\n");
		printf("\n 2.DELETE\n");
		printf("\n 3.DISPLAY\n");
		printf("\n 4.EXIT\n");

		printf("\n ENTER YOUR OPTION :\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("\n INSERT \n");
			tail = insertbegin(tail);
			loop = 1;
			break;
		case 2:
			printf("\n DELETE\n");
			tail = deletebegin(tail);
			loop = 1;
			break;
		case 3:
			printf("\n DISPLAY\n");
			display(tail);
			loop = 1;
			break;
		case 4:
			printf("\n EXIT\n");
			loop = 0;
			break;
		default:
			printf("\n YOU HAVE ENTERED WRONG OPTION.\n");
			loop = 1;
		}
	} while (loop);
}
node *createnode()
{
	node *temp = (node *)malloc(sizeof(node));
	temp->next = temp;
	return temp;
}

node *createcircularlinklist(node *tail)
{
	int i, n;
	printf("\n NEW NODES ARE INSERTED AT BEGINING--\n");
	printf("\n HOW MANY NODES?\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		tail = insertbegin(tail);
	}
	return tail;
}

node *insertbegin(node *tail)
{
	node *newnode = createnode();
	if (newnode == NULL)
	{
		printf("\nCAN'T CREATE A NODE FOR FULL MEMORY.\n");
	}
	else
	{
		printf("\nENTER THE DATA TO BE INSERTED AT BEGINING:\n ");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		if (tail == NULL)
		{
			tail = newnode;
			tail->next = newnode;
		}
		else
		{
			newnode->next = tail->next;
			tail->next = newnode;
		}
		display(tail);
		return tail;
	}
}

node *deletebegin(node *tail)
{
	node *ptr;
	if (tail == NULL)
	{
		printf("\n NOTHING TO DELETE.\n");
	}
	else
	{
		ptr = tail->next;
		if (ptr->next == ptr)
		{
			tail = NULL;
			free(ptr);
		}
		else
		{
			tail->next = ptr->next;
			free(ptr);
		}
	}
	display(tail);
	return (tail);
}

void display(node *temp)
{
	node *p;
	printf("\nTHE LINKEDLIST IS ->\n");
	if (temp == NULL)
	{
		printf("\n EMPTY LINKLIST.\n");
	}
	else
	{
		p = temp->next;
		while (p != temp)
		{
			printf("[%d]->", p->data);
			p = p->next;
		}
		printf("[%d]", p->data);
	}
	printf("\n");
	printf("\n ____\n");
}
