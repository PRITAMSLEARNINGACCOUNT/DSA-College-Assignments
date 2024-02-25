#include <stdio.h>
#include <stdlib.h>
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
void Delete_At_Index(struct Linked_List *Head_Pointer, int index)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node = Head_Pointer;
    struct Linked_List *Extra_Node_2 = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node_2 = Head_Pointer;
    int i = 0;
    do
    {
        if (i == index)
        {
            Head_Pointer->Node = Extra_Node->Node;
            free(Extra_Node);
            break;
        }
        else
        {
            Head_Pointer = Extra_Node;
            Extra_Node = Extra_Node->Node;
        }
        i++;
    } while (Extra_Node != Extra_Node_2);
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
    Fifth->Node = Head;
    printf("Before Deletion\n");
    Traversal(Head);
    printf("Enter The Position You Want To Delete??\n");
    scanf("%d", &Position);
    if ((Position - 1) < 0 || (Position - 1) > 6)
    {

        printf("Deletion Failed Because Of Invalid Index\n");
        return 0;
    }

    if ((Position - 1) == 0)
    {
        printf("After Deletion\n");
        Head = Head->Node;
        Fifth->Node = Head;
        Traversal(First);
    }
    else
    {

        printf("After Deletion\n");
        Delete_At_Index(Head, Position - 1);
        Traversal(Head);
    }

    return 0;
}