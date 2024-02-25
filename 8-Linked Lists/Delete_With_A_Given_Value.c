#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
int Delete_With_Value(struct Linked_List *Head_Pointer, int Value)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node = Head_Pointer;
    while (Extra_Node != NULL)
    {
        if (Extra_Node->Data == Value)
        {
            Head_Pointer->Node = Extra_Node->Node;
            // Head_Pointer->Node = NULL;
            free(Extra_Node);
            // break;
            return 0;
        }
        else
        {
            Head_Pointer = Extra_Node;
            Extra_Node = Extra_Node->Node;
        }
    }
    // printf("Hello World");
    return 2;
}
int main()
{
    int val = 900;
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
    printf("Enter A Value You Want To Be Deleted??\n");
    scanf("%d", &val);
    if (Head->Data == val)
    {
        Head = Head->Node;
        printf("After Deletion\n");
        Traversal(Head);
        return 0;
    }

    // printf("%d\n", Delete_With_Value(Head, val));
    if (Delete_With_Value(Head, val) == 0)
    {
        printf("After Deletion\n");
        Traversal(Head);
    }
    else
    {
        // printf("Hello");
        printf("The Value Is Not Founded In The Linked List.\n");
    }
    // Traversal(Head);
    return 0;
}