#include <stdio.h>
#include <stdlib.h>
struct Linked_List
{
    int Data;
    struct Linked_List *Next_Node;
    struct Linked_List *Prev_Node;
};

void Traversal(struct Linked_List *Copy)
{
    while (Copy != NULL)
    {
        printf("%d\n", Copy->Data);
        Copy = Copy->Next_Node;
    }
}
void Insert(struct Linked_List *Copy, int data)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node->Data = data;
    Extra_Node->Next_Node = Copy->Next_Node;
    Extra_Node->Prev_Node = Copy;
    if (Copy->Next_Node != NULL)
    {
        Copy->Next_Node->Prev_Node = Extra_Node;
    }
    Copy->Next_Node = Extra_Node;
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
    Head->Prev_Node = NULL;
    Head->Next_Node = First;
    First->Data = 20;
    First->Prev_Node = Head;
    First->Next_Node = Second;
    Second->Data = 900;
    Second->Prev_Node = First;
    Second->Next_Node = Third;
    Third->Data = 104;
    Third->Prev_Node = Second;
    Third->Next_Node = Fourth;
    Fourth->Data = 510;
    Fourth->Prev_Node = Third;
    Fourth->Next_Node = Fifth;
    Fifth->Data = 5401;
    Fifth->Prev_Node = Fourth;
    Fifth->Next_Node = NULL;

    printf("Before Insertion\n");
    Traversal(Head);
    printf("After Insertion\n");
    Insert(Fifth, 587);
    Traversal(Head);
    return 0;
}