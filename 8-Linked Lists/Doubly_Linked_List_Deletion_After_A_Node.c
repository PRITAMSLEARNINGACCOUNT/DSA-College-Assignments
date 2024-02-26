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
void Delete(struct Linked_List *Copy)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node = Copy->Next_Node;
    Copy->Next_Node = Copy->Next_Node->Next_Node;
    Copy->Next_Node->Prev_Node = Copy;
    free(Extra_Node);
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

    printf("Before Deletion\n");
    Traversal(Head);
    printf("After Deletion\n");
    // Please Don't Give The Last Node As It Isn't Connected To Any Another Node
    Delete(Third);
    Traversal(Head);
    return 0;
}