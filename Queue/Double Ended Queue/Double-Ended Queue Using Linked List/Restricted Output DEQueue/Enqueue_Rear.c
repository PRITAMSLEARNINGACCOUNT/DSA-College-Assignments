#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
c
void Traversal(struct Queue *Copy)
{
    while (Copy != NULL)
    {
        printf("%d\n", Copy->Data);
        Copy = Copy->Next_Node;
    }
}
bool IsFull()
{
    struct Queue *Node = (struct Queue *)malloc(sizeof(struct Queue));
    if (Node == NULL)
    {
        return true;
    }
    return false;
}
void Enqueue(struct Queue **Front, struct Queue **Rear, int Value)
{
    if (IsFull())
    {
        printf("The Queue Is Full\n");
    }
    else if ((*Front) == NULL && (*Rear) == NULL)
    {
        struct Queue *Element = (struct Queue *)malloc(sizeof(struct Queue));
        Element->Data = Value;
        Element->Next_Node = NULL;
        Element->Previous_Node = NULL;
        (*Front) = (*Rear) = Element;
    }
    else
    {
        struct Queue *Element = (struct Queue *)malloc(sizeof(struct Queue));
        Element->Data = Value;
        Element->Next_Node = NULL;
        Element->Previous_Node = (*Rear);
        (*Rear)->Next_Node = Element;
        (*Rear) = Element;
    }
}
int main()
{
    struct Queue *Front_Index = (struct Queue *)malloc(sizeof(struct Queue));
    struct Queue *Rear_Index = (struct Queue *)malloc(sizeof(struct Queue));
    Front_Index = NULL;
    Rear_Index = NULL;
    Enqueue(&Front_Index, &Rear_Index, 200);
    Enqueue(&Front_Index, &Rear_Index, 56470);
    Traversal(Front_Index);
    return 0;
}