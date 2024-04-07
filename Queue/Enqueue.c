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

bool IsFull(struct Queue *Copy)
{
    if (Copy->Rear_Index == Copy->size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Enqueue(struct Queue *ptr, int Insert_Value)
{
    if (IsFull(ptr))
    {
        printf("The Queue Is Full\n");
    }
    else
    {
        ptr->Rear_Index++;
        ptr->array[ptr->Rear_Index] = Insert_Value;
    }
}
int main()
{
    struct Queue *Q1 = (struct Queue *)malloc(sizeof(struct Queue));
    Q1->size = 20;
    Q1->Front_Index = -1;
    Q1->Rear_Index = -1;
    Q1->array = (int *)malloc(Q1->size * (sizeof(int)));
    Enqueue(Q1, 20);
    Enqueue(Q1, 200);
    return 0;
}