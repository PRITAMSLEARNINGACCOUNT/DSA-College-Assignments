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
struct Linked_List *Case_1(struct Linked_List *Copy, int data)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node->Data = data;
    // struct Linked_List *Temp_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    // struct Linked_List Temp_Head = *Copy;
    // Temp_Node = Copy;
    Extra_Node->Node = Copy;
    // Traversal(Extra_Node);
    // Copy = Extra_Node;
    // return Extra_Node;
    return Extra_Node;
}
void Case_2(struct Linked_List *Head_Pointer, int data, int index)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node->Data = data;
    int i = 1;
    // int count = 0;
    while (Head_Pointer != NULL)
    {
        // printf("HUE HUE HUE\n");
        if (i == index)
        {
            printf("Hello World\n");
            Extra_Node->Node = Head_Pointer->Node;
            Head_Pointer->Node = Extra_Node;
            // count++;
            break;
        }
        else
        {
            Head_Pointer = Head_Pointer->Node;
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
    int index = 0;
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

    printf("Enter On Which Index Do You Want To Enter A Node?\n");
    scanf("%d", &index);
    if (index < 0 || index > 6)
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