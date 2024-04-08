#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int *array;
    int Front_Index;
    int Rear_Index;
};
void IsFull(struct Queue *Copy)
{
    if (((Copy->Rear_Index + 1) % Copy->size) == Copy->Front_Index)
    {
        printf("Queue Is Full\n");
    }
    else
    {
        printf("Queue Is Not Full\n");
    }
}
int main()
{
    struct Queue *Q1 = (struct Queue *)malloc(sizeof(struct Queue));
    Q1->size = 3;
    Q1->Front_Index = 0;
    Q1->Rear_Index = 0;
    Q1->array = (int *)malloc(Q1->size * (sizeof(int)));
    Q1->Rear_Index = ((Q1->Rear_Index + 1) % Q1->size);
    Q1->array[Q1->Rear_Index] = 20;
    IsFull(Q1);
    return 0;
}