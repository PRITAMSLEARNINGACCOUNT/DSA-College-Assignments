#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Queue
{
    int Data;
    struct Queue *Node;
};
void Traversal(struct Queue *Copy)
{
    while (Copy != NULL)
    {
        printf("%d\n", Copy->Data);
        Copy = Copy->Node;
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
        Element->Node = NULL;
        (*Front) = (*Rear) = Element;
    }
    else
    {
        struct Queue *Element = (struct Queue *)malloc(sizeof(struct Queue));
        Element->Data = Value;
        Element->Node = NULL;
        (*Rear)->Node = Element;
        (*Rear) = Element;
    }
}
bool IsNull(struct Queue *Front, struct Queue *Rear)
{

    if (Front == NULL)
    {
        return true;
    }
    return false;
}
int Dequeue(struct Queue **Front, struct Queue **Rear)
{
    int Value = -1;
    if (IsNull((*Front), (*Rear)))
    {
        printf("The Queue Is Empty\n");
    }
    else
    {
        struct Queue *Free_Pointer = (struct Queue *)malloc(sizeof(struct Queue));
        Free_Pointer = *Front;
        Value = (*Front)->Data;
        (*Front) = (*Front)->Node;
        free(Free_Pointer);
    }
    return Value;
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
    Dequeue(&Front_Index, &Rear_Index);
    Dequeue(&Front_Index, &Rear_Index);
    Dequeue(&Front_Index, &Rear_Index);
    Traversal(Front_Index);
    return 0;
}