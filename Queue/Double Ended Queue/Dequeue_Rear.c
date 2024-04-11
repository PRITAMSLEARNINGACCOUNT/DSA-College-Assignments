#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Queue
{
    int size;
    int *array;
    int Front_Index;
    int Rear_Index;
};
bool IsEmpty(struct Queue *ptr)
{
    if (ptr->Front_Index == ptr->Rear_Index || ptr->Rear_Index == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Dequeue(struct Queue *Pointer)
{
    if (IsEmpty(Pointer))
    {
        printf("The Queue Is Already Empty\n");
    }
    else
    {
        int val = Pointer->array[Pointer->Rear_Index];
        Pointer->Rear_Index--;
        return val;
    }
}
int main()
{
    struct Queue *Q1 = (struct Queue *)malloc(sizeof(struct Queue));
    Q1->size = 1;
    Q1->Front_Index = -1;
    Q1->Rear_Index = -1;
    Q1->array = (int *)malloc(Q1->size * (sizeof(int)));
    IsEmpty(Q1);

    return 0;
}