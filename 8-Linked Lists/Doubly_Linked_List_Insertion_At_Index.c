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

struct Linked_List *Case_1(struct Linked_List *Copy, int data)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node->Data = data;
    Extra_Node->Next_Node = Copy;
    Extra_Node->Prev_Node = NULL;
    Copy->Prev_Node = Extra_Node;
    return Extra_Node;
}
void Case_2(struct Linked_List *Head_Pointer, int data, int index)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node->Data = data;
    int i = 1;
    while (Head_Pointer != NULL)
    {
        if (i == index)
        {
            Extra_Node->Next_Node = Head_Pointer->Next_Node;
            Head_Pointer->Next_Node->Prev_Node=Extra_Node;
            Extra_Node->Prev_Node=Head_Pointer;
            Head_Pointer->Next_Node = Extra_Node;
            break;
        }
        else
        {
            Head_Pointer = Head_Pointer->Next_Node;
        }
        i++;
    }
}
int main()
{
    int index = 0;
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
    printf("Enter On Which Position Do You Want To Enter A Node?\n");
    scanf("%d", &index);
    if ((index - 1) < 0 || (index - 1) > 6)
    {

        printf("Insertion Failed Because Of Invalid Index\n");
        return 0;
    }

    if ((index - 1) == 0)
    {
        printf("After Insertion\n");
        Head = Case_1(Head, 5144);
        Traversal(Head);
    }
    else
    {

        printf("After Insertion\n");
        Case_2(Head, 507, index - 1);
        Traversal(Head);
    }

    return 0;
}