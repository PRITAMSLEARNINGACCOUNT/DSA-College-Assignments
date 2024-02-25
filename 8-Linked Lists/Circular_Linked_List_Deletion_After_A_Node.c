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
    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node = Copy;
    do
    {
        printf("%d\n", Copy->Data);
        Copy = Copy->Node;
    } while (Extra_Node != Copy);
}

int Delete_With_Value(struct Linked_List *Head_Pointer, int Value)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node = Head_Pointer;
    struct Linked_List *Extra_Node_2 = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node_2 = Head_Pointer;

    do
    {
        if (Extra_Node->Data == Value)
        {
            Head_Pointer->Node = Extra_Node->Node;
            free(Extra_Node);
            return 0;
        }
        else
        {
            Head_Pointer = Extra_Node;
            Extra_Node = Extra_Node->Node;
        }
    } while (Extra_Node != Extra_Node_2);
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
    Fifth->Node = Head;
    printf("Before Deletion\n");
    Traversal(Head);
    printf("Enter A Value You Want To Be Deleted??\n");
    scanf("%d", &val);
    if (Head->Data == val)
    {
        Head = Head->Node;
        Fifth->Node = Head;
        printf("After Deletion\n");
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
    return 0;
}