#include <stdio.h>
#include <stdlib.h>
struct Linked_List
{
    int Data;
    struct Linked_List *Node;
};
int IsNull(struct Linked_List *Top)
{
    if (Top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
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
int POP(struct Linked_List **Top)
{
    if (IsNull(*Top))
    {
        printf("Stack Underflows\n");
        return 0;
    }
    else
    {
        // printf("Hello World\n");
        struct Linked_List *Removal_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
        Removal_Node = *Top;
        int Removal_Value = Removal_Node->Data;
        free(Removal_Node);
        *Top = (*Top)->Node;
        return Removal_Value;
    }
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
    printf("Before Popping Element\n");
    Traversal(Top);
    printf("So The Popped Element Is %d\n", POP(&Top));
    printf("After Popping Element\n");
    Traversal(Top);
    return 0;
}