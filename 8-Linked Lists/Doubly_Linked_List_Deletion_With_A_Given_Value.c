#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
int Delete_With_Value(struct Linked_List *Head_Pointer, int Value)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node = Head_Pointer;
    while (Extra_Node != NULL)
    {
        if (Extra_Node->Data == Value)
        {
            Head_Pointer->Next_Node = Extra_Node->Next_Node;
            Extra_Node->Next_Node->Prev_Node = Head_Pointer;
            free(Extra_Node);
            return 0;
        }
        else
        {
            Head_Pointer = Extra_Node;
            Extra_Node = Extra_Node->Next_Node;
        }
    }
    // printf("Hello World");
    return 2;
}

void Delete_At_End(struct Linked_List *Head_Pointer)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node = Head_Pointer;
    while (true)
    {
        if (Extra_Node->Next_Node == NULL)
        {
            Head_Pointer->Next_Node = NULL;
            free(Extra_Node);
            break;
        }
        else
        {
            Head_Pointer = Extra_Node;
            Extra_Node = Extra_Node->Next_Node;
        }
    }
}
int main()
{
    int val = 0;
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

    printf("Enter A Value You Want To Be Deleted??\n");
    scanf("%d", &val);
    if (Head->Data == val)
    {
        Head = Head->Next_Node;
        Head->Next_Node->Prev_Node = NULL;
        printf("After Deletion\n");
        Traversal(Head);
        return 0;
    }
    if (Fifth->Data == val)
    {
        Delete_At_End(Head);
        Traversal(Head);
        return 0;
    }

    if (Delete_With_Value(Head, val) == 0)
    {
        printf("After Deletion\n");
        Traversal(Head);
    }
    else
    {
        printf("The Value Is Not Founded In The Linked List.\n");
    }
    // printf("After Deletion\n");
    // Traversal(Head);
    return 0;
}
