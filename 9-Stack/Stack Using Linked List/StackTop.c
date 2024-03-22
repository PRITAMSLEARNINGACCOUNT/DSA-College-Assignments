#include <stdio.h>
#include <stdlib.h>
struct Linked_List
{
    int Data;
    struct Linked_List *Node;
};

int IsFull()
{
    struct Linked_List *Temporary_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    if (Temporary_Node == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Linked_List *PUSH(struct Linked_List *Top_Copy, int Value)
{
    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    if (!IsFull())
    {
        Extra_Node->Data = Value;
        Extra_Node->Node = Top_Copy;
    }
    else
    {
        printf("Stack Overflows\n");
        return NULL;
    }

    return Extra_Node;
}
void StackTop(struct Linked_List *Copy)
{
    printf("The Top Most Element Of The Stack Is %d\n", Copy->Data);
}
void Traversal(struct Linked_List *Copy)
{
    while (Copy != NULL)
    {
        printf("%d\n", Copy->Data);
        Copy = Copy->Node;
    }
}
int main()
{
    struct Linked_List *Top;
    Top = NULL;
    Top = PUSH(Top, 10);
    Top = PUSH(Top, 100);
    Top = PUSH(Top, 11);
    StackTop(Top);
    // Traversal(Top);
    return 0;
}