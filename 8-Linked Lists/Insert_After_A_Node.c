#include <stdio.h>
#include <stdlib.h>
struct Linked_List
{
    int Data;
    struct Linked_List *Node;
};
void Traversal(struct Linked_List *Copy)
{
    while (Copy != NULL)
    {
        printf("%d\n", Copy->Data);
        Copy = Copy->Node;
    }
}

void Insert(struct Linked_List *Copy, int data)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node->Data = data;
    Extra_Node->Node = Copy->Node;
    Copy->Node = Extra_Node;
    // Traversal(Copy);
}
int main()
{
    struct Linked_List *Head = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    struct Linked_List *First = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    struct Linked_List *Second = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    struct Linked_List *Third = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    struct Linked_List *Fourth = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    struct Linked_List *Fifth = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Head->Data = 90;
    Head->Node = First;
    First->Data = 20;
    First->Node = Second;
    Second->Data = 900;
    Second->Node = Third;
    Third->Data = 104;
    Third->Node = Fourth;
    Fourth->Data = 510;
    Fourth->Node = Fifth;
    Fifth->Data = 5401;
    Fifth->Node = NULL;

    printf("Before Insertion\n");
    Traversal(Head);
    Insert(Second, 20);
    printf("After Insertion\n");
    Traversal(Head);

    return 0;
}