/*
Note:An Address Of Any Type Of Data Can not be Changed Without Being Pointer
The Above Line Means We Just Can's Change Address Of An Already Declared Data.
&Data=Address_Of_Data---->This Can Not Be Done.
In Order To Do Something I Wanted In The Above Line Can Be Done By Doing Something Like Below:-
Data_Type *Data;
Data=Address_Of_Data;
*/
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
void Delete_At_Index(struct Linked_List *Head_Pointer, int index)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node = Head_Pointer;
    int i = 0;
    // int count = 0;
    while (Head_Pointer != NULL)
    {
        // printf("HUE HUE HUE\n");
        if (i == index)
        {
            // printf("Hello World\n");
            // printf("Hello World\n");
            // Extra_Node->Node = Head_Pointer->Node;
            // Head_Pointer->Node = Extra_Node;
            // count++;
            Head_Pointer->Node = Extra_Node->Node;
            free(Extra_Node);
            break;
        }
        else
        {
            // printf("Hello World\n");
            Head_Pointer = Extra_Node;
            // printf("%d\n", Head_Pointer->Data);
            Extra_Node = Extra_Node->Node;
        }
        i++;
    }
    // if (count != 0)
    // {
    // }

    // struct Linked_List Extra_Node;
    // Extra_Node.Data = data;
    // Extra_Node->Node = Copy->Node;
    // Extra_Node.Node = Copy->Node;
    // Copy->Node = Extra_Node;

    // Traversal(Copy);
}
int main()
{
    int Position;
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
    printf("Before Deletion\n");
    Traversal(Head);
    // printf("Enter The Position You Want To Delete??\n");
    // scanf("%d", &Position);
    Position = 3;
    if ((Position - 1) < 0 || (Position - 1) > 6)
    {

        printf("Deletion Failed Because Of Invalid Index\n");
        return 0;
    }

    if ((Position - 1) == 0)
    {
        printf("After Deletion\n");
        // Head = Case_1(Head, 5144);
        // Traversal(Head);
        free(Head);
        Traversal(First);
    }
    else
    {

        printf("After Deletion\n");
        Delete_At_Index(Head, Position - 1);
        Traversal(Head);
        // Case_2(Head, 507, index - 1);
        // Traversal(Head);
    }
    // printf("After Deletion\n");
    // Traversal(Head);
    return 0;
}