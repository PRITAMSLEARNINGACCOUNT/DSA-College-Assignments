#include <stdio.h>
#include <stdlib.h>
struct Linked_List
{
    int Data;
    struct Linked_List *Prev_Node;
    struct Linked_List *Next_Node;
};

void Traversal(struct Linked_List *Copy)
{
    while (Copy != NULL)
    {
        printf("%d\n", Copy->Data);
        Copy = Copy->Next_Node;
    }
}

void Reverse_Traversal(struct Linked_List *Head)
{
    while (Head != NULL)
    {
        printf("%d\n", Head->Data);
        // Copy = Copy->Next_Node;
        Head = Head->Prev_Node;
    }
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
    Head->Next_Node = First;
    Head->Prev_Node = NULL;
    First->Data = 20;
    First->Next_Node = Second;
    First->Prev_Node = Head;
    Second->Data = 900;
    Second->Next_Node = Third;
    Second->Prev_Node = First;
    Third->Data = 104;
    Third->Prev_Node = Second;
    Third->Next_Node = Fourth;
    Fourth->Data = 510;
    Fourth->Next_Node = Fifth;
    Fourth->Prev_Node = Third;
    Fifth->Data = 5401;
    Fifth->Next_Node = NULL;
    Fifth->Prev_Node = Fourth;
    printf("Forword Traversal\n");
    Traversal(Head);
    printf("Reverse Traversal\n");
    Reverse_Traversal(Fifth);
    return 0;
}