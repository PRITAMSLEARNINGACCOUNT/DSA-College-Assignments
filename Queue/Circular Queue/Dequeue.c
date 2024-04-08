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
    if (ptr->Front_Index == ptr->Rear_Index)
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
        return -1;
    }
    else
    {
        Pointer->Front_Index = (Pointer->Front_Index + 1) % Pointer->size;
        return Pointer->array[Pointer->Front_Index];
    }
}
int main()
{
    struct Queue *Q1 = (struct Queue *)malloc(sizeof(struct Queue));
    Q1->size = 20;
    Q1->Front_Index = 0;
    Q1->Rear_Index = 0;
    Q1->array = (int *)malloc(Q1->size * (sizeof(int)));
    Q1->Rear_Index = ((Q1->Rear_Index + 1) % Q1->size);
    Q1->array[Q1->Rear_Index] = 20;
    printf("%d\n", Dequeue(Q1));
    printf("%d\n", Dequeue(Q1));
    return 0;
}